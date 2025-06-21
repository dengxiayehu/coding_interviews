#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// 题目：0~n-1 中缺失的数字。
// 一个长度为 n-1 的递增排序数组中的所有数字都是唯一的，并且每个数字都在 0~n-1 之内。在范围 0~n-1 内的 n 个数字中有且仅
// 有一个数字不出现在该数组中，请找出这个数。
// 题目出的有点拗口，就是长度为 n 的数组，每个元素都在 [0, n] 之内。
// 思路：这是一个典型的类二分查找算法。
class Solution53_1 {
public:
    int getMissingNumber(const std::vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }

        const size_t n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] == m) {
                // 正好在位置上，说明左边不缺
                l = m + 1;
                if (l > r) {
                    // 都在位置上，但题意肯定缺一个，就是 r + 1
                    return r + 1;
                }
            } else if (nums[m] > m) {
                r = m - 1;
                if (r < l) {
                    // nums[m] 少一个数
                    return m;
                }
            }
        }

        return 0;
    }
};

TEST(ut_53_1, getMissingNumber) {
    Solution53_1 s;

    EXPECT_EQ(s.getMissingNumber(std::vector<int>{0, 1, 3}), 2);
    EXPECT_EQ(s.getMissingNumber(std::vector<int>{0, 2, 3}), 1);
    EXPECT_EQ(s.getMissingNumber(std::vector<int>{0, 1, 2, 4, 5}), 3);
    EXPECT_EQ(s.getMissingNumber(std::vector<int>{1, 2, 3, 4, 5}), 0);
    EXPECT_EQ(s.getMissingNumber(std::vector<int>{0, 2, 3, 4, 5}), 1);
    EXPECT_EQ(s.getMissingNumber(std::vector<int>{0, 1, 2, 3, 4}), 5);
}
