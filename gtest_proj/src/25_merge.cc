#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "list_util.h"

// https://leetcode.cn/problems/merge-two-sorted-lists/description/
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。leetcode 上有一个限制是新链表是通过
// 拼接给定的两个链表的所有节点组成的。
class Solution25 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h = nullptr;
        ListNode* t = nullptr;
        // 先一并处理 l1 和 l2
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* node = nullptr;
            if (l1->val < l2->val) {
                // 看题意，元素相同时采用的 l2 链表中节点
                node = l1;
                l1 = l1->next;
            } else {
                node = l2;
                l2 = l2->next;
            }
            node->next = nullptr;
            if (h == nullptr) {
                h = t = node;
            } else {
                t->next = node;
                t = node;
            }
        }
        auto append = [&h, t](ListNode* l) {
            if (l != nullptr) {
                if (h == nullptr) {
                    h = l;
                } else {
                    t->next = l;
                }
            }
        };
        // 判断 l1/l2 中是否还有剩余元素
        append(l1);
        append(l2);

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

TEST(ut_25, merge) {
    Solution25 s;

    std::vector<int> nums1{1, 2, 4};
    ListNode* l1 = nullptr;
    ListNode* t1 = nullptr;
    ASSERT_EQ(create_list_by_array(nums1.data(), nums1.size(), l1, t1), 0);

    std::vector<int> nums2{1, 3, 4};
    ListNode* l2 = nullptr;
    ListNode* t2 = nullptr;
    ASSERT_EQ(create_list_by_array(nums2.data(), nums2.size(), l2, t2), 0);

    ListNode* h = s.mergeTwoLists(l1, l2);
    ASSERT_THAT(h, ListContentMatcher(std::vector{1, 1, 2, 3, 4, 4}));

    destroy_list(h);
}
