#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <stack>

// https://leetcode.cn/problems/min-stack/description/
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数。在该栈中，调用 min、push 以及 pop 的时间
// 复杂度都是 O(1)。
// 这道题还可以不使用辅助栈，额外空间复杂度也是 O(1) 的解法，思想是栈中存入的是当前值与最小值的偏差，并且记录最小值。
// 这个算法技巧性很高！
class MinStack1 {
public:
    MinStack1() {
    }

    void push(int val) {
        if (m_stack.empty()) {
            // 压入首个元素
            m_min = val;
            m_stack.push(0);
        } else {
            int64_t diff = val - m_min;  // 判断当前值和最小值的偏差
            m_stack.push(diff);

            if (diff < 0) {  // 当前值更小，需更新最小值
                m_min = val;
            }
        }
    }

    void pop() {
        int64_t diff = m_stack.top();
        m_stack.pop();
        if (diff < 0) {  // 弹掉了一个最小值，最小值变大了
            m_min -= diff;
        }
    }

    int top() {
        int64_t diff = m_stack.top();
        if (diff > 0) {
            return m_min + diff;
        }

        // 此时当前值就是最小值
        return m_min;
    }

    // 取栈中最小的元素，时间复杂度是 O(1)
    int getMin() {
        return m_min;
    }

private:
    // 栈中存储当前值和最小值的偏差：
    // 若值为正则恢复时当前值为 m_min + diff，最小值保持不变；
    // 若值为负则当前值就是 m_min
    std::stack<int64_t> m_stack;
    int64_t m_min = 0;  // 记录最小值
};

TEST(ut_30_1, MinStack1) {
    MinStack1 s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.getMin(), 1);
}
