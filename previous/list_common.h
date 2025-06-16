#pragma once

#include <iostream>
#include <string>

#include "list_node.h"

inline void print_list(ListNode* head) {
    std::string sep;
    ListNode* p = head;
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
