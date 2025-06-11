#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/
// 这道题和剑指 offer 上有所偏差，offer 中允许元素存在重复，难度更高
class Solution11_1 {
public:
    // 遇到要求 O(logn) 时间复杂度的算法，那么肯定是二分
    int findMin(const std::vector<int>& nums) {
        // return find_min_internal(nums, 0, nums.size() - 1);

        // 元素仅有一个或者已经是有序的情况
        if (nums.size() == 1 || nums.front() < nums.back()) {
            return nums[0];
        }

        int lo = 0;
        int hi = nums.size() - 1;
        // 只要还有至少 2 个元素就需要处理
        while (lo < hi) {
            int m = lo + ((hi - lo) >> 1);
            // 注意：是判断 nums[m] 和 nums[hi]，因为若只有 2 个元素时 m != hi 但是 m = lo
            if (nums[m] > nums[hi]) {
                lo = m + 1;
            } else {
                hi = m;
            }
        }

        return nums[lo];
    }

private:
    // 下面算法是自己想出来的，能解决问题，但是不够清晰和简练
    // 面试时若遇到这道题，还是用上面的算法解决较好
    int find_min_internal(const std::vector<int>& nums, int lo, int hi) {
        // 递归退出条件1：包含仅有一个元素或数组已经有序的情况
        if (nums[lo] <= nums[hi]) {
            return nums[lo];
        }

        // 递归退出条件2：找到了下降点
        if (lo + 1 == hi && nums[lo] > nums[hi]) {
            return nums[hi];
        }

        // 不断对半分最终肯定分成 size=1 或者 size=2 子数组，在数组非递减情况下，肯定会走到上面递归退出条件 1 或者 2

        int m = lo + ((hi - lo) >> 1);
        if (nums[lo] > nums[m]) {
            // 特殊情况：判断是否就是递减序列，例如：5 4 3 2 1
            if (nums[m] > nums[hi]) {
                return nums[hi];
            }
            // 下降点在左侧
            return find_min_internal(nums, lo, m);
        }
        // 特殊情况：判断是否递增序列在一开始就判断了，例如：1 2 3 4 5，这里无需再判断
        // 下降点肯定在右侧
        return find_min_internal(nums, m, hi);
    }
};

TEST(ut_11, findMin) {
    Solution11_1 s;

    std::vector<int> nums = {3, 4, 5, 1, 2};
    EXPECT_EQ(s.findMin(nums), 1);

    std::vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(s.findMin(nums1), 0);

    std::vector<int> nums2 = {11, 13, 15, 17};
    EXPECT_EQ(s.findMin(nums2), 11);

    std::vector<int> nums3 = {1, 2};
    EXPECT_EQ(s.findMin(nums3), 1);

    std::vector<int> nums4 = {1, 2, 3};
    EXPECT_EQ(s.findMin(nums4), 1);

    std::vector<int> nums5 = {3, 1, 2};
    EXPECT_EQ(s.findMin(nums5), 1);

    std::vector<int> nums6 = {5, 1, 2, 3, 4};
    EXPECT_EQ(s.findMin(nums6), 1);

    std::vector<int> nums7 = {2, 3, 4, 1};
    EXPECT_EQ(s.findMin(nums7), 1);

    std::vector<int> nums8 = {5, 4, 3, 2, 1};
    EXPECT_EQ(s.findMin(nums8), 1);

    std::vector<int> nums9 = {5, 4, 3};
    EXPECT_EQ(s.findMin(nums9), 3);
}
