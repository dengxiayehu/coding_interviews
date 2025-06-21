#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <string>

// https://leetcode.cn/problems/longest-substring-without-repeating-characters/
// 使用滑动窗口来解决，s[i .. k] 表示以 s[i] 开头的无重复字符的字符串。
class Solution48_1 {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        if (s.empty()) {
            return 0;
        }

        static constexpr int kHashSize = 256;
        int hash[kHashSize] = {0};

        auto exists = [&hash](int ch) { return hash[ch] != 0; };

        auto set = [&hash](int ch) { hash[ch] = 1; };

        auto clear = [&hash](int ch) { hash[ch] = 0; };

        int i = 0;
        int j = s.length() - 1;
        int k = i;
        int res = INT_MIN;
        while (k <= j) {
            while (k <= j && !exists(s[k])) {
                set(s[k]);
                ++k;
            }
            int count = k > j ? j - i + 1 : k - i;
            res = std::max(res, count);
            if (k > j) {
                break;
            }
            clear(s[i]);
            ++i;
        }

        return res;
    }
};

TEST(ut_48_1, lengthOfLongestSubstringSlidingWindow) {
    Solution48_1 s;

    EXPECT_EQ(s.lengthOfLongestSubstring("abcd"), 4);
    EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
    EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
}
