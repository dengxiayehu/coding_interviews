#pragma once

#include <iostream>
#include <cstdarg>

#include "macro_util.h"

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode() :
        next(NULL), random(NULL) { }
    explicit RandomListNode(int x) : label(x), next(NULL), random(NULL) {
    }
};

inline int create_list_by_array(const int arr[], const int n, RandomListNode*& head, RandomListNode*& tail) {
    head = NULL;
    tail = NULL;

    if (!arr || n <= 0) {
        return -1;
    }

    head = new RandomListNode[n];

    for (int i = 0; i < n; i++) {
        RandomListNode *node = &head[i];
        node->label = arr[i];
        if (i != n-1) {
            node->next = node+1;
        }
    }

    tail = &head[n-1];

    return 0;
}

inline int random_list(RandomListNode* root, ...) {
    va_list ap;
    va_start(ap, root);

    for ( ; ; ) {
        int from = va_arg(ap, int);
        if (from == -1) {
            goto out;
        }
        int to = va_arg(ap, int);
        if (to == -1) {
            goto out;
        }

        root[from].random = &root[to];
    }

out:
    va_end(ap);

    return 0;
}

inline int destroy_list(RandomListNode*& head) {
    delete[] head;

    return 0;
}

inline void print_list(RandomListNode* head) {
    RandomListNode *p = head;
    while (p) {
        std::cout << p << "@" << p->label;
        if (p->random) {
            std::cout << ":" << p->random->label;
        }
        std::cout << " ";
        p = p->next;
    }
    std::cout << std::endl;
}
