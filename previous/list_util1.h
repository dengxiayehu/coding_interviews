#pragma once

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) { }
    explicit ListNode(int v) : val(v), next(NULL) {
    }
};

inline int create_list_by_array(const int arr[], const int n, ListNode*& head, ListNode*& tail) {
    head = NULL;
    tail = NULL;

    if (!arr || n <= 0) {
        return -1;
    }

    head = new ListNode[n];

    for (int i = 0; i < n; i++) {
        ListNode *node = &head[i];
        node->val = arr[i];
        if (i != n-1) {
            node->next = node+1;
        }
    }

    tail = &head[n-1];

    return 0;
}

inline int destroy_list(ListNode*& head) {
    delete[] head;

    return 0;
}

// NOTE: should not use this function to print loop link list
inline void print_list(ListNode* head) {
    ListNode *p = head;
    while (p) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}
