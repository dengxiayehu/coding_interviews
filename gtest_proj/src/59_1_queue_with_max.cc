#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <deque>
#include <queue>
#include <utility>

// 题目：队列的最大值。
// 请定义一个队列并实现函数 max 得到队列里的最大值，要求函数 max、push_back 和 pop_front 的时间复杂度都是 O(1)。
// 需要自行维护一个索引信息，用来在弹出一个元素时判断 max top 是否需要弹出。
template <typename T>
class QueueWithMax {
public:
    void Push(T val) {
        InternalData data = std::make_pair(m_cur_idx, val);
        m_data_que.push(data);
        while (!m_max_deque.empty() && m_max_deque.back().second <= val) {  // 注意：这里是 <=
            m_max_deque.pop_back();
        }
        m_max_deque.push_back(data);
        ++m_cur_idx;
    }

    void Pop() {
        InternalData data = m_data_que.front();
        m_data_que.pop();
        if (data.first == m_max_deque.front().first) {
            m_max_deque.pop_front();
        }
    }

    T Front() const {
        m_data_que.front();
    }

    T Max() const {
        return m_max_deque.front().second;
    }

    T Empty() const {
        return m_data_que.empty();
    }

private:
    int m_cur_idx = 0;
    typedef std::pair<int, T> InternalData;
    std::queue<InternalData> m_data_que;
    std::deque<InternalData> m_max_deque;
};

TEST(ut_59_1, QueueWithMax) {
    QueueWithMax<int> max_queue;

    max_queue.Push(3);
    EXPECT_EQ(max_queue.Max(), 3);

    max_queue.Push(6);
    EXPECT_EQ(max_queue.Max(), 6);

    max_queue.Push(6);
    EXPECT_EQ(max_queue.Max(), 6);

    max_queue.Pop();
    EXPECT_EQ(max_queue.Max(), 6);

    max_queue.Pop();
    EXPECT_EQ(max_queue.Max(), 3);
}
