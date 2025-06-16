#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/spiral-matrix/
// 题目：给你一个 m 行 n 列的矩阵 matrix，请按顺时针螺旋顺序，返回矩阵中所有元素。
// 这道题的难点之一是怎么确定退出条件，数个数的方式是一种“保底”方法（不是最优，但能解决问题:(）。
// 按某种顺序打印二维数组的算法，用 t/b/l/r 这样的界限去框，思维比较清晰。
class Solution29 {
public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        const int m = matrix.size();
        if (m == 0) {
            return res;
        }
        const int n = matrix[0].size();
        if (n == 0) {
            return res;
        }
        int t = 0;
        int b = m - 1;
        int l = 0;
        int r = n - 1;
        while (true) {
            // 上面一行
            for (int j = l; j <= r; j++) {
                res.push_back(matrix[t][j]);
            }
            if (++t > b) {
                break;
            }
            // 右侧一列
            for (int i = t; i <= b; i++) {
                res.push_back(matrix[i][r]);
            }
            if (--r < l) {
                break;
            }
            // 下面一行
            for (int j = r; j >= l; j--) {
                res.push_back(matrix[b][j]);
            }
            if (--b < t) {
                break;
            }
            // 左侧一列
            for (int i = b; i >= t; i--) {
                res.push_back(matrix[i][l]);
            }
            if (++l > r) {
                break;
            }
        }

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

TEST(ut_29, spiralOrder) {
    Solution29 s;

    {
        std::vector<std::vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        auto res = s.spiralOrder(matrix);
        EXPECT_THAT(res, VectorContentMatcher(std::vector<int>{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}));
    }

    {
        std::vector<std::vector<int>> matrix{{2, 5, 8}, {4, 0, -1}};
        auto res = s.spiralOrder(matrix);
        EXPECT_THAT(res, VectorContentMatcher(std::vector<int>{2, 5, 8, -1, 0, 4}));
    }
}
