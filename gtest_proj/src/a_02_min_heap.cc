#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "./min_heap.h"

TEST(ut_a02, minHeap) {
    MinHeap<int> min_heap;

    min_heap.Insert(2);
    min_heap.Insert(1);
    EXPECT_EQ(min_heap.Min(), 1);
    min_heap.Insert(-1);
    EXPECT_EQ(min_heap.Min(), -1);
    EXPECT_EQ(min_heap.ExtractMin(), -1);
    EXPECT_EQ(min_heap.ExtractMin(), 1);
}
