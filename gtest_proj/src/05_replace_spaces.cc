#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

#include "./matchers.h"

// https://leetcode.cn/problems/string-to-url-lcci/description/
class Solution05 {
public:
    // 注意：这里 str 是类似作为字符数组使用，处理完后需 resize 成真实不包含结束标记的大小
    std::string replaceSpaces(std::string& str, int length) {
        if (str.empty() || length <= 0) {
            return str;
        }

        // 统计字符串中空格的个数
        int spaces_num = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') {
                ++spaces_num;
            }
        }
        if (spaces_num == 0) {
            // 没有空格，无需处理
            str.resize(length);
            return str;
        }

        // 计算处理之后的字符串长度，每多一个空格，在原来基础上 +2
        int new_length = length + spaces_num * 2;
        int j = length - 1;
        int z = new_length - 1;
        while (j >= 0) {
            if (str[j] != ' ') {
                str[z--] = str[j--];
            } else {
                str[z--] = '0';
                str[z--] = '2';
                str[z--] = '%';
                j--;
            }
        }
        str.resize(new_length);
        return str;
    }
};

TEST(Solution05, ReplaceSpaces) {
    Solution05 s;

    std::string str(" We are  happy. ");
    str.resize(128);
    EXPECT_THAT(s.replaceSpaces(str, 16).c_str(), StrEq("%20We%20are%20%20happy.%20"));

    std::string str1("abc");
    str1.resize(128);
    EXPECT_THAT(s.replaceSpaces(str1, 3).c_str(), StrEq("abc"));

    std::string str2;
    str2.resize(128);
    EXPECT_THAT(s.replaceSpaces(str2, 0).c_str(), StrEq(""));

    std::string str3("x");
    str3.resize(128);
    EXPECT_THAT(s.replaceSpaces(str3, 1).c_str(), StrEq("x"));

    std::string str4("   ");
    str4.resize(128);
    EXPECT_THAT(s.replaceSpaces(str4, 3).c_str(), StrEq("%20%20%20"));

    // 这条用例比较特殊，在原先字符空间上处理完后，结尾还有多余的空格，需要 resize 掉
    std::string str5("ds sdfs afs sdfa dfssf asdf             ");
    str5.resize(256);
    EXPECT_THAT(s.replaceSpaces(str5, 27).c_str(), StrEq("ds%20sdfs%20afs%20sdfa%20dfssf%20asdf"));
}
