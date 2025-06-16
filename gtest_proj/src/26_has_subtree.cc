#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "./matchers.h"
#include "tree_util.h"

// https://leetcode.cn/problems/subtree-of-another-tree/description/
// 题目：给你两棵二叉树 root 和 subRoot。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在返回 true；
// 否则返回 false。
// 二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。
// 思路：遍历 root 中节点，然后挨个调用 is_sub_match() 函数去尝试匹配。
class Solution26 {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr || subRoot == nullptr) {
            return false;
        }

        return is_subtree_internal(root, subRoot);
    }

private:
    // 先序递归遍历 root
    bool is_subtree_internal(TreeNode* root, TreeNode* sub) {
        if (is_sub_match(root, sub)) {
            return true;
        }

        if (root != nullptr) {
            return is_subtree_internal(root->left, sub) || is_subtree_internal(root->right, sub);
        }

        return false;
    }

    // 判断 s 和 r 是否相等
    bool is_sub_match(TreeNode* r, TreeNode* s) {
        if (r == nullptr && s == nullptr) {
            return true;
        }

        if (r != nullptr && s != nullptr && r->val == s->val) {
            return is_sub_match(r->left, s->left) && is_sub_match(r->right, s->right);
        }

        return false;
    }
};

TEST(ut_26, isSubtree) {
    Solution26 s;

    {
        std::vector<int> nums_root{3, 4, 1, -1, -1, 2, -1, -1, 5, -1, -1};
        TreeNode* root = create_pre_order(nums_root.data(), nums_root.size());
        ASSERT_THAT(root, NotNull());
        std::vector<int> nums_sub{4, 1, -1, -1, 2, -1, -1};
        TreeNode* sub_root = create_pre_order(nums_sub.data(), nums_sub.size());
        ASSERT_THAT(sub_root, NotNull());
        EXPECT_TRUE(s.isSubtree(root, sub_root));
        delete_postorder(root);
        delete_postorder(sub_root);
    }

    {
        std::vector<int> nums_root{1, -1, 1, -1, 1, -1, 1, 2, -1, -1, -1};
        TreeNode* root = create_pre_order(nums_root.data(), nums_root.size());
        ASSERT_THAT(root, NotNull());
        std::vector<int> nums_sub{1, -1, 1, 2, -1, -1, -1};
        TreeNode* sub_root = create_pre_order(nums_sub.data(), nums_sub.size());
        ASSERT_THAT(sub_root, NotNull());
        EXPECT_TRUE(s.isSubtree(root, sub_root));
        delete_postorder(root);
        delete_postorder(sub_root);
    }
}
