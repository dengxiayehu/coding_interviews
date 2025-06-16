#pragma once

#include <cstddef>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {
    }
    explicit ListNode(int v) : val(v), next(nullptr) {
    }
};
