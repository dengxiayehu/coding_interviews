#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "list_util.h"

// https://leetcode.cn/problems/reverse-linked-list/description/
// 题目：定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
// 题目虽然简单，但思路要清晰：新节点都插在反转链表的开头。
class Solution24 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* h = nullptr;
        ListNode* p = head;
        while (p != nullptr) {
            ListNode* q = p->next;
            if (h == nullptr) {
                // 反转后链表的第一个节点
                h = p;
                h->next = nullptr;
            } else {
                // 将元素添加到反转链表的开头
                p->next = h;
                h = p;
            }
            p = q;
        }

        return h;
    }
};

MATCHER_P(ListContentMatcher, vi, "") {
    int idx = 0;
    ListNode* p = arg;
    while (p != nullptr) {
        if (idx >= vi.size() || p->val != vi[idx]) {
            return false;
        }
        p = p->next;
        ++idx;
    }

    return idx == vi.size();
}

TEST(ut_24, reverseList) {
    Solution24 s;

    std::vector<int> nums{1, 2, 3, 4, 5};
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ASSERT_EQ(create_list_by_array(nums.data(), nums.size(), head, tail), 0);
    head = s.reverseList(head);
    EXPECT_THAT(head, ListContentMatcher(std::vector<int>{5, 4, 3, 2, 1}));
    destroy_list(head);
}
