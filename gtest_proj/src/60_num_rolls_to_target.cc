#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/
// 这里有 n 个一样的骰子，每个骰子上都有 k 个面，分别标号为 1 到 k 。
// 给定三个整数 n、k 和 target，请返回投掷骰子的所有可能的结果（共有 kn 种方式），使得骰子面朝上的数字总和等于 target。
// 由于答案可能很大，你需要对 10^9 + 7 取模。
class Solution60_1 {
private:
    std::vector<std::vector<int>> m_dp = std::vector<std::vector<int>>(31, std::vector<int>(1001, -1));

public:
    int numRollsToTarget(int d, int f, int target) {
        if (target < 0 || target > d * f) {
            return 0;
        }

        if (d == 0) {
            return target == 0 ? 1 : 0;
        }

        if (m_dp[d][target] >= 0) {
            return m_dp[d][target];
        }

        int res = 0;
        for (int i = 1; i <= f; i++) {
            res += numRollsToTarget(d - 1, f, target - i);
            res %= 1000000007;
        }

        m_dp[d][target] = res;

        return res;
    }
};

TEST(ut_60_1, numRollsToTarget) {
    Solution60_1 s;

    EXPECT_EQ(s.numRollsToTarget(30, 30, 500), 222616187);
}
