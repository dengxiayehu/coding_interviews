#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

// https://leetcode.cn/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/
// 题目：请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号数。
class Solution67 {
public:
    int myAtoi(const std::string& str) {
        const size_t n = str.length();
        int idx = 0;
        while (idx < n && isspace(str[idx])) {
            ++idx;
        }
        if (idx == n) {
            return 0;
        }

        bool negative = false;
        if (str[idx] == '+' || str[idx] == '-') {
            if (str[idx] == '-') {
                negative = true;
            }
            idx++;
            if (idx == n) {
                return 0;
            }
        }

        int num = 0;
        while (idx < n && isdigit(str[idx])) {
            int cur_digit = str[idx] - '0';
            if (negative) {
                if (num > INT_MAX / 10 || (num == INT_MAX / 10 && cur_digit >= 8)) {
                    return INT_MIN;
                }
            } else {
                if (num > INT_MAX / 10 || (num == INT_MAX / 10 && cur_digit >= 7)) {
                    return INT_MAX;
                }
            }
            num *= 10;
            num += cur_digit;
            ++idx;
        }

        return negative ? -num : num;
    }
};

TEST(ut_67, myAtoi) {
    Solution67 s;

    EXPECT_EQ(s.myAtoi(""), 0);
    EXPECT_EQ(s.myAtoi(" "), 0);
    EXPECT_EQ(s.myAtoi("  "), 0);
    EXPECT_EQ(s.myAtoi("42"), 42);
    EXPECT_EQ(s.myAtoi("+123"), 123);
    EXPECT_EQ(s.myAtoi("-123"), -123);
    EXPECT_EQ(s.myAtoi("1a33"), 1);
    EXPECT_EQ(s.myAtoi("-2147483648"), -2147483648);
    EXPECT_EQ(s.myAtoi("-2147483649"), -2147483648);
    EXPECT_EQ(s.myAtoi("+2147483647"), 2147483647);
    EXPECT_EQ(s.myAtoi("+2147483648"), 2147483647);
}
