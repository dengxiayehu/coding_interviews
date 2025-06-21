#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

#include "./matchers.h"

// 题目：左旋转字符串。例如输入 "abcdefg" 和数字 2，返回结果为 cdefgab。
class Solution58_1 {
public:
    std::string leftRotateString(std::string& s, int n) {
        const size_t len = s.length();
        if (len == 0 || n <= 0 || n % len == 0) {
            return s;
        }

        n %= len;
        reverse(s, 0, n - 1);
        reverse(s, n, len - 1);
        reverse(s, 0, len - 1);

        return s;
    }

private:
    void reverse(std::string& s, int i, int j) {
        const size_t len = s.length();
        if (i < 0 || i >= len || j < 0 || j >= len || i >= j) {
            return;
        }
        // 倒置 s[i .. j] 区间
        while (i < j) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            ++i;
            --j;
        }
    }
};

TEST(ut_58_1, leftRotateString) {
    Solution58_1 s;

    std::string str("abcdefg");
    EXPECT_THAT(s.leftRotateString(str, 2), StrEq("cdefgab"));
}
