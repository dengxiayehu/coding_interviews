#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "list_util.h"

// 题目：圆圈中最后存在的数字。在0, 1, 2, ..., n - 1 这 n 个数字排成一个圆圈，从数字 0 开始，每次从这个圆圈里删除第 m 个
// 数字。求出这个圆圈里剩下的最后一个数字。例如，0, 1, 2, 3, 4 这 5 个数字组成一圈，m = 3 时删除的顺序是：2、0、4、1。
class Solution62 {
public:
    int lastRemaining(int n, int m) {
        if (n < 1 || m < 1) {
            return -1;
        }

        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        std::vector<int> nums;
        for (int i = 0; i < n; i++) {
            nums.push_back(i);
        }
        int ret = create_list_by_array(nums.data(), nums.size(), head, tail);
        if (ret != 0) {
            return -1;
        }
        // 形成一个环
        tail->next = head;

        m %= n;

        ListNode* cur = head;
        ListNode* prev = tail;
        while (cur != prev) {
            for (int i = 1; i < m; ++i) {
                cur = cur->next;
                prev = prev->next;
            }
            ListNode* to_delete = cur;
            prev->next = cur->next;
            cur = cur->next;
            delete to_delete;
        }

        ret = cur->val;

        cur->next = nullptr;
        destroy_list(cur);

        return ret;
    }
};

TEST(ut_62, lastRemaining) {
    Solution62 s;

    EXPECT_EQ(s.lastRemaining(5, 3), 3);
    EXPECT_EQ(s.lastRemaining(5, 1), 4);
}
