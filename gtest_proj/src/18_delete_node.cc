#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "list_util.h"

// 题目：在 O(1) 时间内删除链表节点。
// 在删除尾节点时时间复杂度是 O(n)，其他情况时间复杂度是 O(1)，整体满足 O(1) 时间复杂度的要求。
// 删除的节点记得要释放内存，不是仅仅将其从链表中删除
class Solution18 {
public:
    void DeleteNode(ListNode** head, ListNode* tbd) {
        if (head == nullptr || *head == nullptr || tbd == nullptr) {
            return;
        }

        if (*head == tbd) {
            *head = (*head)->next;
            delete tbd;
        } else if (tbd->next == nullptr) {
            // 删除尾节点时需遍历找到其前驱节点
            ListNode* p = *head;
            while (p != nullptr && p->next != tbd) {
                p = p->next;
            }
            if (p != nullptr) {
                // 找到了前驱
                p->next = p->next->next;
                delete tbd;
            }
        } else {
            // 在中间节点，把下一个节点的值拷贝到当前节点，然后把下一个节点给删除
            ListNode* next_node = tbd->next;
            tbd->val = next_node->val;
            tbd->next = next_node->next;
            delete next_node;
        }
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

TEST(ut_18, deleteNode) {
    Solution18 s;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    std::vector<int> arr = {1, 2, 3, 4};
    ASSERT_EQ(create_list_by_array(arr.data(), arr.size(), head, tail), 0);
    EXPECT_THAT(head, ListContentMatcher(arr));

    // 将头节点 1 删除
    ListNode* p = head->next;
    s.DeleteNode(&head, head);
    EXPECT_EQ(head, p);
    arr.erase(arr.begin());
    EXPECT_THAT(head, ListContentMatcher(std::vector<int>{2, 3, 4}));

    // 将节点 3 删除（其实原先节点 3 指向的空间并没有被删除，真正删除的是 4 指向的空间）
    p = head->next;
    s.DeleteNode(&head, p);
    EXPECT_THAT(head, ListContentMatcher(std::vector<int>{2, 4}));

    // 将结尾节点 4 删除
    p = head->next;
    s.DeleteNode(&head, p);
    EXPECT_THAT(head, ListContentMatcher(std::vector<int>{2}));
}
