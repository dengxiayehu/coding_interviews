#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

// https://leetcode.cn/problems/minimum-path-sum/
// dp 算法是比较高效的，一般求极大值（极小值）要首先想到 dp
class Solution47_2 {
public:
    int minPathSum(const std::vector<std::vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        const size_t m = grid.size();
        const size_t n = grid[0].size();
        // 新申请一个 mxn 数组用于 dp 算法，也可以复用 grid 的空间，具体可以问一下面试官
        std::vector<std::vector<int>> dp(m);
        for (size_t i = 0; i < m; i++) {
            dp[i].resize(n, -1);
        }
        // 状态转移方程：dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
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
                    dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

TEST(ut_47_2, minPathSumDP) {
    Solution47_2 s;

    EXPECT_EQ(s.minPathSum(std::vector<std::vector<int>>{std::vector<int>{1, 3, 1}, std::vector<int>{1, 5, 1},
                                                         std::vector<int>{4, 2, 1}}),
              7);

    EXPECT_EQ(s.minPathSum(std::vector<std::vector<int>>{std::vector<int>{1, 2, 3}, std::vector<int>{4, 5, 6}}), 12);

    EXPECT_EQ(s.minPathSum(std::vector<std::vector<int>>{std::vector<int>{1, 2}, std::vector<int>{3, 4}}), 7);

    std::vector<std::vector<int>> grid = {std::vector<int>{5, 0, 1, 1, 2, 1, 0, 1, 3, 6, 3, 0, 7, 3, 3, 3, 1},
                                          std::vector<int>{1, 4, 1, 8, 5, 5, 5, 6, 8, 7, 0, 4, 3, 9, 9, 6, 0},
                                          std::vector<int>{2, 8, 3, 3, 1, 6, 1, 4, 9, 0, 9, 2, 3, 3, 3, 8, 4},
                                          std::vector<int>{3, 5, 1, 9, 3, 0, 8, 3, 4, 3, 4, 6, 9, 6, 8, 9, 9},
                                          std::vector<int>{3, 0, 7, 4, 6, 6, 4, 6, 8, 8, 9, 3, 8, 3, 9, 3, 4},
                                          std::vector<int>{8, 8, 6, 8, 3, 3, 1, 7, 9, 3, 3, 9, 2, 4, 3, 5, 1},
                                          std::vector<int>{7, 1, 0, 4, 7, 8, 4, 6, 4, 2, 1, 3, 7, 8, 3, 5, 4},
                                          std::vector<int>{3, 0, 9, 6, 7, 8, 9, 2, 0, 4, 6, 3, 9, 7, 2, 0, 7},
                                          std::vector<int>{8, 0, 8, 2, 6, 4, 4, 0, 9, 3, 8, 4, 0, 4, 7, 0, 4},
                                          std::vector<int>{3, 7, 4, 5, 9, 4, 9, 7, 9, 8, 7, 4, 0, 4, 2, 0, 4},
                                          std::vector<int>{5, 9, 0, 1, 9, 1, 5, 9, 5, 5, 3, 4, 6, 9, 8, 5, 6},
                                          std::vector<int>{5, 7, 2, 4, 4, 4, 2, 1, 8, 4, 8, 0, 5, 4, 7, 4, 7},
                                          std::vector<int>{9, 5, 8, 6, 4, 4, 3, 9, 8, 1, 1, 8, 7, 7, 3, 6, 9},
                                          std::vector<int>{7, 2, 3, 1, 6, 3, 6, 6, 6, 3, 2, 3, 9, 9, 4, 4, 8}};
    EXPECT_EQ(s.minPathSum(grid), 83);
}
