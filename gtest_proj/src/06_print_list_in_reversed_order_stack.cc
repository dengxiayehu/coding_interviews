#include <gtest/gtest.h>

#include <memory>
#include <stack>

#include "./immutable_list.h"

// leetcode 1265：逆序打印不可变链表
class Solution06_1 {
public:
    // 遍历链表将节点放到栈中，待遍历完成后在将节点弹出并打印
    void printLinkedListInReverse(ImmutableListNode* head) {
        std::stack<ImmutableListNode*> s;
        for (ImmutableListNode* p = head; p != nullptr; p = p->getNext()) {
            s.push(p);
        }
        while (!s.empty()) {
            s.top()->printValue();
            s.pop();
        }
    }
};

TEST(ut_06, PrintLinkedListInReverseWithStack) {
    Solution06_1 s;

    auto deletor = [](ImmutableListNode* h) { destroy_list(h); };

    std::shared_ptr<ImmutableListNode> head(create_list(std::vector<int>{1, 2, 3}), deletor);
    s.printLinkedListInReverse(head.get());

    std::shared_ptr<ImmutableListNode> head1(create_list(std::vector<int>{1}), deletor);
    s.printLinkedListInReverse(head1.get());

    std::shared_ptr<ImmutableListNode> head2(nullptr, deletor);
    s.printLinkedListInReverse(head2.get());
}
