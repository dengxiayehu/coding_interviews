#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

// 题目：在一个 mxn 的棋盘上的每一格都方有一个礼物，每个礼物都有一定价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里
// 的礼物，并每次向右或向下移动一格，直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计算你最多能拿到多少价值的礼物？
class Solution47 {
public:
    int getMaxValue(const std::vector<std::vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        const size_t m = grid.size();
        const size_t n = grid[0].size();
        std::vector<std::vector<int>> dp(m);
        for (size_t i = 0; i < m; i++) {
            dp[i].resize(n, -1);
        }
        // 状态转移方程：dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        dp[0][0] = grid[0][0];
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i == 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

TEST(ut_47, getMaxValue) {
    Solution47 s;

    EXPECT_EQ(
            s.getMaxValue(std::vector<std::vector<int>>{std::vector<int>{1, 10, 3, 8}, std::vector<int>{12, 2, 9, 6},
                                                        std::vector<int>{5, 7, 4, 11}, std::vector<int>{3, 7, 16, 5}}),
            53);
}
