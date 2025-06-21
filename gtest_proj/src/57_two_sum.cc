#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
// 题目：和为 s 的两个数字。输入一个递增排序的数组和一个数字 s，在数组中查找两个数，使得它们的和正好是 s。如果有多对数字
// 的和等于 s，则输出任意一堆即可。
// leetcode 上要求数组的下标是从 1 开始，返回结果中索引小的在前面。
class Solution57 {
public:
    std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
        std::vector<int> res;
        if (numbers.size() < 2) {
            return res;
        }

        int l = 0;
        int r = numbers.size() - 1;
        while (l <= r) {
            int cur_sum = numbers[l] + numbers[r];
            if (cur_sum == target) {
                res.push_back(l + 1);
                res.push_back(r + 1);
                break;
            } else if (cur_sum > target) {
                --r;
            } else {
                ++l;
            }
        }

        return res;
    }
};

MATCHER_P(VectorContentMatcher, vi, "") {
    const std::vector<int>& v = arg;
    for (size_t i = 0; i < vi.size(); i++) {
        if (v[i] != vi[i]) {
            return false;
        }
    }

    return true;
}

TEST(ut_57, tn_57) {
    Solution57 s;

    EXPECT_THAT(s.twoSum(std::vector<int>{2, 7, 11, 15}, 9), VectorContentMatcher(std::vector<int>{1, 2}));
}
