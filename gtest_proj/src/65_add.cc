#include <gmock/gmock.h>
#include <gtest/gtest.h>

// 题目：写一个函数，求两个整数之和，要求在函数体内不能使用 + - * / 四则运算符号。
class Solution65 {
public:
    int add(int num1, int num2) {
        int sum = 0;
        int carry = 0;

        do {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;

            num1 = sum;
            num2 = carry;
        } while (num2 != 0);

        return num1;
    }
};

TEST(ut_65, add) {
    Solution65 s;

    EXPECT_EQ(s.add(2, 3), 5);
}
