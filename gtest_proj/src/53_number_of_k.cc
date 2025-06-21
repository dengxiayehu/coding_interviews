#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
// 题目：给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。
// 你必须设计并实现时间复杂度为 O(log n)的算法解决此问题。
class Solution53 {
public:
    std::vector<int> searchRange(const std::vector<int>& nums, int target) {
        std::vector<int> res;

        if (nums.empty()) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }

        // get left most
        int l = 0;
        int r = nums.size() - 1;
        int m = 0;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (nums[m] == target) {
                if (m > l && nums[m - 1] == target) {
                    r = m - 1;
                } else {
                    break;
                }
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (l > r) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        res.push_back(m);

        // get right most
        l = 0;
        r = nums.size() - 1;
        m = 0;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (nums[m] == target) {
                if (m < r && nums[m + 1] == target) {
                    l = m + 1;
                } else {
                    break;
                }
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        res.push_back(m);

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

TEST(ut_53, searchRange) {
    Solution53 s;

    auto res = s.searchRange(std::vector<int>{5, 7, 7, 8, 8, 10}, 8);
    EXPECT_THAT(res, VectorContentMatcher(std::vector<int>{3, 4}));

    res = s.searchRange(std::vector<int>{5, 7, 7, 8, 8, 10}, 6);
    EXPECT_THAT(res, VectorContentMatcher(std::vector<int>{-1, -1}));

    res = s.searchRange(std::vector<int>{}, 0);
    EXPECT_THAT(res, VectorContentMatcher(std::vector<int>{-1, -1}));
}
