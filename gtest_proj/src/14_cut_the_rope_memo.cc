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

        // 达到最小长度没法再分割了
        if (length == 1) {
            return 1;
        }

        // 特殊情况，在长度为 2 和 3 时理论上不分割乘积最大，但题目要求我们必须要分割
        // cutting_bamboo_internal 算法考虑了不分割的情况
        // 所以需要特殊处理
        if (length <= 3) {
            return length - 1;
        }

        // 备忘录
        std::vector<int> memo(length + 1, -1);
        return cutting_bamboo_internal(length, &memo);
    }

private:
    int cutting_bamboo_internal(int length, std::vector<int>* memo) {
        // 备忘录中已经有值了，直接取出
        if ((*memo)[length] > 0) {
            return (*memo)[length];
        }

        // 默认最大乘积是不分割的情况
        int res = length;
        // 绳子可能的分割点
        // 有一个优化点，i 不用从 1 开始，因为这种情况乘积肯定比不分割还小
        int cut_idx = (length >> 1);
        for (int i = 2; i <= cut_idx; i++) {
            res = std::max(res, cutting_bamboo_internal(i, memo) * cutting_bamboo_internal(length - i, memo));
        }
        // 将 length 结果保存入备忘录
        (*memo)[length] = res;

        return res;
    }
};

TEST(ut_14, cuttingBamboo) {
    Solution14 s;

    EXPECT_EQ(s.cuttingBamboo(8), 18);
    EXPECT_EQ(s.cuttingBamboo(3), 2);
    EXPECT_EQ(s.cuttingBamboo(9), 27);
    EXPECT_EQ(s.cuttingBamboo(12), 81);
    EXPECT_EQ(s.cuttingBamboo(20), 1458);
}
