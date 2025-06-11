#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

// https://leetcode.cn/problems/jian-sheng-zi-lcof/description/
/* 题目：给你一根长度为 n 的绳子，请把绳子剪成 m 段（m、n 都是整数，n > 1 且 m > 1），每段绳子的长度记作 k[0],k[1], ...,
 *k[m]。 请问 k[0],k[1]*...*k[m] 可能的最大乘积是多少？
 **/
// 这种题目必须使用动态规划 + 备忘录的方式，否则运行会超时。这里的算法是递归的自顶向下，能通过用例，但还有优化空间。
class Solution14 {
public:
    int cuttingBamboo(int length) {
        // 参数校验
        if (length <= 0) {
            return 0;
        }
        if (length == 1) {
            return 1;
        }

        // 特殊情况
        if (length <= 3) {
            return length - 1;
        }

        // 备忘录，空间大小需是 length + 1，先初始化基本情况
        std::vector<int> memo(length + 1);
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 3;

        return cutting_bamboo_internal(length, &memo);
    }

private:
    int cutting_bamboo_internal(int length, std::vector<int>* memo) {
        // 备忘录中已经有值了，直接取出
        if (memo->at(length) > 0) {
            return memo->at(length);
        }

        int max = 0;
        // 绳子可能的分割点
        // i 不用从 1 开始，因为这种情况乘积肯定比不分割还小，另外最多只要尝试分割一半就行了
        int cut_idx = (length >> 1);
        for (int i = 2; i <= cut_idx; i++) {
            int left = std::max(i, cutting_bamboo_internal(i, memo));
            int right = std::max(length - i, cutting_bamboo_internal(length - i, memo));
            max = std::max(max, left * right);
        }
        // 将 length 结果保存入备忘录
        memo->at(length) = max;

        return max;
    }
};

TEST(ut_14, cuttingBamboo) {
    Solution14 s;

    EXPECT_EQ(s.cuttingBamboo(8), 18);
    EXPECT_EQ(s.cuttingBamboo(3), 2);
    EXPECT_EQ(s.cuttingBamboo(4), 4);
    EXPECT_EQ(s.cuttingBamboo(9), 27);
    EXPECT_EQ(s.cuttingBamboo(12), 81);
    EXPECT_EQ(s.cuttingBamboo(20), 1458);
}
