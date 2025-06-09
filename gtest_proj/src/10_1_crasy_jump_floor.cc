#include <gtest/gtest.h>

// 青蛙最多一次可以跳 n 阶，求青蛙跳上 n 阶台阶总共有多少种跳法。
// 思路是：n 以下的 n - 1 阶台阶要么跳，要么不跳，每一阶都有两种情况，所以结果应该是 2 ^ (n - 1)
// 另外思考快速乘方算法：
// a^n = a^(n/2) * a^(n/2)    ，n=偶数
// a^n = a^(n/2) * a^(n/2) * a，n=奇数
// 看了之前的题解，还可以更快：
// a^n = (a * a)^(n/2)    ，n=偶数
// a^n = (a * a)^(n/2) * a，n=奇数
class Solution10_1 {
public:
    int jumpFloorII(int number) {
        // 边界情况，0/1 阶都只有一种情况
        if (number <= 1) {
            return 1;
        }
        return mypow(2, number - 1);
    }

private:
    int mypow(int a, int n) {
        if (n == 1) {
            // 递归退出条件
            return a;
        }
        if ((n & 1) == 1) {  // 奇数
            return mypow(a * a, n / 2) * a;
        } else {  // 偶数
            return mypow(a * a, n / 2);
        }
    }
};

TEST(ut_10_1, JumpFloorII) {
    Solution10_1 s;

    EXPECT_EQ(s.jumpFloorII(-1), 1);
    EXPECT_EQ(s.jumpFloorII(0), 1);
    EXPECT_EQ(s.jumpFloorII(1), 1);
    EXPECT_EQ(s.jumpFloorII(2), 2);
    EXPECT_EQ(s.jumpFloorII(3), 4);
    EXPECT_EQ(s.jumpFloorII(4), 8);
}
