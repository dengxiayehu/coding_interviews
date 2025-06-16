#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "./matchers.h"
#include "list_util1.h"

// https://leetcode.cn/problems/linked-list-cycle-ii/
class Solution23 {
public:
    ListNode* detectCycle(ListNode* head) {
        // 空链表直接返回
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        do {
            if (fast == nullptr || fast->next == nullptr) {
                // fast 走得快，若没有环肯定会先到链表尾
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        // 有环，找到环的入口处
        ListNode* p = head;
        while (p != slow) {
            p = p->next;
            slow = slow->next;
        }

        return slow;
    }
};

TEST(ut_23, DetectCycle) {
    Solution23 s;

    {
        std::vector<int> nums{1, 2, 3, 4, 5};
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        create_list_by_array1(nums.data(), nums.size(), head, tail);
        ASSERT_THAT(head, NotNull());
        ListNode* res = s.detectCycle(head);
        EXPECT_THAT(res, IsNull());
        destroy_list1(head);
    }

    {
        std::vector<int> nums1{1, 2};
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        create_list_by_array1(nums1.data(), nums1.size(), head, tail);
        ASSERT_THAT(head, NotNull());
        head[1].next = &head[0];
        ListNode* res = s.detectCycle(head);
        ASSERT_THAT(res, NotNull());
        EXPECT_EQ(res->val, 1);
        destroy_list1(head);
    }
}
