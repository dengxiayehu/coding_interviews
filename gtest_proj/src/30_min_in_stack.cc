#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <stack>

// https://leetcode.cn/problems/min-stack/description/
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数。在该栈中，调用 min、push 以及 pop 的时间
// 复杂度都是 O(1)。
// 这道题能想出一个辅助栈的思路不容易。
class MinStack {
public:
    MinStack() {
    }

    void push(int val) {
        m_stack_data.push(val);
        int min = val;
        if (!m_stack_min.empty()) {
            int min_top = m_stack_min.top();
            if (min > min_top) {
                min = min_top;
            }
        }
        m_stack_min.push(min);
    }

    void pop() {
        m_stack_data.pop();
        m_stack_min.pop();
    }

    int top() {
        return m_stack_data.top();
    }

    // 取栈中最小的元素，时间复杂度是 O(1)
    int getMin() {
        return m_stack_min.top();
    }

private:
    std::stack<int> m_stack_data;
    std::stack<int> m_stack_min;
};

TEST(ut_30, MinStack) {
    MinStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.getMin(), 1);
}
