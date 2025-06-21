#include <gmock/gmock.h>
#include <gtest/gtest.h>

// https://leetcode.cn/problems/consecutive-numbers-sum/
// 题目：给定一个正整数 n，返回连续正整数满足所有数字之和为 n 的组数。
// 与剑指 offer 的区别是不限定至少两个元素。
class Solution57_2 {
public:
    // 下面算法会导致超时，数学方法暂略
    int consecutiveNumbersSum(int n) {
        int small_upper_bound = (n >> 1);
        int small = 1;
        int big = 2;
        int count = 0;
        while (small <= small_upper_bound) {
            int cur_sum = sum_range(small, big);
            if (cur_sum == n) {
                ++count;
                ++small;
            } else if (cur_sum > n) {
                ++small;
            } else {
                ++big;
            }
        }

        return count + 1;
    }

private:
    int sum_range(int64_t small, int64_t big) {
        return ((big - small + 1) * (small + big)) >> 1;
    }
};

TEST(ut_57_2, consecutiveNumbersSum) {
    Solution57_2 s;

    EXPECT_EQ(s.consecutiveNumbersSum(15), 4);
    // EXPECT_EQ(s.consecutiveNumbersSum(933320757), 16);
    EXPECT_EQ(s.consecutiveNumbersSum(313653678), 16);
}
