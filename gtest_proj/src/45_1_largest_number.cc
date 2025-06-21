#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

// https://leetcode.cn/problems/largest-number/
// 题目：给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的数。
// 全排列算法会超时。
// 另外需注意：若数组中所有元素都是 0，需要去重。
// 这道题已经想到要排序，但关注点都在 a 和 b 比较（位数可能不同），没有想到将拼接结果进行比较:(。
class Solution45_1 {
public:
    std::string largestNumber(const std::vector<int>& nums) {
        if (nums.empty()) {
            return "";
        }

        std::vector<std::string> nums_str;
        for (auto n : nums) {
            nums_str.push_back(std::to_string(n));
        }

        std::sort(nums_str.begin(), nums_str.end(),
                  [](const std::string& a, const std::string& b) { return a + b > b + a; });

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

TEST(ut_45_1, largestNumber) {
    Solution45_1 s;

    {
        std::vector<int> nums{1, 2, 3};
        EXPECT_THAT(s.largestNumber(nums), "321");
    }

    {
        std::vector<int> nums{3, 32, 321};
        EXPECT_THAT(s.largestNumber(nums), "332321");
    }

    {
        std::vector<int> nums{432, 43243};
        EXPECT_THAT(s.largestNumber(nums), "43243432");
    }

    {
        std::vector<int> nums{1, 4, 7, 2, 5, 8, 0, 3, 6, 9};
        EXPECT_THAT(s.largestNumber(nums), "9876543210");
    }

    {
        std::vector<int> nums{3, 30, 34, 5, 9};
        EXPECT_THAT(s.largestNumber(nums), "9534330");
    }

    {
        std::vector<int> nums{0, 0, 0, 0};
        EXPECT_THAT(s.largestNumber(nums), "0");
    }

    {
        std::vector<int> nums{1175, 482, 341, 815, 7354, 4543, 4576, 9042, 7929, 8839};
        EXPECT_THAT(s.largestNumber(nums), "9042883981579297354482457645433411175");
    }
}
