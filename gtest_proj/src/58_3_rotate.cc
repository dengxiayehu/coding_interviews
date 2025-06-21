#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "./matchers.h"

// https://leetcode.cn/problems/rotate-array/
// 题目：给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
// 思路：将右移动转换为左移，然后用“杂技”翻转算法。
class Solution58_3 {
public:
    void rotate(std::vector<int>& nums, int k) {
        if (nums.empty() || k <= 0 || k % nums.size() == 0) {
            return;
        }

        k %= nums.size();
        k = nums.size() - k;
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
        reverse(nums, 0, nums.size() - 1);
    }

private:
    void reverse(std::vector<int>& nums, int i, int j) {
        if (i < 0 || i >= nums.size() || j < 0 || j >= nums.size()) {
            return;
        }

        while (i < j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            ++i;
            --j;
        }
    }
};

TEST(ut_58_3, rotate) {
    Solution58_3 s;

    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    s.rotate(nums, 3);
    EXPECT_THAT(nums, ElementsAreArray(std::vector<int>{5, 6, 7, 1, 2, 3, 4}));
}
