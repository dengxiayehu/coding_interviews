#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/description/
class Solution11 {
public:
    int findMin(const std::vector<int>& nums) {
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
            } else if (nums[m] < nums[hi]) {
                hi = m;
            } else {
                hi--;
            }
        }

        return nums[lo];
    }
};

TEST(ut_11, findMinMayDuplicate) {
    Solution11 s;

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

    std::vector<int> nums8 = {2, 2, 2, 0, 1};
    EXPECT_EQ(s.findMin(nums8), 0);

    std::vector<int> nums9 = {2, 2, 2, 0, 2};
    EXPECT_EQ(s.findMin(nums9), 0);

    std::vector<int> nums10 = {0, 1, 2, 2, 2};
    EXPECT_EQ(s.findMin(nums10), 0);

    std::vector<int> nums11 = {1, 1, 3};
    EXPECT_EQ(s.findMin(nums11), 1);
}
