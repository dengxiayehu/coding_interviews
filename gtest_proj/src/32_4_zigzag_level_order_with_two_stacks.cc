#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <stack>
#include <vector>

#include "tree_util.h"

// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
class Solution32_4 {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        std::vector<int> lv;
        std::stack<TreeNode*> st[2];
        st[0].push(root);  // st[0] 处理顺序打印情况，st[1] 处理逆序打印情况
        int idx = 0;
        int cur_lvl = 1;
        int next_lvl = 0;
        while (!st[idx].empty()) {
            TreeNode* node = st[idx].top();
            st[idx].pop();

            lv.push_back(node->val);

            if (idx == 0) {
                if (node->left != nullptr) {
                    st[1 - idx].push(node->left);
                    ++next_lvl;
                }
                if (node->right != nullptr) {
                    st[1 - idx].push(node->right);
                    ++next_lvl;
                }
            } else {
                if (node->right != nullptr) {
                    st[1 - idx].push(node->right);
                    ++next_lvl;
                }
                if (node->left != nullptr) {
                    st[1 - idx].push(node->left);
                    ++next_lvl;
                }
            }

            if (--cur_lvl == 0) {
                cur_lvl = next_lvl;
                next_lvl = 0;
                idx = 1 - idx;
                res.push_back(lv);
                lv.clear();
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

TEST(ut_32_4, levelOrder) {
    Solution32_4 s;

    {
        std::vector<int> nums{1, 2, 4,  8,  -1, -1, 9,  -1, -1, 5,  10, -1, -1, 11, -1, -1,
                              3, 6, 12, -1, -1, 13, -1, -1, 7,  14, -1, -1, 15, -1, -1};
        TreeNode* root = create_pre_order(nums.data(), nums.size());
        auto res = s.zigzagLevelOrder(root);
        std::vector<std::vector<int>> wanted{std::vector<int>{1}, std::vector<int>{3, 2}, std::vector<int>{4, 5, 6, 7},
                                             std::vector<int>{15, 14, 13, 12, 11, 10, 9, 8}};
        EXPECT_THAT(res, VectorContentMatcher(wanted));
        delete_postorder(root);
    }

    {
        std::vector<int> nums{3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
        TreeNode* root = create_pre_order(nums.data(), nums.size());
        auto res = s.zigzagLevelOrder(root);
        std::vector<std::vector<int>> wanted{std::vector<int>{3}, std::vector<int>{20, 9}, std::vector<int>{15, 7}};
        EXPECT_THAT(res, VectorContentMatcher(wanted));
        delete_postorder(root);
    }
}
