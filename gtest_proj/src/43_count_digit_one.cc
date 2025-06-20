#include <gmock/gmock.h>
#include <gtest/gtest.h>

// https://leetcode.cn/problems/number-of-digit-one/
// 题目：输入一个整数 n，求 1~n 这 n 个整数的十进制表示中 1 出现的次数。
// 参考k神的思路或类比自行车密码锁。
// 2304 十位 1 的次数：0010 - 2219，相当于把十位的 1 固定住，看其他拨片可能的情况，229 - 000 + 1 = 230 = 23 * 10
// 2314 十位 1 的次数：0010 - 2314，相当于把十位的 1 固定住，看其他拨片可能的情况，234 - 000 + 1 = 235 = 23 * 10 + 1 + 4
// 2324 十位 1 的次数：0010 - 2319，相当于把十位的 1 固定住，看其他拨片可能的情况，239 - 000 + 1 = 240 = (23 + 1) * 10
//
// 13 个位 1 的次数：01 - 11，1 - 0 + 1 = 2 = (1 + 1) * 1 = 2
// 13 十位 1 的次数：10 - 13，3 - 0 + 1 = 4 = 1 + 3，此时 high 部分为 0
// 所以 1-13 出现 1 的次数为 6
class Solution43 {
public:
    int countDigitOne(int n) {
        if (n <= 0) {
            return 0;
        }

        int64_t res = 0;
        int64_t cur = n % 10;
        int64_t digit = 1;
        int64_t low = 0;
        int64_t high = n / 10;
        while (high != 0 || cur != 0) {
            if (cur == 0) {
                res += high * digit;
            } else if (cur == 1) {
                res += high * digit + 1 + low;
            } else {
                res += (high + 1) * digit;
            }
            low += cur * digit;
            digit *= 10;
            cur = high % 10;
            high /= 10;
        }

        return res;
    }
};

TEST(ut_43, countDigitOne) {
    Solution43 s;

    EXPECT_EQ(s.countDigitOne(13), 6);
    EXPECT_EQ(s.countDigitOne(1000000000), 900000001);
}
