#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/majority-element/
class Solution39_1 {
public:
    int majorityElement(const std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        const size_t nums_size = nums.size();
        int count = 1;
        int cand = nums[0];
        for (size_t i = 1; i < nums_size; i++) {
            int n = nums[i];
            if (n == cand) {
                ++count;
            } else if (--count == 0) {
                cand = n;
                count = 1;
            }
        }

        return cand;
    }
};

TEST(ut_39_1, majorityElementFaster) {
    Solution39_1 s;

    std::vector<int> nums1{3, 2, 3};
    EXPECT_EQ(s.majorityElement(nums1), 3);
    std::vector<int> nums2{2, 2, 1, 1, 1, 2, 2};
    EXPECT_EQ(s.majorityElement(nums2), 2);
    std::vector<int> nums3{4, 5, 4};
    EXPECT_EQ(s.majorityElement(nums3), 4);
}
