#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

#include "./matchers.h"

// https://leetcode.cn/problems/string-to-url-lcci/description/
class Solution05_1 {
public:
    // 有一个更快的算法，不用先计算字符串 str 中空格的个数，反正 str 中空间足够，就将处理后内容放到 str 的最后即可。
    std::string replaceSpaces(std::string& str, int length) {
        if (str.empty() || length <= 0) {
            return str;
        }

        int j = length - 1;
        int z = str.length() - 1;
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
        return str.substr(z + 1);
    }
};

TEST(Solution05_1, ReplaceSpacesFaster) {
    Solution05_1 s;

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
