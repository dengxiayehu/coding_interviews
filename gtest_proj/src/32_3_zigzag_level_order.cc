#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <queue>
#include <stack>
#include <vector>

#include "tree_util.h"

// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
// 题目：请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照
// 从左到右打印，其他以此类推。
// 过程中最好不出现 reverse 操作，用 queue + stack 实现，本质上相对两个 stack 的算法不是最优。
class Solution32_3 {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        bool forward = true;
        std::queue<TreeNode*> q;
        q.push(root);
        int cur_lvl = 1;
        int next_lvl = 0;
        TreeNode* node = nullptr;
        std::vector<int> lv;
        std::stack<int> st;
        while (!q.empty()) {
            node = q.front();
            q.pop();

            if (forward) {
                lv.push_back(node->val);
            } else {
                st.push(node->val);
            }

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
                if (!forward) {
                    while (!st.empty()) {
                        lv.push_back(st.top());
                        st.pop();
                    }
                }
                res.push_back(lv);
                lv.clear();
                forward = !forward;
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

TEST(ut_32_3, zigzagLevelOrder) {
    Solution32_3 s;

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
