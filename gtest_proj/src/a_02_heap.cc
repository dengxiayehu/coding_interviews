#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <functional>

#include "./heap.h"

TEST(ut_a_02, minHeap) {
    Heap<int> min_heap;
    min_heap.Insert(2);
    min_heap.Insert(1);
    EXPECT_EQ(min_heap.Top(), 1);
    min_heap.Insert(-1);
    EXPECT_EQ(min_heap.Top(), -1);
    EXPECT_EQ(min_heap.Extract(), -1);
    EXPECT_EQ(min_heap.Extract(), 1);
}

TEST(ut_a_02, maxHeap) {
    Heap<int, std::less<int>> max_heap;
    max_heap.Insert(2);
    max_heap.Insert(1);
    EXPECT_EQ(max_heap.Top(), 2);
    max_heap.Insert(3);
    EXPECT_EQ(max_heap.Top(), 3);
    EXPECT_EQ(max_heap.Extract(), 3);
    EXPECT_EQ(max_heap.Extract(), 2);
}
