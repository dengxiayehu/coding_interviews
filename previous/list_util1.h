#pragma once

#include <iostream>

#include "list_common.h"
#include "list_node.h"

inline int create_list_by_array1(const int arr[], const int n, ListNode*& head, ListNode*& tail) {
    head = NULL;
    tail = NULL;

    if (!arr || n <= 0) {
        return -1;
    }

    head = new ListNode[n];

    for (int i = 0; i < n; i++) {
        ListNode* node = &head[i];
        node->val = arr[i];
        if (i != n - 1) {
            node->next = node + 1;
        }
    }

    tail = &head[n - 1];

    return 0;
}

inline int destroy_list1(ListNode*& head) {
    delete[] head;

    return 0;
}
