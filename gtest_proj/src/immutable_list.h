#pragma once

#include <iostream>
#include <vector>

class ImmutableListNode {
public:
    ImmutableListNode(int value, ImmutableListNode* prev) : m_value(value), m_next(nullptr) {
        if (prev != nullptr) {
            m_next = prev->m_next;
            prev->m_next = this;
        }
    }

    void printValue() {
        std::cout << m_value;
    }

    ImmutableListNode* getNext() {
        return m_next;
    }

private:
    int m_value;
    ImmutableListNode* m_next;
};

inline ImmutableListNode* create_list(const std::vector<int>& vec) {
    if (vec.empty()) {
        return nullptr;
    }

    ImmutableListNode* head = nullptr;
    ImmutableListNode* tail = nullptr;
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
        ImmutableListNode* node = new ImmutableListNode(*it, tail);
        if (head == nullptr) {
            head = node;
        }
        tail = node;
    }

    return head;
}

inline int destroy_list(ImmutableListNode* head) {
    ImmutableListNode *p, *q;
    p = head;
    while (p) {
        q = p->getNext();
        delete p;
        p = q;
    }

    return 0;
}
