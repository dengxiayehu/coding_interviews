#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "list_util.h"

// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/
// 题目：在一个排序的链表中，如何删除重复的节点？
// 这道题主要是能想到三指针的思想，另外记得释放节点内存。
class Solution18_2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* x = head;
        ListNode* p = head;
        ListNode* q = head->next;
        while (q != nullptr) {
            // p 和 q 节点的值相同，则需要删除所有值为 val 的节点
            if (p->val == q->val) {
                ListNode* t = q->next;
                while (t != nullptr && t->val == q->val) {
                    t = t->next;
                }
                // t 为新值节点或者链表结尾 nullptr
                if (p == head) {
                    // 考虑删除节点
                    ListNode* r = head;
                    while (r != t) {
                        ListNode* n = r->next;
                        delete r;
                        r = n;
                    }
                    head = t;
                    if (t == nullptr) {
                        break;
                    }
                    x = t;
                    p = t;
                    q = t->next;
                } else {
                    // 考虑删除节点
                    ListNode* r = p;
                    while (r != t) {
                        ListNode* n = r->next;
                        delete r;
                        r = n;
                    }
                    x->next = t;
                    if (t == nullptr) {
                        break;
                    }
                    p = t;
                    q = t->next;
                }
            } else {
                if (x->val != p->val) {
                    x = p;
                }
                p = p->next;
                q = q->next;
            }
        }

        return head;
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

TEST(ut_18_2, deleteDuplication) {
    Solution18_2 s;

    {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        std::vector<int> arr = {1, 2, 3, 3, 4, 4, 5};
        ASSERT_EQ(create_list_by_array(arr.data(), arr.size(), head, tail), 0);
        EXPECT_THAT(head, ListContentMatcher(arr));

        head = s.deleteDuplicates(head);
        EXPECT_THAT(head, ListContentMatcher(std::vector<int>{1, 2, 5}));
        destroy_list(head);
    }

    {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        std::vector<int> arr = {1, 1, 3, 4, 5};
        ASSERT_EQ(create_list_by_array(arr.data(), arr.size(), head, tail), 0);
        EXPECT_THAT(head, ListContentMatcher(arr));

        head = s.deleteDuplicates(head);
        EXPECT_THAT(head, ListContentMatcher(std::vector<int>{3, 4, 5}));
        destroy_list(head);
    }

    {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        std::vector<int> arr = {1, 1, 3, 3, 5, 5};
        ASSERT_EQ(create_list_by_array(arr.data(), arr.size(), head, tail), 0);
        EXPECT_THAT(head, ListContentMatcher(arr));

        head = s.deleteDuplicates(head);
        EXPECT_THAT(head, ListContentMatcher(std::vector<int>{}));
        destroy_list(head);
    }

    {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        std::vector<int> arr = {1, 1, 1, 2, 3};
        ASSERT_EQ(create_list_by_array(arr.data(), arr.size(), head, tail), 0);
        EXPECT_THAT(head, ListContentMatcher(arr));

        head = s.deleteDuplicates(head);
        EXPECT_THAT(head, ListContentMatcher(std::vector<int>{2, 3}));
        destroy_list(head);
    }
}
