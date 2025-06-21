#include <gmock/gmock.h>
#include <gtest/gtest.h>

// https://leetcode.cn/problems/ugly-number-ii/description/
// 题目：我们把只包含因子 2、3 和 5 的数称作丑数。给你一个整数 n，请你找出并返回 n 个丑数。
// 从检测丑数变成如何按顺序生成丑数。
class Solution49 {
public:
    int nthUglyNumber(int n) {
        int* dp = new int[n + 1];
        dp[1] = 1;
        int n2 = 1;
        int n3 = 1;
        int n5 = 1;
        for (int i = 2; i <= n; ++i) {
            int multi2 = dp[n2] * 2;
            int multi3 = dp[n3] * 3;
            int multi5 = dp[n5] * 5;
            int min = min3(multi2, multi3, multi5);
            dp[i] = min;
            if (min == multi2) {
                ++n2;
            }
            if (min == multi3) {
                ++n3;
            }
            if (min == multi5) {
                ++n5;
            }
        }

        int res = dp[n];
        delete[] dp;

        return res;
    }

private:
    int min3(int a, int b, int c) {
        int min = a < b ? a : b;
        min = min < c ? min : c;

        return min;
    }
};

TEST(ut_49, nthUglyNumber) {
    Solution49 s;

    EXPECT_EQ(s.nthUglyNumber(10), 12);
    EXPECT_EQ(s.nthUglyNumber(1), 1);
}
