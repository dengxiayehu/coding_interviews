#pragma once

#include <stdio.h>

#include <iostream>
#include <string>

#include "macro_util.h"

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int v) : val(v), next(NULL) {
    }
};

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

inline void print_list(ListNode* head) {
    std::string sep;
    ListNode *p = head;
    while (p) {
        std::cout << sep << p->val;
        if (sep.empty()) {
            sep = " ";
        }
        p = p->next;
    }
    std::cout << std::endl;
}

inline int get_list_size(ListNode* head) {
    int size = 0;
    ListNode* p = head;
    while (p) {
        p = p->next;
        ++size;
    }

    return size;
}
