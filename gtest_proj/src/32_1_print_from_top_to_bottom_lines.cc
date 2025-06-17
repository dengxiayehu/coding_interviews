#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <queue>
#include <vector>

#include "tree_util.h"

// https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
// 题目：分行从上到下打印二叉树，同一层的节点按照从左到右的顺序打印。
// 这道题技巧性很高，需想到当前行个数和下一行个数信息。
class Solution32_1 {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        std::vector<int> lv;
        std::queue<TreeNode*> q;
        q.push(root);
        int next_lvl = 0;  // 下一行节点数
        int cur_lvl = 1;   // 每一行节点数，第一行数目肯定是 1
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            lv.push_back(node->val);

            if (node->left != nullptr) {
                q.push(node->left);
                ++next_lvl;
            }

            if (node->right != nullptr) {
                q.push(node->right);
                ++next_lvl;
            }

            if (--cur_lvl == 0) {
                cur_lvl = next_lvl;
                res.push_back(lv);
                lv.clear();
                next_lvl = 0;
            }
        }

        return res;
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

TEST(ut_32_1, levelOrder) {
    Solution32_1 s;

    std::vector<int> nums{3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    TreeNode* root = create_pre_order(nums.data(), nums.size());
    auto res = s.levelOrder(root);
    std::vector<std::vector<int>> wanted{std::vector<int>{3}, std::vector<int>{9, 20}, std::vector<int>{15, 7}};
    EXPECT_THAT(res, VectorContentMatcher(wanted));
    delete_postorder(root);
}
