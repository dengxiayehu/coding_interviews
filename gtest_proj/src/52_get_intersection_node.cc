#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "./matchers.h"
#include "list_util1.h"

// https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
// 题目：输入两个链表，找出它们的第一个公共节点。如果两个链表不存在交点则返回 null。
class Solution52 {
public:
    ListNode* getIntersectionNode(ListNode* head_a, ListNode* head_b) {
        if (head_a == nullptr || head_b == nullptr) {
            return nullptr;
        }

        int list_length_a = get_list_length(head_a);
        int list_length_b = get_list_length(head_b);
        int skip_a = list_length_a - list_length_b;
        int skip_b = list_length_b - list_length_a;
        ListNode* p = head_a;
        while (skip_a > 0) {
            p = p->next;
            --skip_a;
        }
        ListNode* q = head_b;
        while (skip_b > 0) {
            q = q->next;
            --skip_b;
        }
        while (p != nullptr && q != nullptr) {
            if (p == q) {
                return p;
            }
            p = p->next;
            q = q->next;
        }

        return nullptr;
    }

private:
    int get_list_length(ListNode* head) {
        if (head == nullptr) {
            return 0;
        }
        int count = 0;
        ListNode* n = head;
        while (n != nullptr) {
            ++count;
            n = n->next;
        }

        return count;
    }
};

TEST(ut_52, getIntersectionNode) {
    Solution52 s;

    ListNode* head_a = nullptr;
    ListNode* tail_a = nullptr;
    std::vector<int> nums_a{101, 102, 103, 104, 105};
    ASSERT_EQ(create_list_by_array1(nums_a.data(), nums_a.size(), head_a, tail_a), 0);
    ListNode* head_b = nullptr;
    ListNode* tail_b = nullptr;
    std::vector<int> nums_b{1, 2, 3};
    ASSERT_EQ(create_list_by_array1(nums_b.data(), nums_b.size(), head_b, tail_b), 0);
    head_b[2].next = &head_a[2];
    ListNode* res = s.getIntersectionNode(head_a, head_b);
    EXPECT_THAT(res, NotNull());
    EXPECT_EQ(res->val, 103);
    destroy_list1(head_a);
    destroy_list1(head_b);
}
