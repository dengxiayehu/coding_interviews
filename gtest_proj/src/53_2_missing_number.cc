#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/missing-number/
// 题目：丢失的数字。给定一个包含 [0, n] 中 n 个数的数组 nums，找出 [0, n] 这个范围内没有出现在数组中的那个数。
// 数组中所有数字都是独一无二的。
// 数组并非有序。
// 要求：线性时间复杂度，额外常数空间。
class Solution53_2 {
public:
    int missingNumber(const std::vector<int>& nums) {
        // 参数校验，不论外部怎么调用，确保函数不崩溃是基本要求
        if (nums.empty()) {
            return -1;
        }

        const size_t n = nums.size();
        int target_sum = (n * (n + 1)) >> 1;
        int sum = 0;
        for (const auto n : nums) {
            sum += n;
        }

        return target_sum - sum;
    }

    int missingNumberXOR(const std::vector<int>& nums) {
        // 参数校验，不论外部怎么调用，确保函数不崩溃是基本要求
        if (nums.empty()) {
            return -1;
        }

        const size_t n = nums.size();
        int res = 0;
        // 异或一个数两次，相当于没有异或这个数；
        // 0 异或一个数等于那个数
        for (const auto n : nums) {
            res ^= n;
        }
        for (int i = 0; i <= n; ++i) {
            res ^= i;
        }

        return res;
    }
};

TEST(ut_53_2, missingNumber) {
    Solution53_2 s;

    EXPECT_EQ(s.missingNumber(std::vector<int>{3, 0, 1}), 2);
}

TEST(ut_53_2, missingNumberXOR) {
    Solution53_2 s;

    EXPECT_EQ(s.missingNumberXOR(std::vector<int>{3, 0, 1}), 2);
}
