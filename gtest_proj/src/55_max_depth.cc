#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "tree_util.h"

// https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
// 题目：给定一个二叉树 root，返回其最大深度。（root 的深度是 1）
class Solution55 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

TEST(ut_55, maxDepth) {
    Solution55 s;

    std::vector<int> nums{3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    TreeNode* root = create_pre_order(nums.data(), nums.size());
    EXPECT_EQ(s.maxDepth(root), 3);
    delete_postorder(root);
}
