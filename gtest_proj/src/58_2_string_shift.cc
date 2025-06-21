#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "./matchers.h"

// https://leetcode.cn/problems/perform-string-shifts/description/
// 题目：给定一个包含小写英文字母的字符串 s 以及一个矩阵 shift，其中 shift[i] = [direction, amount]：
// direction 可以为 0 （表示左移）或 1 （表示右移）。
// amount 表示 s 左右移的位数。
// 左移 1 位表示移除 s 的第一个字符，并将该字符插入到 s 的结尾。
// 类似地，右移 1 位表示移除 s 的最后一个字符，并将该字符插入到 s 的开头。
// 对这个字符串进行所有操作后，返回最终结果。
// 思路：先整体处理左右移最终的结果是左移多少。
class Solution58_2 {
public:
    std::string stringShift(std::string s, const std::vector<std::vector<int>>& shift) {
        if (s.empty()) {
            return "";
        }

        const size_t n = s.length();
        int left_rotate = 0;
        for (const auto& v : shift) {
            if (v.size() < 2) {
                return "";
            }
            left_rotate += (v[0] == 0 ? v[1] : -v[1]);
        }
        if (left_rotate < 0) {
            int tmp = -left_rotate;
            if (tmp % n == 0) {
                left_rotate = 0;
            } else {
                int times = tmp / n + 1;
                left_rotate += times * n;
            }
        } else {
            left_rotate %= n;
        }

        if (left_rotate > 1) {
            reverse(s, 0, left_rotate - 1);
        }
        if (n - left_rotate > 1) {
            reverse(s, left_rotate, n - 1);
        }
        reverse(s, 0, n - 1);

        return s;
    }

private:
    void reverse(std::string& s, int i, int j) {
        while (i < j) {
            int tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            ++i;
            --j;
        }
    }
};

TEST(ut_58_2, tn_58_2) {
    Solution58_2 s;

    std::string str("abc");
    EXPECT_THAT(s.stringShift(str, std::vector<std::vector<int>>{std::vector<int>{0, 1}, std::vector<int>{0, 1}}),
                StrEq("cab"));
}
