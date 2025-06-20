#include <gmock/gmock.h>
#include <gtest/gtest.h>

// https://leetcode.cn/problems/nth-digit/description/
// 题目：给你一个整数 n，请你在无限的整数序列 [1, 2, 3, 4 ...] 中找出并返回第 n 位上的数字。
// 例如 n = 3，输出 3。
// 这道题和剑指 offer 上的类似，只是形式更规整。
class Solution44_1 {
public:
    int findNthDigit(int index) {
        if (index < 0) {
            return -1;
        }
        int num = index;
        int digit = 1;
        while (true) {
            int64_t dc = get_digit_chars(digit);
            if (num <= dc) {
                break;
            }
            num -= dc;
            ++digit;
        }
        int64_t nums = num / digit;
        int64_t remain = num % digit;
        int64_t x = get_digit_start_num(digit) + nums - 1 + (remain != 0 ? 1 : 0);
        if (remain == 0) {
            return x % 10;
        }
        int shift = digit - remain;
        while (shift > 0) {
            x /= 10;
            --shift;
        }

        return x % 10;
    }

private:
    int64_t get_digit_start_num(int digit) {
        return std::pow(10, digit - 1);
    }

    int64_t get_digit_chars(int digit) {
        int64_t nums = 9 * std::pow(10, digit - 1);

        return nums * digit;
    }
};

TEST(ut_44_1, findNthDigit) {
    Solution44_1 s;

    EXPECT_EQ(s.findNthDigit(3), 3);
    EXPECT_EQ(s.findNthDigit(11), 0);
}
