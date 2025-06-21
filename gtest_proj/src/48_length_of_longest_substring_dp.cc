#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

// https://leetcode.cn/problems/longest-substring-without-repeating-characters/
// 题目：给定一个字符串 s，请你找出其中不含有重复字符的最长子串的长度。
// 若 s[i] 没有出现过， dp[i] = dp[i - 1] + 1
// 若 s[i] 出现过（上一次出现该字符的位置为 j），d = i - j，
// d <= dp[i - 1]，则 dp[i] = d
// d > dp[i - 1]，则 dp[i] = dp[i - 1] + 1
class Solution48 {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        if (s.empty()) {
            return 0;
        }

        static constexpr int kHashSize = 256;
        int hash[kHashSize];
        for (int i = 0; i < kHashSize; ++i) {
            hash[i] = -1;
        }

        int res = 1;
        int n = s.length();
        std::vector<int> dp(n);
        dp[0] = 1;
        int ch = s[0];
        hash[ch] = 0;
        for (int i = 1; i < n; i++) {
            ch = s[i];
            int idx = hash[ch];
            if (idx < 0) {
                dp[i] = dp[i - 1] + 1;
            } else {
                int d = i - idx;
                if (d <= dp[i - 1]) {
                    dp[i] = d;
                } else {
                    dp[i] = dp[i - 1] + 1;
                }
            }
            hash[ch] = i;
            res = std::max(res, dp[i]);
        }

        return res;
    }

    int lengthOfLongestSubstringOptimize(const std::string& s) {
        if (s.empty()) {
            return 0;
        }

        static constexpr int kHashSize = 256;
        int hash[kHashSize];
        for (int i = 0; i < kHashSize; ++i) {
            hash[i] = -1;
        }

        int res = 1;
        int n = s.length();
        int fi_1 = 1;
        int ch = s[0];
        hash[ch] = 0;
        for (int i = 1; i < n; i++) {
            ch = s[i];
            int idx = hash[ch];
            int fi = 0;
            if (idx < 0) {
                fi = fi_1 + 1;
            } else {
                int d = i - idx;
                if (d <= fi_1) {
                    fi = d;
                } else {
                    fi = fi_1 + 1;
                }
            }
            hash[ch] = i;
            res = std::max(res, fi);
            fi_1 = fi;
        }

        return res;
    }
};

TEST(ut_48, lengthOfLongestSubstring) {
    Solution48 s;

    EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
    EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
}

TEST(ut_48, lengthOfLongestSubstringOptimize) {
    Solution48 s;

    EXPECT_EQ(s.lengthOfLongestSubstringOptimize("abcabcbb"), 3);
    EXPECT_EQ(s.lengthOfLongestSubstringOptimize("bbbbb"), 1);
    EXPECT_EQ(s.lengthOfLongestSubstringOptimize("pwwkew"), 3);
}
