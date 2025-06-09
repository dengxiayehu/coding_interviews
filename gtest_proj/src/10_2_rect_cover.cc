#include <gtest/gtest.h>

// 8 个 2*1 的矩形去覆盖 8*2 的大矩形，有多少种方法？
// 和跳台阶问题类似，考虑最后一步覆盖是横着的两块覆盖还是竖着的一块覆盖，则情况是 f(n - 2) + f(n - 1)
class Solution10_2 {
public:
    int rectCover(int number) {
        if (number <= 1) {
            return 1;
        }
        int f0 = 1;
        int f1 = 1;
        int fn = 0;
        for (int i = 2; i <= number; i++) {
            fn = f0 + f1;
            f0 = f1;
            f1 = fn;
        }
        return fn;
    }
};

TEST(ut_10_2, RectCover) {
    Solution10_2 s;

    EXPECT_EQ(s.rectCover(1), 1);
    EXPECT_EQ(s.rectCover(2), 2);
    EXPECT_EQ(s.rectCover(3), 3);
    EXPECT_EQ(s.rectCover(4), 5);
}
