#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "random_list_util.h"

// https://leetcode.cn/problems/copy-list-with-random-pointer/
// 题目：请实现一个函数复制一个复杂链表。在复杂链表中每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针
// 指向链表中任意节点或者 nullptr。
// 思路：先遍历原始链表，每个节点都复制一份挂在原始节点后面。第二遍再处理 random 指针，原始->目标，复制->目标->next。
// 提交 leetcode 时将 RandomListNode 替换为 Node，label 替换为 val。
class Solution35 {
public:
    RandomListNode* copyRandomList(RandomListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        RandomListNode* p = head;
        RandomListNode* q = nullptr;
        RandomListNode* dup = nullptr;
        while (p != nullptr) {
            q = p->next;

            dup = new RandomListNode(p->label);
            dup->next = q;
            p->next = dup;

            p = q;
        }

        // 处理 dup->random，这一步需要和下面的拆分步骤分开
        p = head;
        while (p != nullptr) {
            dup = p->next;
            if (p->random != nullptr) {
                dup->random = p->random->next;
            }

            p = dup->next;
        }

        // 拆分链表为 head 和 dup_head
        RandomListNode* dup_head = nullptr;
        RandomListNode* dup_tail = nullptr;
        p = head;
        while (p != nullptr) {
            dup = p->next;
            q = dup->next;

            if (dup_head == nullptr) {
                dup_head = dup_tail = dup;
            } else {
                dup_tail->next = dup;
                dup_tail = dup;
            }

            p->next = q;
            p = q;
        }

        return dup_head;
    }
};

TEST(ut_35, copyRandomList) {
    Solution35 s;

    std::vector<int> nums{7, 13, 11, 10, 1};
    RandomListNode* head = nullptr;
    RandomListNode* tail = nullptr;
    create_list_by_array(nums.data(), nums.size(), head, tail);
    random_list(head, 1, 0, 2, 4, 3, 2, 4, 0, -1);
    RandomListNode* clone = s.copyRandomList(head);
    destroy_list(head);
    destroy_list(clone);
}
