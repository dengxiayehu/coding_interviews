#include <gmock/gmock.h>
#include <gtest/gtest.h>

// https://leetcode.cn/problems/qiu-12n-lcof/description/
// 题目：求 1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case 等关键字及条件判断语句（A ? B : C）。
class A {
public:
    A() {
        ++InstanceCount;
        AccumulatorCount += InstanceCount;
    }

    static int GetAccumulatorCount() {
        return AccumulatorCount;
    }

    static void Reset() {
        AccumulatorCount = 0;
        InstanceCount = 0;
    }

private:
    static int InstanceCount;
    static int AccumulatorCount;
};

int A::InstanceCount = 0;
int A::AccumulatorCount = 0;

class Solution64 {
public:
    int mechanicalAccumulator(int target) {
        // 创建一个 n * (n + 1) 大小的二维数组，求其大小就是 n * (n + 1)，然后再除以 2 即可
        char arr[target][target + 1];

        return sizeof(arr) >> 1;
    }

    int mechanicalAccumulatorUseConstructor(int target) {
        // 将重置操作放到测试函数入口这里较好
        A::Reset();

        A* arr = new A[target];
        int res = A::GetAccumulatorCount();
        delete[] arr;

        return res;
    }
};

TEST(ut_64, mechanicalAccumulator) {
    Solution64 s;

    EXPECT_EQ(s.mechanicalAccumulator(5), 15);
    EXPECT_EQ(s.mechanicalAccumulator(7), 28);
}

TEST(ut_64, mechanicalAccumulatorUseConstructor) {
    Solution64 s;

    EXPECT_EQ(s.mechanicalAccumulatorUseConstructor(5), 15);
    EXPECT_EQ(s.mechanicalAccumulatorUseConstructor(7), 28);
}
