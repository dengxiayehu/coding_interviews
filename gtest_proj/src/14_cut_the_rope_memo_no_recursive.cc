#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

// https://leetcode.cn/problems/jian-sheng-zi-lcof/description/
// 优先采用此自底向上的算法，先将小问题算好，再根据递推公式算大问题。
class Solution14_1 {
public:
    int cuttingBamboo(int length) {
        if (length <= 0) {
            return 0;
        }
        if (length == 1) {
            return 1;
        }
        if (length <= 3) {
            return length - 1;
        }

        std::vector<int> memo(length + 1);
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 3;
        // 通用的套路，定义一个极值
        int max = 0;
        for (int i = 4; i <= length; i++) {
            // 求取每一个 memo[i] 的值
            for (int j = 1; j <= (i >> 1); j++) {  // 没必要傻傻的从 1 切割到 i - 1，超过中心就对称处理了
                // 递推公式：f(n) = f(i) * f(n - i)
                max = std::max(max, memo[j] * memo[i - j]);
            }
            memo[i] = max;
        }

        return memo[length];
    }
};

TEST(ut_14_1, cuttingBambooNoRecursive) {
    Solution14_1 s;

    EXPECT_EQ(s.cuttingBamboo(8), 18);
    EXPECT_EQ(s.cuttingBamboo(3), 2);
    EXPECT_EQ(s.cuttingBamboo(9), 27);
    EXPECT_EQ(s.cuttingBamboo(12), 81);
    EXPECT_EQ(s.cuttingBamboo(20), 1458);
}
