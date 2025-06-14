#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "list_util.h"

// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
// 题目：输入一个链表，删除该链表中倒数第 n 个节点。最后一个节点是倒数第 1 个节点。
class Solution22_1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n <= 0) {
            return nullptr;
        }
        ListNode* fast = head;
        // fast 先走 n 步，明确肯定存在倒数第 n 个节点
        for (int i = 0; i < n; i++) {
            if (fast != nullptr) {
                fast = fast->next;
            } else {
                return nullptr;
            }
        }
        // 再尝试让 fast 多走一步，如此我们可以定位到倒数 n 个节点的前驱
        if (fast != nullptr) {
            fast = fast->next;
        } else {
            // 删除的其实是头节点
            ListNode* p = head;
            head = head->next;
            delete p;
            return head;
        }

        ListNode* slow = head;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // slow 是要删除节点的前驱
        ListNode* p = slow->next;
        slow->next = slow->next->next;
        delete p;

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

TEST(ut_22_1, removeNthFromEnd) {
    Solution22_1 s;

    std::vector<int> nums{1, 2, 3, 4, 5};
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ASSERT_EQ(create_list_by_array(nums.data(), nums.size(), head, tail), 0);
    head = s.removeNthFromEnd(head, 1);
    EXPECT_THAT(head, ListContentMatcher(std::vector<int>{1, 2, 3, 4}));
    head = s.removeNthFromEnd(head, 4);
    EXPECT_THAT(head, ListContentMatcher(std::vector<int>{2, 3, 4}));
    head = s.removeNthFromEnd(head, 1);
    EXPECT_THAT(head, ListContentMatcher(std::vector<int>{2, 3}));
    destroy_list(head);
}
