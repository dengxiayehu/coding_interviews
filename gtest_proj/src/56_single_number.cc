#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "./matchers.h"

// https://leetcode.cn/problems/single-number-iii/description/
// 题目：给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。请找出只出现一次的那两个数字。
// 先将数组中所有元素异或一次，得到唯一两个出现一次的元素异或值。找到异或值二进制表示中某个 bit 1，然后据此将原数组中
// 元素判断对应 bit 是否为 1 对半分开再异或，如此两个出现一次的元素肯定在不同的一半中。
class Solution56 {
public:
    std::vector<int> singleNumber(const std::vector<int>& nums) {
        std::vector<int> res;
        if (nums.size() <= 1) {
            return res;
        }

        int res_xor = 0;
        for (const auto n : nums) {
            res_xor ^= n;
        }

        unsigned int mask = get_first_index_of_1_mask(res_xor);
        int a = 0;
        int b = 0;
        for (const auto n : nums) {
            if (test_bit(n, mask)) {
                a ^= n;
            } else {
                b ^= n;
            }
        }
        res.push_back(a);
        res.push_back(b);

        return res;
    }

private:
    unsigned int get_first_index_of_1_mask(int i) {
        unsigned int flag = 1;
        while (flag != 0) {
            if ((flag & i) != 0) {
                break;
            }
            flag <<= 1;
        }

        return flag;
    }

    bool test_bit(int i, unsigned int mask) {
        return (i & mask) != 0;
    }
};

TEST(ut_56, singleNumber) {
    Solution56 s;

    EXPECT_THAT(s.singleNumber(std::vector<int>{1, 2, 1, 3, 2, 5}), UnorderedElementsAreArray(std::vector<int>{3, 5}));
    EXPECT_THAT(s.singleNumber(std::vector<int>{2, 1, 2, 3, 4, 1}), UnorderedElementsAreArray(std::vector<int>{3, 4}));
}
