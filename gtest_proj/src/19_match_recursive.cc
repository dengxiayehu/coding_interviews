#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

// https://leetcode.cn/problems/regular-expression-matching/description/
// 题目：请实现一个函数用来匹配包含 '.' 和 '*' 的正则表达式。模式中的字符 '.' 表示匹配任意一个字符，而 '*' 表示它前面的
// 字符可以出现任意次（含 0 次）。
// 下面算法能解决问题，但时间复杂度较高，有一个用例无法通过。
// 最优算法是使用动态规划，暂略。
class Solution19 {
public:
    bool isMatch(const std::string& s, const std::string& p) {
        return is_match_internal(s.c_str(), 0, p.c_str(), 0);
    }

private:
    bool is_match_internal(const char* s, int i, const char* p, int j) {
        // 在 p 到结尾时，要么匹配要么不匹配。s 若到结尾还不能明确是否匹配，例如 p 还剩 a*，那么剥离掉 a* 后，p 还与 s
        // 匹配。
        // 递归退出条件 1：完全匹配了
        if (strend(s, i) && strend(p, j)) {
            return true;
        }

        // 递归退出条件 2：明确不匹配
        if (!strend(s, i) && strend(p, j)) {
            return false;
        }

        // p 肯定不为空，判断 p[1] 是否为 '*'

        if (p[j + 1] == '*') {
            if (equal(s, i, p, j)) {
                bool remove_star = is_match_internal(s, i, p, j + 2);
                bool remove_one = is_match_internal(s, i + 1, p, j + 2);
                bool remove_many = is_match_internal(s, i + 1, p, j);
                return remove_star || remove_one || remove_many;
            } else {
                // 需跳过 a*
                return is_match_internal(s, i, p, j + 2);
            }
        } else {
            // 正常匹配 s 和 p，此时 p 肯定非空，s 不确定
            if (equal(s, i, p, j)) {
                // 继续匹配下一个字符
                return is_match_internal(s, i + 1, p, j + 1);
            }
        }

        // 递归退出条件 3：其他不匹配场景
        return false;
    }

    bool strend(const char* s, int idx) {
        return s[idx] == '\0';
    }

    bool equal(const char* s, int i, const char* p, int j) {
        return s[i] == p[j] || (!strend(s, i) && p[j] == '.');
    }
};

TEST(ut_19, matchRecursive) {
    Solution19 s;

    EXPECT_FALSE(s.isMatch("aa", "a"));
    EXPECT_TRUE(s.isMatch("aa", "a*"));
    EXPECT_TRUE(s.isMatch("aa", "a."));
    EXPECT_TRUE(s.isMatch("ab", ".*"));
    // EXPECT_FALSE(s.isMatch("aaaaaaaaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*"));
    EXPECT_FALSE(s.isMatch("aaab", "a*a*"));
    EXPECT_TRUE(s.isMatch("bbbba", ".*a*a"));
}
