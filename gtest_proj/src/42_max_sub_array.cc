#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

// https://leetcode.cn/problems/maximum-subarray/description/
// 题目：输入一个整型数组，数组里有整数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
// 典型的动态规划算法：max[m, n] = max(max[m, n - 1] + nums[n], nums[1])
class Solution42 {
public:
    int maxSubArray(const std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        const size_t nums_size = nums.size();
        int res = nums[0];
        int max = res;
        for (size_t i = 1; i < nums_size; i++) {
            res = std::max(res + nums[i], nums[i]);
            if (res > max) {
                max = res;
            }
        }

        return max;
    }
};

TEST(ut_42, maxSubArray) {
    Solution42 s;

    EXPECT_EQ(s.maxSubArray(std::vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 5}), 6);
    EXPECT_EQ(s.maxSubArray(std::vector<int>{1}), 1);
    EXPECT_EQ(s.maxSubArray(std::vector<int>{5, 4, -1, 7, 8}), 23);
    EXPECT_EQ(s.maxSubArray(std::vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6);
    EXPECT_EQ(s.maxSubArray(std::vector<int>{-2, -1, -3, -4, -1, -2}), -1);
}
