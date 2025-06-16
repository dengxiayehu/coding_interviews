#pragma once

#include <stdio.h>

#include <iostream>
#include <string>

#include "list_common.h"
#include "list_node.h"
#include "macro_util.h"

inline int create_list_by_array(const int arr[], const int n, ListNode*& head, ListNode*& tail) {
    head = NULL;
    tail = NULL;

    if (!arr || n <= 0) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        ListNode *node = new ListNode(arr[i]);
        if (!head) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    return 0;
}

inline int destroy_list(ListNode*& head) {
    ListNode *p, *q;
    p = head;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }
    head = NULL;

    return 0;
}
