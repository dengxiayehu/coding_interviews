#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

// 题目：给定一个数字，我们按照如下规则把它翻译为字符串：
// 0 -> 'a'
// 1 -> 'b'
// ...
// 25 -> 'z'
// 一个数字有多种翻译。请实现一个函数，用来计算一个数字有多少种不同的翻译方法。
// 遇到求多少种情况的，通常可以往动态规划上面去想。
class Solution46 {
public:
    int getTranslationCount(int number) {
        if (number < 0) {
            return 0;
        }

        std::string number_str = std::to_string(number);
        const size_t n = number_str.length();
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (size_t i = 2; i <= n; i++) {
            char si_1 = number_str[i - 1];
            char si_2 = number_str[i - 2];
            if (si_2 == '0') {
                // 0x 是非法组合，所以 dp[i] 只与 dp[i - 1] 相关
                // 与下面 else 逻辑可以合并，为便于理解，先不动
                dp[i] = dp[i - 1];
            } else if (si_2 == '1' || (si_2 == '2' && (si_1 >= '0' && si_1 <= '5'))) {
                dp[i] = dp[i - 2] + dp[i - 1];
            } else {
                dp[i] = dp[i - 1];
            }
        }

        return dp[n];
    }
};

TEST(ut_46, getTranslationCount) {
    Solution46 s;

    EXPECT_EQ(s.getTranslationCount(12258), 5);
    EXPECT_EQ(s.getTranslationCount(0), 1);
    EXPECT_EQ(s.getTranslationCount(10), 2);
    EXPECT_EQ(s.getTranslationCount(100), 2);
}
