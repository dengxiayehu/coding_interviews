#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <stack>
#include <vector>

#include "./matchers.h"
#include "tree_util.h"

// https://leetcode.cn/problems/invert-binary-tree/description/
// 题目：请完成一个函数，输入一棵二叉树，该函数输出它的镜像。
// 在原树的基础上做镜像操作。
class Solution27 {
public:
    TreeNode* invertTree(TreeNode* root) {
        invert_tree_internal(root);

        return root;
    }

private:
    void invert_tree_internal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invert_tree_internal(root->left);
        invert_tree_internal(root->right);
    }
};

MATCHER_P(TreeContentMatcher, vi, "") {
    int idx = 0;
    TreeNode* root = arg;
    std::stack<TreeNode*> s;
    TreeNode* node = root;
    while (node != nullptr || !s.empty()) {
        if (node != nullptr) {
            int tmp = vi[idx++];
            if (tmp != node->val) {
                return false;
            }
            s.push(node);
            node = node->left;
        } else {
            int tmp = vi[idx++];
            if (tmp != -1) {
                return false;
            }
            node = s.top();
            s.pop();
            node = node->right;
        }
    }
    if (root != nullptr) {
        if (vi[idx++] != -1) {
            return -1;
        }
    }

    return idx == vi.size();
}

TEST(ut_27, invertTree) {
    Solution27 s;

    std::vector<int> nums_root{3, 4, 1, -1, -1, 2, -1, -1, 5, -1, -1};
    TreeNode* root = create_pre_order(nums_root.data(), nums_root.size());
    ASSERT_THAT(root, NotNull());
    TreeNode* invert_root = s.invertTree(root);
    EXPECT_THAT(invert_root, TreeContentMatcher(std::vector<int>{3, 5, -1, -1, 4, 2, -1, -1, 1, -1, -1}));
    delete_postorder(invert_root);
}
