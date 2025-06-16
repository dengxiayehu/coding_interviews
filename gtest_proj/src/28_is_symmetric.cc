#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "./matchers.h"
#include "tree_util.h"

// https://leetcode.cn/problems/symmetric-tree/
// 题目：给你一棵二叉树的根节点 root，检查它是否轴对称。
class Solution28 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }

        return is_symmetric_internal(root, root);
    }

private:
    // 定义两种遍历方式：l 是先序遍历，r 是先根后右再左遍历，若树是镜像的话这两种遍历顺序应该是完全一致的。
    bool is_symmetric_internal(TreeNode* l, TreeNode* r) {
        if (l == nullptr && r == nullptr) {
            return true;
        }

        if (l != nullptr && r != nullptr) {
            if (l->val == r->val) {
                return is_symmetric_internal(l->left, r->right) && is_symmetric_internal(l->right, r->left);
            }
        }

        return false;
    }
};

TEST(ut_28, isSymmetric) {
    Solution28 s;

    {
        std::vector<int> nums_root{1, 2, 3, -1, -1, 4, -1, -1, 2, 4, -1, -1, 3, -1, -1};
        TreeNode* root = create_pre_order(nums_root.data(), nums_root.size());
        ASSERT_THAT(root, NotNull());
        ASSERT_TRUE(s.isSymmetric(root));
        delete_postorder(root);
    }

    {
        std::vector<int> nums_root{1, 2, -1, 3, -1, -1, 2, -1, 3, -1, -1};
        TreeNode* root = create_pre_order(nums_root.data(), nums_root.size());
        ASSERT_THAT(root, NotNull());
        ASSERT_FALSE(s.isSymmetric(root));
        delete_postorder(root);
    }
}
