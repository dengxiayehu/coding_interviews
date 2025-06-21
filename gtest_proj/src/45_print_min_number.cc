#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，找到其中最小的那个。
class Solution45 {
public:
    std::string minNumber(const std::vector<int>& nums) {
        if (nums.empty()) {
            return "";
        }

        std::vector<std::string> nums_str;
        for (auto n : nums) {
            nums_str.push_back(std::to_string(n));
        }

        std::sort(nums_str.begin(), nums_str.end(),
                  [](const std::string& a, const std::string& b) { return a + b < b + a; });

        if (nums_str[0] == "0") {
            return "0";
        }

        std::ostringstream oss;
        for (auto& str : nums_str) {
            oss << str;
        }

        return oss.str();
    }
};

TEST(ut_45, printMinNumber) {
    Solution45 s;

    EXPECT_THAT(s.minNumber(std::vector<int>{3, 32, 321}), "321323");
    EXPECT_THAT(s.minNumber(std::vector<int>{0, 0, 0}), "0");
}
