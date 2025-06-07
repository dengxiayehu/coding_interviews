#include <gtest/gtest.h>

#include <memory>

#include "./immutable_list.h"

// leetcode 1265：逆序打印不可变链表
class Solution06 {
public:
    // 先递归再打印
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (head == nullptr) {
            return;
        }
        printLinkedListInReverse(head->getNext());
        head->printValue();
    }
};

TEST(ut_06, PrintLinkedListInReverse) {
    Solution06 s;

    std::shared_ptr<ImmutableListNode> head(create_list(std::vector<int>{1, 2, 3}), destroy_list);
    s.printLinkedListInReverse(head.get());

    std::shared_ptr<ImmutableListNode> head1(create_list(std::vector<int>{1}), destroy_list);
    s.printLinkedListInReverse(head1.get());

    std::shared_ptr<ImmutableListNode> head2(nullptr, destroy_list);
    s.printLinkedListInReverse(head2.get());
}
