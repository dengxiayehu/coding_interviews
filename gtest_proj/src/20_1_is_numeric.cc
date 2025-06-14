#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

// https://leetcode.cn/problems/valid-number/description/
// 在解决这道题时核心思想是 A[.[B]][e|EC] 或者 .B[e|EC] 的表示规则。
class Solution20_1 {
public:
    bool isNumber(const std::string& s) {
        if (s.empty()) {
            return false;
        }

        const char* p = s.c_str();

        return is_numeric_internal(p);
    }

private:
    bool is_numeric_internal(const char* p) {
        bool numeric = scan_int(p);
        if (is_dot(p)) {
            p++;
            numeric = scan_uint(p) || numeric;  // 有小数点的话，小数点左右有一侧有数字就行
        }
        if (is_e(p)) {
            p++;
            numeric = scan_int(p) && numeric;
        }

        return numeric && strend(p);
    }

    bool scan_int(const char*& p) {
        if (is_sign(p)) {
            p++;
        }

        return scan_uint(p);
    }

    bool scan_uint(const char*& p) {
        const char* save = p;
        while (is_digit(p)) {
            p++;
        }

        return p > save;
    }

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
};

TEST(ut_20_1, isNumeric) {
    Solution20_1 s;

    EXPECT_TRUE(s.isNumber("0"));
    EXPECT_FALSE(s.isNumber("e"));
    EXPECT_FALSE(s.isNumber("."));
    EXPECT_FALSE(s.isNumber("e9"));
    EXPECT_TRUE(s.isNumber("-1E+3"));
    EXPECT_TRUE(s.isNumber("+.8"));
    EXPECT_FALSE(s.isNumber("+"));
    EXPECT_FALSE(s.isNumber("-1E+1.3"));
}
