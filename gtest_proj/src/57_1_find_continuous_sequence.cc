#include <gmock/gmock.h>
#include <gtest/gtest.h>

// 题目：和为 s 的连续整数序列。
// 输入一个整数 s，打印出所有和为 s 的连续整数序列（至少含有两个数）。例如，输入 15，由于 1+2+3+4+5=4+5+6=7+8=15，所以
// 打印出 3 个连续序列 1~5、4~6 和 7~8。
class Solution57_1 {
public:
    int findContinuousSequence(int n) {
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

        return count;
    }

private:
    int sum_range(int64_t small, int64_t big) {
        return ((big - small + 1) * (small + big)) >> 1;
    }
};

TEST(ut_57_1, findContinuousSequence) {
    Solution57_1 s;

    EXPECT_EQ(s.findContinuousSequence(15), 3);
    EXPECT_EQ(s.findContinuousSequence(100), 2);
    EXPECT_EQ(s.findContinuousSequence(1000), 3);
}
