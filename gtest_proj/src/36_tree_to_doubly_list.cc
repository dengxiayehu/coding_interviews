#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "tree_util.h"

// https://leetcode.cn/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成排序的双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
// 二叉搜索树的中序遍历结果就是排序后的节点，我们需要维护 head 和 tail 信息，最后串起来。
class Solution36 {
public:
    TreeNode* treeToDoublyList(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* head = nullptr;
        TreeNode* tail = nullptr;
        tree_to_doubly_list_internal(root, head, tail);

        tail->right = head;
        head->left = tail;

        return head;
    }

private:
    void tree_to_doubly_list_internal(TreeNode* node, TreeNode*& head, TreeNode*& tail) {
        if (node == nullptr) {
            return;
        }

        tree_to_doubly_list_internal(node->left, head, tail);

        // 找到一个节点
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->right = node;
            node->left = tail;
            tail = node;
        }

        tree_to_doubly_list_internal(node->right, head, tail);
    }
};

MATCHER_P(TreeListContentMatcher, vi, "") {
    int idx = 0;
    TreeNode* head = arg;
    TreeNode* p = head;
    do {
        EXPECT_EQ(p->val, vi[idx]);
        p = p->right;
        idx++;
    } while (p != head);
    EXPECT_EQ(idx, vi.size());

    idx = vi.size() - 1;
    p = head->left;
    do {
        EXPECT_EQ(p->val, vi[idx]);
        p = p->left;
        --idx;
    } while (p != head->left);
    EXPECT_EQ(idx, -1);

    return true;
}

TEST(ut_36, treeToDoublyList) {
    Solution36 s;

    std::vector<int> nums{10, 6, 4, -1, -1, 8, -1, -1, 14, 12, -1, -1, 16, -1, -1};
    TreeNode* root = create_pre_order(nums.data(), nums.size());
    TreeNode* head = s.treeToDoublyList(root);
    EXPECT_THAT(head, TreeListContentMatcher(std::vector<int>{4, 6, 8, 10, 12, 14, 16}));

    // 手动删除这种特殊的树节点链表
    TreeNode* p = head;
    TreeNode* q = nullptr;
    do {
        q = p->right;
        delete p;
        p = q;
    } while (p != head);
}
