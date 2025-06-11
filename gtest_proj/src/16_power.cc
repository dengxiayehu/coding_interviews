#include <gtest/gtest.h>

#include <limits>

// https://leetcode.cn/problems/powx-n/description/
// 题目：实现 pow(x, n)，即计算 x 的 n 次幂函数（即 x^n）。
// 这道题可能存在 exponent 取反后溢出了 int 表示的范围，需要提升数据类型为 int64_t，提升完之后再取反
class Solution16 {
public:
    double myPow(double base, int exponent) {
        // 0^0 没有意义
        if (is_double_zero(base) && exponent == 0) {
            return 0;
        }

        bool negative = exponent < 0;
        int64_t n = exponent;
        if (negative) {
            n = -n;
        }

        // 快速乘方算法
        // 1. a^n = (a * a)^(n/2)，    n 为偶数
        // 2. a^n = (a * a)^(n/2) * a，n 为奇数
        double res = mypow_fast(base, n);

        if (negative) {
            // 1/0 错误
            if (is_double_zero(res)) {
                return 0;
            }
            res = 1 / res;
        }

        return res;
    }

private:
    bool is_double_zero(double d) {
        return std::abs(d) < std::numeric_limits<double>::epsilon();
    }

    // n 若为 11，转换为二进制就是 1011。也就是 a^11 = a^8 * a^2 * a^1
    double mypow_fast(double a, int64_t n) {
        double res = 1.0;
        while (n > 0) {
            if ((n & 1) == 1) {  // 判断 n 所表示的二进制的最低一位是否为 1
                res *= a;
            }
            a *= a;  // “测试“二进制位左移
            n >>= 1;
        }

        return res;
    }

    double mypow(double a, int64_t n) {
        if (n == 0) {
            return 1;
        }

        if ((n & 1) == 1) {
            return mypow(a * a, n >> 1) * a;
        }
        return mypow(a * a, n >> 1);
    }
};

TEST(ut_16, power) {
    Solution16 s;

    EXPECT_FLOAT_EQ(s.myPow(2.00000, 1), 2.00000);
    EXPECT_FLOAT_EQ(s.myPow(2.00000, 2), 4.00000);
    EXPECT_FLOAT_EQ(s.myPow(2.00000, 3), 8.00000);
    EXPECT_FLOAT_EQ(s.myPow(2.00000, 10), 1024.00000);
    EXPECT_FLOAT_EQ(s.myPow(1.00000, -2147483648), 1.00000);
}
