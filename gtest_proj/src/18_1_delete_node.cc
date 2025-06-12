#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "list_util.h"

// https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/description/
class Solution18_1 {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr) {
            return nullptr;
        }

        // 删除头节点
        if (head->val == val) {
            head = head->next;
            return head;
        }

        // 用一前一后两个指针
        ListNode* p = head;
        ListNode* q = head->next;
        while (q != nullptr) {
            if (q->val == val) {
                p->next = q->next;
                break;
            }
            p = p->next;
            q = q->next;
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

TEST(ut_18_1, deleteNode) {
    Solution18_1 s;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    std::vector<int> arr = {1, 2, 3, 4};
    ASSERT_EQ(create_list_by_array(arr.data(), arr.size(), head, tail), 0);
    EXPECT_THAT(head, ListContentMatcher(arr));

    head = s.deleteNode(head, 1);
    EXPECT_THAT(head, ListContentMatcher(std::vector<int>{2, 3, 4}));
    head = s.deleteNode(head, 4);
    EXPECT_THAT(head, ListContentMatcher(std::vector<int>{2, 3}));
    head = s.deleteNode(head, 2);
    EXPECT_THAT(head, ListContentMatcher(std::vector<int>{3}));
    head = s.deleteNode(head, 3);
    EXPECT_THAT(head, ListContentMatcher(std::vector<int>{}));
}
