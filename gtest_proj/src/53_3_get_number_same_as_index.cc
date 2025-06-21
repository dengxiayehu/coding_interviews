#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// 题目：数组中数值和下标相等的元素。
// 假设一个单调递增的数组里的每个元素都是整数并且唯一的。请编程实现一个函数，找出数组中任意一个数值等于其下标的元素。
// 例如，在数组 {-3, -1, 1, 3, 5} 中，数字 3 和它的下标相等。
class Solution53_3 {
public:
    int getNumberSameAsIndex(const std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] == m) {
                return m;
            } else if (nums[m] > m) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return 0;
    }
};

TEST(ut_53_3, getNumberSameAsIndex) {
    Solution53_3 s;

    EXPECT_EQ(s.getNumberSameAsIndex(std::vector<int>{-3, -1, 1, 3, 5}), 3);
}
