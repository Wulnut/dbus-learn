/*
 * @Author: Wulnut carepdime@gmail.com
 * @Date: 2023-03-13 11:01:03
 * @LastEditors: Wulnut carepdime@gmail.com
 * @LastEditTime: 2023-03-14 17:01:57
 * @FilePath: /task/Linklist.c
 * @Description:
 */

#include "Linklist.h"
#include <string.h>

ListNode* create_node(char *data) {
    ListNode *node = (ListNode*) malloc(sizeof (ListNode));
    node->str = data;
    node->next = NULL;
    return node;
} 

// 添加新节点
void append_node(ListNode **head, char *data) {
    ListNode *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        ListNode *current = *head;
        // 找到最后一位
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// 在指定位置插入新节点
void insert_node(ListNode **head, char *data, int position) {
    ListNode *new_node = create_node(data);

    if (*head == NULL || position == 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        ListNode *current = *head;
        int i = 0;

        // 找到目标位置节点的上一位
        while (current != NULL && i < position - 1) {
            current = current->next;
            ++ i;
        }

        new_node->next = current->next;
        current->next = new_node;
    }
}

// 删除指定节点
int delete_node (ListNode **head, int data) {
    if (*head == NULL) return 0;

    ListNode *current = *head; // 当前节点
    ListNode *previous = NULL; // 前一个节点

    // printf("current data: %d\n", data);
    // printf("current path: %s id: %d\n", current->str, *(current->str + (strlen(current->str) - 1)) - '0');

    while (current != NULL && *(current->str + (strlen(current->str) - 1)) - '0' != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return 0;

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);

    return 1;
}

int get_length(ListNode *head) {
    int length = 0;
    ListNode *current = head;

    while (current != NULL) {
        length ++;
        current = current->next;
    }

    return length;
}

void free_list(ListNode **head) {
    ListNode *current = *head;

    while (current != NULL) {
        ListNode *temp = current;
        current = current->next;
        free(temp);
    }

    *head = NULL;
}

void print_list(ListNode *head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("print %s\n ", current->str);
        current = current->next;
    }
}

void insert_at_end(ListNode** head, char *data) {
    ListNode* node = create_node(data);
    
    if (*head == NULL) {
        *head = node;
    } else {
        ListNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

int move_node_to_tail(ListNode** head, int data) {
    if (*head == NULL || (*head)->next == NULL) return 0;

    ListNode* current = *head;
    ListNode* previous = NULL;
    ListNode* target = NULL;

    while (current != NULL) {
        if (*(current->str + (strlen(current->str) - 1)) - '0' == data) {
            target = current;
            break;
        }

        previous = current;
        current = current->next;
    }

    if (target == NULL) return 0;

    if (previous != NULL) {
        previous->next = target->next;
    } else {
        *head = target->next;
    }

    insert_at_end(head, target->str);

    free(target);

    return 1;
}