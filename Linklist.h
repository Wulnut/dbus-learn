
#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode {
    char *str;
    struct ListNode *next;
} ListNode;

// 创建链表
ListNode* create_node(char *data);

// 添加新节点到链表尾部
void append_node(ListNode** head, char *data);

// 在链表指定位置插入新节点
void insert_node(ListNode** head, char *data, int position);

// 删除指定位置的节点
int delete_node(ListNode** head, int data);

// 获取链表长度
int get_length(ListNode* head);

//打印链表
void print_list(ListNode* head);

//释放链表内存
void free_list(ListNode** head);

#endif /*__LINKLIST_H*/