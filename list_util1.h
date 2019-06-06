#ifndef LIST_UTIL1_H
#define LIST_UTIL1_H

#include <iostream>

#include "macro_util.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) { }
    ListNode(int v) : val(v), next(NULL) { }
};

static int create_list_by_array(const int arr[], const int n, ListNode *&head, ListNode *&tail)
{
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

static int destroy_list(ListNode *&head)
{
    delete [] head;

    return 0;
}

static void print_list(ListNode *head)
{
    ListNode *p = head;
    while (p) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

#endif