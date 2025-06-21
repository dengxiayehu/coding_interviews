#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "tree_util.h"

// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/
// 题目：给定一个二叉搜索树的根节点 root，和一个整数 k，请你设计一个算法查找其中第 k 小的元素。（从 1 开始计数）
// 二叉搜索树的中序遍历就是递增顺序。
class Solution54 {
public:
    int kthSmallest(TreeNode* node, int k) {
        if (node == nullptr || k <= 0) {
            return -1;
        }

        int res = -1;
        kth_smallest_internal(node, k, res);

        return res;
    }

private:
    void kth_smallest_internal(TreeNode* node, int& k, int& res) {
        if (node == nullptr || k == 0) {
            return;
        }

        kth_smallest_internal(node->left, k, res);

        if (--k == 0) {
            res = node->val;
            return;
        }

        kth_smallest_internal(node->right, k, res);
    }
};

TEST(ut_54, kthSmallest) {
    Solution54 s;

    std::vector<int> nums{3, 1, -1, 2, -1, -1, 4, -1, -1};
    TreeNode* root = create_pre_order(nums.data(), nums.size());
    EXPECT_EQ(s.kthSmallest(root, 1), 1);
    delete_postorder(root);
}
