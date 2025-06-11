#include <gtest/gtest.h>

#include <vector>

// 题目：地上有一个 m 行 n 列的方格。一个机器人从坐标 (0, 0)
// 的格子开始移动，它每次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和大于 k
// 的格子。请问该机器人能够到达多少个格子？
class Solution13 {
public:
    int movingCount(int threshold, int rows, int cols) {
        if (rows <= 0 || cols <= 0 || threshold < 0) {
            return 0;
        }

        std::vector<std::vector<bool>> flag(rows);
        for (int i = 0; i < rows; i++) {
            flag[i].resize(cols);
        }

        return moving_count_internal(threshold, rows, cols, &flag, 0, 0);
    }

private:
    int moving_count_internal(const int threshold, const int rows, const int cols, std::vector<std::vector<bool>>* flag,
                              int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            return 0;
        }

        if ((*flag)[i][j]) {
            return 0;
        }

        if (get_digits_sum(i) + get_digits_sum(j) > threshold) {
            return 0;
        }

        (*flag)[i][j] = true;

        int res = 1;  // 当前格子算 1 个
        res += moving_count_internal(threshold, rows, cols, flag, i + 1, j);
        res += moving_count_internal(threshold, rows, cols, flag, i - 1, j);
        res += moving_count_internal(threshold, rows, cols, flag, i, j + 1);
        res += moving_count_internal(threshold, rows, cols, flag, i, j - 1);

        // 走过的格子不能重复计数了
        // (*flag)[i][j] = false;

        return res;
    }

    int get_digits_sum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }
};

TEST(ut_13, movingCount) {
    Solution13 s;

    EXPECT_EQ(s.movingCount(1, 2, 2), 3);
    EXPECT_EQ(s.movingCount(2, 3, 3), 6);
    EXPECT_EQ(s.movingCount(4, 6, 6), 15);
}
