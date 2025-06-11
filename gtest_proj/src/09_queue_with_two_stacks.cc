#include <gtest/gtest.h>

#include <stack>

// https://leetcode.cn/problems/implement-queue-using-stacks/description/
class MyQueue {
public:
    MyQueue() {
    }

    void push(int x) {
        // 入队永远都在 in 栈
        m_stack_in.push(x);
    }

    int pop() {
        if (m_stack_out.empty()) {
            TransferInToOut();
        }
        // 从 out 栈中出队一个元素
        int val = m_stack_out.top();
        m_stack_out.pop();

        return val;
    }

    int peek() {
        if (m_stack_out.empty()) {
            TransferInToOut();
        }

        return m_stack_out.top();
    }

    bool empty() {
        return m_stack_in.empty() && m_stack_out.empty();
    }

private:
    void TransferInToOut() {
        // 若 out 栈为空则将 in 中的内容都 pop -> push 进来
        while (!m_stack_in.empty()) {
            int val = m_stack_in.top();
            m_stack_in.pop();
            m_stack_out.push(val);
        }
    }

private:
    std::stack<int> m_stack_in;
    std::stack<int> m_stack_out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

TEST(ut_09, MyQueue) {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    EXPECT_EQ(q.pop(), 1);
    q.push(4);
    EXPECT_EQ(q.pop(), 2);
    EXPECT_EQ(q.peek(), 3);
    EXPECT_EQ(q.pop(), 3);
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(q.pop(), 4);
}
