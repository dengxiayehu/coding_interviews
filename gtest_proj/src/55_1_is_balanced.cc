#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "tree_util.h"

// https://leetcode.cn/problems/balanced-binary-tree/description/
// 题目：平衡二叉树。输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左、右子树的深度差不超过
// 1，那么它就是一棵平衡二叉树。
// 采用后序遍历能较好地解决问题，处理父节点时左右子树的深度已经有了。
class Solution55_1 {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        bool res = true;
        is_balanced_internal(root, res);

        return res;
    }

private:
    int is_balanced_internal(TreeNode* root, bool& res) {
        if (!res) {
            return 0;
        }

        if (root == nullptr) {
            return 0;
        }

        // 先算左子树深度
        int left = is_balanced_internal(root->left, res);
        int right = 0;
        if (res) {
            // 再算右子树深度
            right = is_balanced_internal(root->right, res);
        }
        int gap = left - right;
        if (gap > 1 || gap < -1) {
            res = false;
            return 0;
        }

        return std::max(left, right) + 1;
    }
};

TEST(ut_55_1, tn_55_1) {
    Solution55_1 s;

    {
        std::vector<int> nums{3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
        TreeNode* root = create_pre_order(nums.data(), nums.size());
        EXPECT_TRUE(s.isBalanced(root));
        delete_postorder(root);
    }

    {
        std::vector<int> nums{1, 2, 3, 4, -1, -1, 4, -1, -1, 3, -1, -1, 2, -1, -1};
        TreeNode* root = create_pre_order(nums.data(), nums.size());
        EXPECT_FALSE(s.isBalanced(root));
        delete_postorder(root);
    }
}
