#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <queue>
#include <vector>

#include "tree_util.h"

// https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/description/
// 题目：给你二叉树的根节点 root，返回其节点值自底向上的层序遍历。
// 这道题可以在由上到下层序遍历的基础上反转结果就行。
class Solution32_2 {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> res;

        if (root == nullptr) {
            return res;
        }

        std::vector<int> lv;
        std::queue<TreeNode*> q;
        q.push(root);
        int cur_lvl = 1;
        int next_lvl = 0;
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
                next_lvl = 0;
                res.push_back(lv);
                lv.clear();
            }
        }

        std::reverse(res.begin(), res.end());

        return res;
    }

private:
    // 这个算法假定根节点的深度是 1
    // 另外一种思路是先将上面 res 向量的大小确定好，就是 get_depth(root)，然后再获取到一行结果时右后往前在 res 中写。
    // 这个算法较在最后 reverse res 慢，略。
    int get_depth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        return 1 + std::max(get_depth(node->left), get_depth(node->right));
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

TEST(ut_32_2, levelOrderBottom) {
    Solution32_2 s;

    std::vector<int> nums{3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    TreeNode* root = create_pre_order(nums.data(), nums.size());
    auto res = s.levelOrderBottom(root);
    std::vector<std::vector<int>> wanted{std::vector<int>{15, 7}, std::vector<int>{9, 20}, std::vector<int>{3}};
    EXPECT_THAT(res, VectorContentMatcher(wanted));
    delete_postorder(root);
}
