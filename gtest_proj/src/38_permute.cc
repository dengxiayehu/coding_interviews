#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/permutations/
// 题目：给定一个不含重复数字的数组 nums，返回其所有可能的全排列。你可以按任意顺序返回答案。
// 典型的全排列算法。
class Solution38 {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;

        permute_internal(res, nums, 0);

        return res;
    }

private:
    void permute_internal(std::vector<std::vector<int>>& res, std::vector<int>& nums, int idx) {
        const size_t nums_size = nums.size();
        if (idx == nums_size) {
            res.push_back(nums);
            return;
        }

        // 先处理不交换场景
        permute_internal(res, nums, idx + 1);
        // 将当前元素与其后面的每一个元素都交换后再处理
        for (int i = idx + 1; i < nums_size; i++) {
            myswap(nums, idx, i);
            permute_internal(res, nums, idx + 1);
            myswap(nums, idx, i);
        }
    }

    void myswap(std::vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};

MATCHER_P(PermutedMatcher, vi, "") {
    std::vector<std::vector<int>> res = arg;
    for (const auto& v : vi) {
        auto found_it = std::find(res.begin(), res.end(), v);
        if (found_it == res.end()) {
            return false;
        }
        res.erase(found_it);
    }
    EXPECT_TRUE(res.empty());
    return true;
}

TEST(ut_38, permute) {
    Solution38 s;

    std::vector<int> nums{1, 2, 3};
    auto res = s.permute(nums);
    std::vector<std::vector<int>> wanted{std::vector<int>{1, 2, 3}, std::vector<int>{1, 3, 2},
                                         std::vector<int>{2, 1, 3}, std::vector<int>{2, 3, 1},
                                         std::vector<int>{3, 2, 1}, std::vector<int>{3, 1, 2}};
    EXPECT_THAT(res, PermutedMatcher(wanted));
}
