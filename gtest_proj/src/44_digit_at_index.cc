#include <gmock/gmock.h>
#include <gtest/gtest.h>

// 题目：数字以 012345678910111213... 的格式序列化到一个字符序列中。在这个序列中，第 5 位（从 0 开始计数）是 5。请写一个
// 函数，求任意第 n 位对应的数字。
class Solution44 {
public:
    int digitAtIndex(int index) {
        if (index < 0) {
            return -1;
        }

        int num = index + 1;
        int digit = 1;
        while (true) {
            int dc = get_digit_chars(digit);
            if (num <= dc) {
                break;
            }
            num -= dc;
            ++digit;
        }
        int nums = num / digit;
        int remain = num % digit;
        int x = get_digit_start_num(digit) + nums - 1 + (remain != 0 ? 1 : 0);
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
    int get_digit_start_num(int digit) {
        return digit == 1 ? 0 : std::pow(10, digit - 1);
    }

    int get_digit_chars(int digit) {
        int nums = digit == 1 ? 10 : 9 * std::pow(10, digit - 1);

        return nums * digit;
    }
};

TEST(ut_44, digitAtIndex) {
    Solution44 s;

    EXPECT_EQ(s.digitAtIndex(5), 5);
    EXPECT_EQ(s.digitAtIndex(11), 0);
    EXPECT_EQ(s.digitAtIndex(12), 1);
    EXPECT_EQ(s.digitAtIndex(1), 1);
    EXPECT_EQ(s.digitAtIndex(9), 9);
    EXPECT_EQ(s.digitAtIndex(10), 1);
    EXPECT_EQ(s.digitAtIndex(13), 1);
    EXPECT_EQ(s.digitAtIndex(19), 4);
}
