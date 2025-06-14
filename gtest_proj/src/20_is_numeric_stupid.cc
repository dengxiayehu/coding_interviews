#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

// https://leetcode.cn/problems/valid-number/description/
// 题目：给定一个字符串 s，返回 s 是否是一个有效数字。
// 一般的，一个有效数字可以用以下的规则之一定义：
// 1. 一个整数（或十进制数）后面跟着一个可选指数
// 一个整数（十进制数）定义为一个可选符号 '-' 或 '+' 后面可选跟着数字；
// 一个十进制数后面跟着如下规则：
// 1. 数字后面跟着一个小数点 .
// 2. 数字后面跟着一个小数点，再跟着数位
// 3. 一个小数点 . 后面跟着数位
// 指数定义为指数符号 'e' 或者 'E'，后面跟着一个整数，前面必须是一个合法十进制数；
// 数字定义为一个或多个数位；
//
// 在解决这道题时核心思想是 A[.[B]][e|EC] 或者 .B[e|EC] 的表示规则。
class Solution20 {
public:
    bool isNumber(const std::string& s) {
        if (s.empty()) {
            return false;
        }

        const char* p = s.c_str();

        return is_number(p);
    }

private:
    bool is_sign(const char* p) {
        return *p == '+' || *p == '-';
    }

    bool is_digit(const char* p) {
        return *p >= '0' && *p <= '9';
    }

    bool is_dot(const char* p) {
        return *p == '.';
    }

    bool is_e(const char* p) {
        return *p == 'E' || *p == 'e';
    }

    bool strend(const char* p) {
        return *p == '\0';
    }

    bool is_number(const char*& p) {
        bool digit_found = false;
        // 检查一开始的符号
        if (is_sign(p)) {
            if (!strend(p) && is_sign(p + 1)) {
                return false;
            }
            p++;
        }
        while (is_digit(p)) {
            digit_found = true;
            p++;
        }

        if (is_dot(p)) {
            p++;
            while (is_digit(p)) {
                digit_found = true;
                p++;
            }
            // 有小数点的话必须包含一个数字
            if (!digit_found) {
                return false;
            }
        }
        // 不能出现两个小数点
        if (is_dot(p)) {
            return false;
        }
        // 这里一个拦截点，必须有一个数字才行，例如用例 "+"，只有一个符号没有数字
        if (digit_found && strend(p)) {
            return true;
        }

        if (is_e(p)) {
            p++;
            // e|E 的前面必须有数字
            if (!digit_found) {
                return false;
            }
            digit_found = false;
            if (is_sign(p)) {
                if (!strend(p) && is_sign(p + 1)) {
                    return false;
                }
                p++;
            }
            while (is_digit(p)) {
                digit_found = true;
                p++;
            }
            // e|E 的后面也必须有数字
            if (!digit_found) {
                return false;
            }
            if (strend(p)) {
                return true;
            }
        }

        return false;
    }
};

TEST(ut_20, isNumericStupid) {
    Solution20 s;

    EXPECT_TRUE(s.isNumber("0"));
    EXPECT_FALSE(s.isNumber("e"));
    EXPECT_FALSE(s.isNumber("."));
    EXPECT_FALSE(s.isNumber("e9"));
    EXPECT_TRUE(s.isNumber("-1E+3"));
    EXPECT_TRUE(s.isNumber("+.8"));
    EXPECT_FALSE(s.isNumber("+"));
    EXPECT_FALSE(s.isNumber("-1E+1.3"));
}
