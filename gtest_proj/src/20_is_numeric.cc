#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

// https://leetcode.cn/problems/valid-number/description/
// 题目：给定一个字符串 s，返回 s 是否是一个有效数字。
// 一般的，一个有效数字可以用以下的规则之一定义：
// 一个整数（或十进制数）后面跟着一个可选指数
//
// 一个整数（或十进制数）定义为一个可选符号 '-' 或 '+' 后面跟着数字
//
// 1. 数字后面跟着一个小数点 .
// 2. 数字后面跟着一个小数点，再跟着数位
// 3. 一个小数点 . 后面跟着数位
//
// 指数定义为指数符号 'e' 或者 'E'，后面跟着一个整数
//
// 数字定义为一个或多个数位
class Solution20 {
public:
    bool isNumber(const std::string& s) {
        if (s.empty()) {
            return false;
        }

        return false;
    }
};

TEST(ut_20, isNumeric) {
}
