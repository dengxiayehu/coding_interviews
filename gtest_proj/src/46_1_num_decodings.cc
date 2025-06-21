#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

// https://leetcode.cn/problems/decode-ways/
// 题目：一条包含字母 A-Z 的消息通过以下映射进行编码：
// "1" -> "A"
// "2" -> "B"
// ...
// "25" -> "Y"
// "26" -> "Z"
// 然而，在解码已编码的消息时，你意识到有许多不同的方式来解码。因为有些编码被包含在其他编码当中（"2" 和 "5" 与 "25"）。
// 给你一个只含数字的非空字符串 s，请计算并返回解码的方法的总数。如果没有合法的方式解码整个字符串，返回 0。
// 题目数据保证答案肯定是一个 32 位的整数。
class Solution46_1 {
public:
    int numDecodings(const std::string& s) {
        if (s[0] == '0') {
            // 首个字符就是 0，肯定无法解码
            return 0;
        }

        const size_t n = s.length();
        std::vector<int> dp(n + 1);
        dp[0] = 1;  // dp[0] 可以根据实际情况反推出来，例如 "20" 时 dp[2] = dp[0] = 1，"12" 时 dp[2] = dp[1] + dp[0] = 2
        dp[1] = 1;  // dp[1] = 1 好理解
        // 计算 dp[i]，表示 s[i - 1] 结尾的情况，如此到最后时 dp[n] 表示 s[n - 1] 的情况，也就是到达了字符串的结尾
        for (size_t i = 2; i <= n; i++) {
            char si_1 = s[i - 1];
            char si_2 = s[i - 2];
            if (si_1 == '0') {
                if (si_2 != '1' && si_2 != '2') {
                    return 0;
                }
                dp[i] = dp[i - 2];
            } else if (si_2 == '1' || (si_2 == '2' && si_1 >= '1' && si_1 <= '6')) {
                dp[i] = dp[i - 1] + dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        }

        return dp[n];
    }
};

TEST(ut_46_1, numDecodings) {
    Solution46_1 s;

    EXPECT_EQ(s.numDecodings("1"), 1);
    EXPECT_EQ(s.numDecodings("12"), 2);
    EXPECT_EQ(s.numDecodings("10"), 1);
    EXPECT_EQ(s.numDecodings("30"), 0);
}
