#include <gtest/gtest.h>

// leetcode 70：爬楼梯
// leetcode 127：跳跃训练
// 考虑 n 台阶的情况，最后一步可以跨 1 阶，也可以跨 2 阶，则所有可能的走法为：
// (f(n - 1) + 确定地走 1 阶) + (f(n - 2) + 确定地走 2 阶)
// 其实就是斐波拉契序列，但 127 这道题需要对 fn 结果对 1000000007 取模，所以过程中的值肯定不会超过 int 表示的范围
class Solution10 {
public:
    int trainWays(int num) {
        if (num <= 1) {
            return 1;
        }
        int f1 = 1;
        int f2 = 1;
        int fn = 0;
        for (int i = 2; i <= num; i++) {
            fn = (f2 + f1) % 1000000007;  // 70 题不需要对 1000000007 取模
            f1 = f2;
            f2 = fn;
        }

        return fn;
    }
};

TEST(ut_10, TrainWays) {
    Solution10 s;

    EXPECT_EQ(s.trainWays(1), 1);
    EXPECT_EQ(s.trainWays(2), 2);
    EXPECT_EQ(s.trainWays(3), 3);
    EXPECT_EQ(s.trainWays(44), 134903163);
}
