#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <functional>

#include "./heap.h"

// https://leetcode.cn/problems/find-median-from-data-stream/description/
// 题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有值排序之后位于中间的数值。如果从
// 数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
class MedianFinder {
public:
    MedianFinder() {
    }

    void addNum(int num) {
        ++m_count;

        if (m_max_heap.Empty() && m_min_heap.Empty()) {
            // 首个元素塞入左侧最大堆
            m_max_heap.Insert(num);
            return;
        }

        // 在左侧最大堆中判断
        if (num <= m_max_heap.Top()) {
            m_max_heap.Insert(num);
            try_to_balance();
            return;
        }

        // 不满足塞入左侧最大堆的，都塞入右侧最小堆
        // 这个思想很关键，简化思维过程
        m_min_heap.Insert(num);
        try_to_balance();
    }

    double findMedian() {
        if ((m_count & 1) == 1) {
            return m_max_heap.Size() > m_min_heap.Size() ? m_max_heap.Top() : m_min_heap.Top();
        }
        return (m_max_heap.Top() + m_min_heap.Top()) / 2.0;
    }

private:
    void try_to_balance() {
        while (m_max_heap.Size() > m_min_heap.Size() + 1) {
            m_min_heap.Insert(m_max_heap.Extract());
        }
        while (m_min_heap.Size() > m_max_heap.Size() + 1) {
            m_max_heap.Insert(m_min_heap.Extract());
        }
    }

private:
    Heap<int, std::less<int>> m_max_heap;
    Heap<int> m_min_heap;
    int m_count = 0;
};

TEST(ut_41, MedianFinder) {
    {
        MedianFinder mf;
        mf.addNum(1);
        mf.addNum(2);
        EXPECT_FLOAT_EQ(mf.findMedian(), 1.5);
        mf.addNum(3);
        EXPECT_FLOAT_EQ(mf.findMedian(), 2);
    }

    {
        MedianFinder mf;
        mf.addNum(0);
        mf.addNum(0);
        EXPECT_FLOAT_EQ(mf.findMedian(), 0);
    }

    {
        MedianFinder mf;
        mf.addNum(12);
        EXPECT_FLOAT_EQ(mf.findMedian(), 12);
        mf.addNum(10);
        EXPECT_FLOAT_EQ(mf.findMedian(), 11);
        mf.addNum(13);
        EXPECT_FLOAT_EQ(mf.findMedian(), 12);
        mf.addNum(11);
        EXPECT_FLOAT_EQ(mf.findMedian(), 11.5);
    }
}
