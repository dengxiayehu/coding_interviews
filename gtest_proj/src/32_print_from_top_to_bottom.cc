#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "tree_util.h"

// 题目：不分行从上到下打印二叉树，同一层的节点按照从左到右的顺序打印。
class Solution32 {
public:
    std::vector<int> levelOrderTop(TreeNode* root) {
        std::vector<int> res;

        return res;
    }
};

MATCHER_P(VectorContentMatcher, vi, "") {
    const std::vector<int>& v = arg;
    size_t vi_size = vi.size();
    size_t v_size = v.size();
    if (vi_size != v_size) {
        return false;
    }
    for (size_t i = 0; i < vi_size; i++) {
        if (vi[i] != vi[i]) {
            return false;
        }
    }

    return true;
}

TEST(ut_32, tn_32) {
    Solution32 s;

    std::vector<int> nums{3, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    TreeNode* root = create_pre_order(nums.data(), nums.size());
    auto res = s.levelOrderTop(root);
    EXPECT_THAT(res, VectorContentMatcher(std::vector<int>{3, 9, 20, 15, 7}));
    delete_postorder(root);
}
