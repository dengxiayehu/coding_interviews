#include <gtest/gtest.h>

#include <queue>
#include <vector>

// https://leetcode.cn/problems/implement-stack-using-queues/description/
// 这道题有一个难点是怎么快捷地获取 top，用一个变量来记录。
class MyStack {
public:
    MyStack() {
        m_queues.resize(2);
    }

    void push(int x) {
        m_queues[m_in_idx].push(x);
        m_top = x;
    }

    int pop() {
        std::queue<int>* in_queue = &m_queues[m_in_idx];
        std::queue<int>* other_queue = &m_queues[TheOtherIdx()];
        // 将 in_queue 中的元素拷贝到 other_queue，仅保留一个元素
        while (in_queue->size() > 1) {
            int val = in_queue->front();
            in_queue->pop();
            other_queue->push(val);
            m_top = val;
        }
        int val = in_queue->front();
        in_queue->pop();
        m_in_idx = TheOtherIdx();

        return val;
    }

    int top() {
        return m_top;
    }

    bool empty() {
        return m_queues[0].empty() && m_queues[1].empty();
    }

private:
    int TheOtherIdx() const {
        return (m_in_idx + 1) % 2;
    }

private:
    std::vector<std::queue<int>> m_queues;
    int m_in_idx = 0;
    int m_top = -1;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

TEST(ut_09_1, MyStack) {
    MyStack s;
    s.push(1);
    EXPECT_EQ(s.top(), 1);
    s.push(2);
    EXPECT_EQ(s.top(), 2);
    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.top(), 1);
    EXPECT_EQ(s.pop(), 1);
    s.push(3);
    s.push(4);
    s.push(5);
    EXPECT_EQ(s.pop(), 5);
    EXPECT_EQ(s.top(), 4);
    EXPECT_EQ(s.pop(), 4);
    EXPECT_EQ(s.pop(), 3);
}
