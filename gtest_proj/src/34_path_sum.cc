#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "tree_util.h"

// https://leetcode.cn/problems/path-sum-ii/description/
// 题目：输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶子节点所
// 经过的节点形成的一条路径。
class Solution34 {
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> res;
        std::vector<int> cand;
        path_sum_internal(root, res, cand, targetSum);

        return res;
    }

private:
    void path_sum_internal(TreeNode* node, std::vector<std::vector<int>>& res, std::vector<int>& cand, int target_sum) {
        if (node == nullptr) {
            return;
        }

        cand.push_back(node->val);

        target_sum -= node->val;

        if (is_leaf(node)) {
            // 当前节点是叶子节点
            if (target_sum == 0) {  // 找到一条和为 target_sum 的路径
                res.push_back(cand);
                cand.pop_back();
                return;
            }
            cand.pop_back();
            return;
        }

        path_sum_internal(node->left, res, cand, target_sum);
        path_sum_internal(node->right, res, cand, target_sum);

        cand.pop_back();  // 当前节点以及其左右子树都考虑过了，从 cand 中删除
    }

    bool is_leaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }
};

MATCHER_P(VectorContentMatcher, vi, "") {
    const std::vector<std::vector<int>>& v = arg;
    size_t vi_size = vi.size();
    size_t v_size = v.size();
    if (vi_size != v_size) {
        return false;
    }
    for (size_t i = 0; i < vi_size; i++) {
        if (v[i] != vi[i]) {
            return false;
        }
    }

    return true;
}

TEST(ut_34, pathSum) {
    Solution34 s;

    {
        // 建二叉树时 nums 数组设置需小心，不然树结构和预期的不一致，用例肯定失败，但可能算法本身没问题
        std::vector<int> nums{5, 4, 11, 7, -1, -1, 2, -1, -1, -1, 8, 13, -1, -1, 4, 5, -1, -1, 1, -1, -1};
        TreeNode* root = create_pre_order(nums.data(), nums.size());
        auto res = s.pathSum(root, 22);
        std::vector<std::vector<int>> wanted{std::vector<int>{5, 4, 11, 2}, std::vector<int>{5, 8, 4, 5}};
        EXPECT_THAT(res, VectorContentMatcher(wanted));
        delete_postorder(root);
    }

    {
        std::vector<int> nums{1, 2, -1, -1, 3, -1, -1};
        TreeNode* root = create_pre_order(nums.data(), nums.size());
        auto res = s.pathSum(root, 5);
        EXPECT_TRUE(res.empty());
        res = s.pathSum(root, 0);
        EXPECT_TRUE(res.empty());
        delete_postorder(root);
    }
}
