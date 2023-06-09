/*
 * @Author: Wulnut carepdime@gmail.com
 * @Date: 2023-03-09 17:14:02
 * @LastEditors: Wulnut carepdime@gmail.com
 * @LastEditTime: 2023-03-13 10:53:18
 * @FilePath: /task/Interface.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * This file is generated by gdbus-codegen, do not modify it.
 *
 * The license of this code is the same as for the D-Bus interface description
 * it was derived from. Note that it links to GLib, so must comply with the
 * LGPL linking clauses.
 */

#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for com.upointech.dbus.ObjectManager */

#define INTERFACE_TYPE_OBJECT_MANAGER (interface_object_manager_get_type ())
#define INTERFACE_OBJECT_MANAGER(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), INTERFACE_TYPE_OBJECT_MANAGER, interfaceObjectManager))
#define INTERFACE_IS_OBJECT_MANAGER(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), INTERFACE_TYPE_OBJECT_MANAGER))
#define INTERFACE_OBJECT_MANAGER_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), INTERFACE_TYPE_OBJECT_MANAGER, interfaceObjectManagerIface))

struct _interfaceObjectManager;
typedef struct _interfaceObjectManager interfaceObjectManager;
typedef struct _interfaceObjectManagerIface interfaceObjectManagerIface;

struct _interfaceObjectManagerIface
{
  GTypeInterface parent_iface;


  gboolean (*handle_add_object) (
    interfaceObjectManager *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_delete_object) (
    interfaceObjectManager *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_objpath_in);

  gboolean (*handle_get_managed_objects) (
    interfaceObjectManager *object,
    GDBusMethodInvocation *invocation);

  void (*interfaces_added) (
    interfaceObjectManager *object,
    const gchar *arg_object_path);

  void (*interfaces_removed) (
    interfaceObjectManager *object,
    const gchar *arg_object_path);

};

GType interface_object_manager_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *interface_object_manager_interface_info (void);
guint interface_object_manager_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void interface_object_manager_complete_add_object (
    interfaceObjectManager *object,
    GDBusMethodInvocation *invocation,
    const gchar *objpath_out);

void interface_object_manager_complete_delete_object (
    interfaceObjectManager *object,
    GDBusMethodInvocation *invocation,
    const gchar *objpath_out);

void interface_object_manager_complete_get_managed_objects (
    interfaceObjectManager *object,
    GDBusMethodInvocation *invocation,
    const gchar *const *object_paths_interfaces_and_properties);



/* D-Bus signal emissions functions: */
void interface_object_manager_emit_interfaces_added (
    interfaceObjectManager *object,
    const gchar *arg_object_path);

void interface_object_manager_emit_interfaces_removed (
    interfaceObjectManager *object,
    const gchar *arg_object_path);



/* D-Bus method calls: */
void interface_object_manager_call_add_object (
    interfaceObjectManager *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean interface_object_manager_call_add_object_finish (
    interfaceObjectManager *proxy,
    gchar **out_objpath_out,
    GAsyncResult *res,
    GError **error);

gboolean interface_object_manager_call_add_object_sync (
    interfaceObjectManager *proxy,
    gchar **out_objpath_out,
    GCancellable *cancellable,
    GError **error);

void interface_object_manager_call_delete_object (
    interfaceObjectManager *proxy,
    const gchar *arg_objpath_in,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean interface_object_manager_call_delete_object_finish (
    interfaceObjectManager *proxy,
    gchar **out_objpath_out,
    GAsyncResult *res,
    GError **error);

gboolean interface_object_manager_call_delete_object_sync (
    interfaceObjectManager *proxy,
    const gchar *arg_objpath_in,
    gchar **out_objpath_out,
    GCancellable *cancellable,
    GError **error);

void interface_object_manager_call_get_managed_objects (
    interfaceObjectManager *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean interface_object_manager_call_get_managed_objects_finish (
    interfaceObjectManager *proxy,
    gchar ***out_object_paths_interfaces_and_properties,
    GAsyncResult *res,
    GError **error);

gboolean interface_object_manager_call_get_managed_objects_sync (
    interfaceObjectManager *proxy,
    gchar ***out_object_paths_interfaces_and_properties,
    GCancellable *cancellable,
    GError **error);



/* ---- */

#define INTERFACE_TYPE_OBJECT_MANAGER_PROXY (interface_object_manager_proxy_get_type ())
#define INTERFACE_OBJECT_MANAGER_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), INTERFACE_TYPE_OBJECT_MANAGER_PROXY, interfaceObjectManagerProxy))
#define INTERFACE_OBJECT_MANAGER_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), INTERFACE_TYPE_OBJECT_MANAGER_PROXY, interfaceObjectManagerProxyClass))
#define INTERFACE_OBJECT_MANAGER_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), INTERFACE_TYPE_OBJECT_MANAGER_PROXY, interfaceObjectManagerProxyClass))
#define INTERFACE_IS_OBJECT_MANAGER_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), INTERFACE_TYPE_OBJECT_MANAGER_PROXY))
#define INTERFACE_IS_OBJECT_MANAGER_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), INTERFACE_TYPE_OBJECT_MANAGER_PROXY))

typedef struct _interfaceObjectManagerProxy interfaceObjectManagerProxy;
typedef struct _interfaceObjectManagerProxyClass interfaceObjectManagerProxyClass;
typedef struct _interfaceObjectManagerProxyPrivate interfaceObjectManagerProxyPrivate;

struct _interfaceObjectManagerProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  interfaceObjectManagerProxyPrivate *priv;
};

struct _interfaceObjectManagerProxyClass
{
  GDBusProxyClass parent_class;
};

GType interface_object_manager_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (interfaceObjectManagerProxy, g_object_unref)
#endif

void interface_object_manager_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
interfaceObjectManager *interface_object_manager_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
interfaceObjectManager *interface_object_manager_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void interface_object_manager_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
interfaceObjectManager *interface_object_manager_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
interfaceObjectManager *interface_object_manager_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define INTERFACE_TYPE_OBJECT_MANAGER_SKELETON (interface_object_manager_skeleton_get_type ())
#define INTERFACE_OBJECT_MANAGER_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), INTERFACE_TYPE_OBJECT_MANAGER_SKELETON, interfaceObjectManagerSkeleton))
#define INTERFACE_OBJECT_MANAGER_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), INTERFACE_TYPE_OBJECT_MANAGER_SKELETON, interfaceObjectManagerSkeletonClass))
#define INTERFACE_OBJECT_MANAGER_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), INTERFACE_TYPE_OBJECT_MANAGER_SKELETON, interfaceObjectManagerSkeletonClass))
#define INTERFACE_IS_OBJECT_MANAGER_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), INTERFACE_TYPE_OBJECT_MANAGER_SKELETON))
#define INTERFACE_IS_OBJECT_MANAGER_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), INTERFACE_TYPE_OBJECT_MANAGER_SKELETON))

typedef struct _interfaceObjectManagerSkeleton interfaceObjectManagerSkeleton;
typedef struct _interfaceObjectManagerSkeletonClass interfaceObjectManagerSkeletonClass;
typedef struct _interfaceObjectManagerSkeletonPrivate interfaceObjectManagerSkeletonPrivate;

struct _interfaceObjectManagerSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  interfaceObjectManagerSkeletonPrivate *priv;
};

struct _interfaceObjectManagerSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType interface_object_manager_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (interfaceObjectManagerSkeleton, g_object_unref)
#endif

interfaceObjectManager *interface_object_manager_skeleton_new (void);


G_END_DECLS

#endif /* __INTERFACE_H__ */
