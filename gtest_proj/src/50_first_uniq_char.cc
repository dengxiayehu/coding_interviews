#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <string>

// https://leetcode.cn/problems/first-unique-character-in-a-string/
// 题目：字符串中第一个只出现一次的字符，返回它的索引，如果不存在则返回 -1。
class Solution50 {
public:
    int firstUniqChar(const std::string& s) {
        static constexpr int kNotFound = -1;
        static constexpr int kDuplicated = -2;
        int hash[128];
        for (int i = 0; i < 128; i++) {
            hash[i] = kNotFound;
        }
        const size_t n = s.length();
        for (int i = 0; i < n; i++) {
            int ch = s[i];
            if (hash[ch] == kNotFound) {
                hash[ch] = i;
            } else if (hash[ch] >= 0) {
                hash[ch] = kDuplicated;
            }
        }

        int res = kNotFound;
        for (int i = 0; i < 128; i++) {
            if (hash[i] != kNotFound && hash[i] != kDuplicated) {
                res = res == kNotFound ? hash[i] : std::min(res, hash[i]);
            }
        }

        return res;
    }

    // 题目说明只有小写字母，则 hash 数组大小可以只是 26
    int firstUniqCharOptimize(const std::string& s) {
        // 初始化 hash 数组的默认值均为 0
        int hash[26] = {0};
        const size_t n = s.length();
        for (int i = 1; i <= n; i++) {
            int ch = s[i - 1] - 'a';
            if (hash[ch] == 0) {
                // 首次看到这个字符
                hash[ch] = i;
            } else {
                // 已经找到过这个字符，这个字符不是答案
                hash[ch] = -1;
            }
        }

        int res = -1;
        for (int i = 0; i < 26; i++) {
            if (hash[i] > 0) {
                res = res == -1 ? hash[i] - 1 : std::min(res, hash[i] - 1);
            }
        }

        return res;
    }
};

TEST(ut_50, firstUniqChar) {
    Solution50 s;

    EXPECT_EQ(s.firstUniqChar("abc"), 0);
    EXPECT_EQ(s.firstUniqChar("loveleetcode"), 2);
    EXPECT_EQ(s.firstUniqChar("aabb"), -1);
}

TEST(ut_50, firstUniqCharOptimize) {
    Solution50 s;

    EXPECT_EQ(s.firstUniqCharOptimize("abc"), 0);
    EXPECT_EQ(s.firstUniqCharOptimize("loveleetcode"), 2);
    EXPECT_EQ(s.firstUniqCharOptimize("aabb"), -1);
}
