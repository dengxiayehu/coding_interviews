#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "./min_heap.h"

// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
class Solution40_2 {
public:
    int findKthLargest(const std::vector<int>& nums, int k) {
        if (k <= 0 || nums.size() < k) {
            return 0;
        }

        MinHeap<int> min_heap;
        for (auto n : nums) {
            if (min_heap.Empty()) {
                min_heap.Insert(n);
            } else if (min_heap.Size() < k) {
                min_heap.Insert(n);
            } else if (min_heap.Min() < n) {
                min_heap.ExtractMin();
                min_heap.Insert(n);
            }
        }

        return min_heap.Min();
    }
};

TEST(ut_40_2, findKthLargestWithMinHeap) {
    Solution40_2 s;

    // sorted: 1, 2, 2, 3, 3, 4, 5, 5, 6
    //                        |
    EXPECT_EQ(s.findKthLargest(std::vector<int>{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4), 4);
}
