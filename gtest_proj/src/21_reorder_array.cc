#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <functional>
#include <vector>

// https://leetcode.cn/problems/sort-array-by-parity/description/
// 题目：给你一个整数数组 nums，将 nums 中的所有偶数元素移动到数组的前面，后跟所有奇数元素。
class Solution21 {
public:
    // 类似快速排序中的 partition 算法
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        return sortArray(nums, is_even);
    }

    static bool is_even(int n) {
        return (n & 1) == 0;
    }

private:
    // 将条件参数化，更加通用一些
    std::vector<int> sortArray(std::vector<int>& nums, std::function<bool(int)> f) {
        size_t sz = nums.size();
        int i = 0;
        int j = sz - 1;
        while (i < j) {
            while (i < j && f(nums[i])) {
                i++;
            }
            while (i < j && !f(nums[j])) {
                j--;
            }
            if (i < j) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        return nums;
    }
};

MATCHER(ReorderedArrayMatcher, "") {
    const std::vector<int>& v = arg;
    bool odd_found = false;
    for (size_t sz = v.size(), i = 0; i < sz; i++) {
        if (!Solution21::is_even(v[i])) {
            odd_found = true;
        } else {
            if (odd_found) {
                return false;
            }
        }
    }

    return true;
}

TEST(ut_21, sortArrayByParity) {
    Solution21 s;

    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_THAT(s.sortArrayByParity(nums), ReorderedArrayMatcher());
}
