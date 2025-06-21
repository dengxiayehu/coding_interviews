#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/single-number-ii/description/
// 题目：数组中唯一只出现一次的数字，其他数字都出现了三次，请找出那个只出现了一次的数字。
// 将一个整型数的二进制表示拆开，分别将对应 bit 1 的个数相加，最终和为 3N 或者 3N + 1。3N + 1 对应的 bit 1 就是出现一次
// 的元素的 bit 1。
class Solution56_1 {
public:
    int singleNumber(const std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        static constexpr int kIntBits = sizeof(int) * 8;
        int bits_sum[kIntBits] = {0};
        for (const auto n : nums) {
            unsigned int flag = 1;
            for (int i = 0; i < kIntBits; ++i) {
                if ((n & flag) != 0) {
                    ++bits_sum[i];
                }
                flag <<= 1;
            }
        }
        int res = 0;
        unsigned int flag = 1;
        for (int i = 0; i < kIntBits; ++i) {
            if (bits_sum[i] % 3 != 0) {
                res |= flag;
            }
            flag <<= 1;
        }

        return res;
    }
};

TEST(ut_56_1, singleNumber) {
    Solution56_1 s;

    EXPECT_EQ(s.singleNumber(std::vector<int>{2, 2, 3, 2}), 3);
    EXPECT_EQ(s.singleNumber(std::vector<int>{0, 1, 0, 1, 0, 1, 99}), 99);
}
