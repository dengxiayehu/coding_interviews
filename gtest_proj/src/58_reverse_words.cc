#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

#include "./matchers.h"

// https://leetcode.cn/problems/reverse-words-in-a-string/description/
// 题目：给你一个字符串，请你反转字符串中单词的顺序。
// 单词是由非空格字符组成的字符串。s 中至少使用一个空格将字符串中的单词分隔开。
// 返回单词顺序颠倒且单词之间用单个空格连接的结果字符串。
// 注意：输入字符串 s 中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应仅用单个空格分隔，
// 且不包含任何额外的空格。
class Solution58 {
public:
    std::string reverseWords(const std::string& s) {
        if (s.empty()) {
            return s;
        }
        const size_t n = s.length();
        int p = 0;
        // 忽略前导空格
        while (p < n && isspace(s[p])) {
            ++p;
        }
        if (p == n) {
            return "";
        }
        std::string res;
        // 找单词并反转放入 res
        while (true) {
            int q = p;
            while (p < n && !isspace(s[p])) {
                ++p;
            }
            // 判断是否需要放单词之间的空格
            if (!res.empty()) {
                res.push_back(' ');
            }
            // [q, p - 1] 是一个单词，倒序放入 res 里
            for (int i = p - 1; i >= q; i--) {
                res.push_back(s[i]);
            }
            while (p < n && isspace(s[p])) {
                ++p;
            }
            if (p == n) {
                break;
            }
        }
        std::reverse(res.begin(), res.end());

        return res;
    }

    std::string reverseWordsInPlace(std::string& s) {
        if (s.empty()) {
            return s;
        }
        const size_t n = s.length();
        int p = 0;
        // 忽略前导空格
        while (p < n && isspace(s[p])) {
            ++p;
        }
        if (p == n) {
            return "";
        }

        // 忽略后置空格
        int q = n - 1;
        while (q > p && isspace(s[q])) {
            --q;
        }
        // [p, q] 是句子主体部分

        int k = 0;
        while (p <= q) {
            int word_start = p;
            while (p <= q && !isspace(s[p])) {
                ++p;
            }

            // 放入单词之间的分隔符
            if (k != 0) {
                s[k++] = ' ';
            }

            // [word_start, p - 1] 是一个单词，放到 s[k] 开始的位置
            int k_start = k;
            for (int i = word_start; i <= p - 1; ++i) {
                s[k++] = s[i];
            }
            // 倒置这个单词
            for (int i = k_start, j = k - 1; i < j; ++i, --j) {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }

            while (p <= q && isspace(s[p])) {
                ++p;
            }
        }
        // 删除 s[k] 以及之后的所有内容
        s.erase(k);
        std::reverse(s.begin(), s.end());

        return s;
    }
};

TEST(ut_58, reverseWords) {
    Solution58 s;

    EXPECT_THAT(s.reverseWords("the sky is blue"), StrEq("blue is sky the"));
    EXPECT_THAT(s.reverseWords("ab  cd"), StrEq("cd ab"));
    EXPECT_THAT(s.reverseWords("  ab  cd  "), StrEq("cd ab"));
}

TEST(ut_58, reverseWordsInPlace) {
    Solution58 s;

    {
        std::string str("the sky is blue");
        EXPECT_THAT(s.reverseWordsInPlace(str), StrEq("blue is sky the"));
    }

    {
        std::string str("ab  cd");
        EXPECT_THAT(s.reverseWordsInPlace(str), StrEq("cd ab"));
    }

    {
        std::string str("  ab  cd  ");
        EXPECT_THAT(s.reverseWordsInPlace(str), StrEq("cd ab"));
    }
}
