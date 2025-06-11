#include <gtest/gtest.h>

// https://leetcode.cn/problems/number-of-1-bits/
// 题目：请实现一个函数，输入一个整数，输出该数的二进制表示中 1 的个数。
// 1 <= n <= 2^31 - 1
// 这道题感觉必须想到 n &= (n - 1) 能去掉 n 表示的二进制中的最后一位 1 的算法才能通过面试，这个思想也需要牢记。
// 其他类似题目：
// 1. 判断一个数是否为 2 的整数次方（二进制表示中只有 1 个 1）
// 2. 数字 m 的二进制变更几次可以得到数字 n，可以先求 m 和 n 的异或拿到要变动的数字，然后数里面 1 的个数
class Solution15 {
public:
    int hammingWeight(int n) {
        // return mustBePositive(n);
        // return supportNegative(n);
        return fast(n);
    }

private:
    // 这是我想出的最“朴素”的算法，针对题目的要求算法本身没有问题
    int mustBePositive(int n) {
        int res = 0;
        while (n != 0) {
            if ((n & 1) == 1) {
                ++res;
            }
            n >>= 1;
        }

        return res;
    }

    int supportNegative(int n) {
        int res = 0;
        unsigned int flag = 1;
        while (flag) {
            if ((n & flag) != 0) {
                ++res;
            }
            flag <<= 1;
        }

        return res;
    }

    // 最优算法
    int fast(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= (n - 1);
        }

        return res;
    }
};

TEST(ut_15, hammingWeight) {
    Solution15 s;

    EXPECT_EQ(s.hammingWeight(1), 1);
    EXPECT_EQ(s.hammingWeight(3), 2);
    EXPECT_EQ(s.hammingWeight(9), 2);
}
