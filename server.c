#define _GNU_SOURCE

#include <gio/gio.h>
#include <stdio.h>
#include <string.h>

#include "Interface.h"
#include "Linklist.h"

#define MAXSIZE 256

ListNode *list;
static interfaceObjectManager *skeleton = NULL;
static int gchar_status = 1;

// typedef struct {
//   int status;  // 状态码
//   char *str;
// } DataType;
// static DataType hash_table[MAXSIZE];



// InterfaceAdded 信号实现
static gboolean emit_interface_added_status_signal(gchar *object_path) {
  printf("emit_interface_added_status_signal invoked\n");

  if (skeleton != NULL) {
    interface_object_manager_emit_interfaces_added(skeleton, object_path);
  }

  return TRUE;
}

// AddObject方法处理函数实现
static gboolean on_handle_add_object(interfaceObjectManager *skeleton,
                                     GDBusMethodInvocation *invocation) {
  // 创建新的对象路径
  gchar *object_path = NULL;
  //  为什么不适用strcpy和strcat，因为多段字符串进行拼接的时候存在重复运算
  asprintf(&object_path, "/com/upointech/dbus/Test/%d", gchar_status);  // 最求性能可以使用memcpy或者手写
  // hash_table[gchar_status - 1].str = strdup(object_path);  // strdup是什么意思 可以在使用完空间后进行释放
  // hash_table[gchar_status - 1].status = 1;  // 修改状态值
  append_node(&list, object_path);
  // print_list(list);
  printf("\"%s\" string \"AddObject\"\n", object_path);
  // 绑定到相应接口
  interface_object_manager_complete_add_object(skeleton, invocation, object_path);
  emit_interface_added_status_signal(object_path);

  gchar_status ++;
  return TRUE;
}

// InterfacesRemoved 信号实现
static gboolean emit_interface_removed_status_signal(const gchar *object_path) {
  printf("emit_interface_removed_status_signal invoked\n");

  if (skeleton != NULL) {
    interface_object_manager_emit_interfaces_removed(skeleton, object_path);
  }

  return TRUE;
}

// DeleteObject方法实现
static gboolean on_handle_delete_object(interfaceObjectManager *skeleton,
                                        GDBusMethodInvocation *invocation,
                                        const gchar *str) {
  
  // if (*(str + (strlen(str) - 1)) - '0' < gchar_status &&
  //     hash_table[*(str + (strlen(str) - 1)) - '1'].status == 1) {  // 如果存在就删除

  //   hash_table[*(str + (strlen(str) - 1)) - '1'].status = 0;

  //   printf("object path %s has been deleted\n", hash_table[*(str + (strlen(str) - 1)) - '1'].str);

  // } else {  // 如果不存在就打印
    
  //   printf("object path %s does not exist\n", str);
  // }
  if (delete_node(&list, *(str + (strlen(str) - 1)) - '0')) {
    printf("object path %s has been deleted\n", str); 
  } else {
    printf("object path %s does not exist\n", str);
  }
  print_list(list);
  // 绑定相应接口
  interface_object_manager_complete_delete_object(skeleton, invocation, str);

  // 发送信号
  emit_interface_removed_status_signal(str);


  return TRUE;
}

// GetManageObject方法实现
static gboolean on_handle_get_managed_objects(
    interfaceObjectManager *skeleton, GDBusMethodInvocation *invocation) {
  // 循环序列化
  ListNode *node = list;
  int i = 0;
  char *ret[MAXSIZE] = {NULL}; // 需要初始化

  // for (int i = 0; i < gchar_status - 1; ++ i) {
    
  //   if (hash_table[i].status == 1) {

  //     *(ret + i) = hash_table[i].str;

  //   }
  // }
  while (node != NULL) {
    *(ret + i) = node->str;
    ++ i;
    node = node->next;
  }

  // 绑定相应接口
  interface_object_manager_complete_get_managed_objects(
      skeleton, invocation, (const gchar *const *)ret);
  return TRUE;
}

// dbus总线进行注册
void on_bus_acquired(GDBusConnection *connection, const gchar *name,
                     gpointer user_data) {
  // 在总线上被捕获
  printf("on_bus_acquired has been invoked, name, is %s\n", name);
  GError *error = NULL;
  skeleton = interface_object_manager_skeleton_new();
  // 绑定信号连接 "handle-add-object"
  g_signal_connect(skeleton, "handle-add-object",
                   G_CALLBACK(on_handle_add_object), NULL);
  // 绑定信号连接 “handle-deleted-object”
  g_signal_connect(skeleton, "handle-delete-object",
                   G_CALLBACK(on_handle_delete_object), NULL);
  // 绑定信号连接"handle-get-managed-object"
  g_signal_connect(skeleton, "handle-get-managed-objects",
                   G_CALLBACK(on_handle_get_managed_objects), NULL);
  //  发布到总线上
  g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(skeleton),
                                   connection, "/com/upointech/dbus/Test",
                                   &error);
  // 判断是否出现错误
  if (error != NULL) {
    printf("Error: Failed to export object. Reason: %s.\n", error->message);
    g_error_free(error);
  }
}

// 注册busname的回调

void on_bus_name_acquired(GDBusConnection *connection, const gchar *name,
                          gpointer user_date) {
  printf("on_bus_name_acquired has been invoked\n");
}

// 判断busname是否丢失回调
void on_bus_name_lost(GDBusConnection *connection, const gchar *name,
                      gpointer user_data) {
  printf("on_bus_name_lost!!!\n");
}

int main(int argc, char const *argv[]) {
  // 初始化
  guint owner_id;   // 设置bus_name
  GMainLoop *loop;  // 设置gloop

#if !GLIB_CHECK_VERSION(2, 35, 0)
  g_type_init();
#endif

  owner_id = g_bus_own_name(G_BUS_TYPE_SESSION, "com.upointech.dbus",
                            G_BUS_NAME_OWNER_FLAGS_NONE, on_bus_acquired,
                            on_bus_name_acquired, on_bus_name_lost, NULL, NULL);

  loop = g_main_loop_new(NULL, FALSE);
  g_main_loop_run(loop);

  g_bus_unown_name(owner_id);
  return 0;
}
