#include <gtest/gtest.h>

#include <memory>

#include "./immutable_list.h"

// https://leetcode.cn/problems/print-immutable-linked-list-in-reverse/description/
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

    auto deletor = [](ImmutableListNode* h) { destroy_list(h); };

    std::shared_ptr<ImmutableListNode> head(create_list(std::vector<int>{1, 2, 3}), deletor);
    s.printLinkedListInReverse(head.get());

    std::shared_ptr<ImmutableListNode> head1(create_list(std::vector<int>{1}), deletor);
    s.printLinkedListInReverse(head1.get());

    std::shared_ptr<ImmutableListNode> head2(nullptr, deletor);
    s.printLinkedListInReverse(head2.get());
}
