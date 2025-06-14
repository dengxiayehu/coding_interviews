#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "list_util.h"

// https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/
class Solution22 {
public:
    int kthToLast(ListNode* head, int k) {
        if (head == nullptr || k <= 0) {
            return -1;
        }
        ListNode* fast = head;
        for (int i = 0; i < k; i++) {
            if (fast != nullptr) {
                fast = fast->next;
            } else {
                return -1;
            }
        }
        ListNode* slow = head;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow->val;
    }
};

TEST(ut_22, kthToLast) {
    Solution22 s;

    std::vector<int> nums{1, 2, 3, 4, 5};
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ASSERT_EQ(create_list_by_array(nums.data(), nums.size(), head, tail), 0);
    EXPECT_EQ(s.kthToLast(head, 1), 5);
    EXPECT_EQ(s.kthToLast(head, 2), 4);
    EXPECT_EQ(s.kthToLast(head, 5), 1);
    destroy_list(head);
}
