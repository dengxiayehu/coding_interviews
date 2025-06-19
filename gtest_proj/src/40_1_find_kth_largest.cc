#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
// 题目：给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。（排序后的倒数第 k 个数，最后一个数是倒数第 1 个数）
// 也就是索引为 nums.size() - k 的数。
// 这道题需要对 partition() 函数做优化，例如使用 medium3() 函数来取哨兵值，否则 leetcode 击败率感人。
class Solution40_1 {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        if (k <= 0 || nums.size() < k) {
            return 0;
        }

        int target_idx = nums.size() - k;
        qsort_internal(nums, 0, nums.size() - 1, target_idx);

        return nums[target_idx];
    }

private:
    void myswap(std::vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    int medium3(const std::vector<int>& nums, int i, int m, int j) {
        return nums[i] > nums[m] ? (nums[m] > nums[j] ? m : (nums[i] > nums[j] ? j : i))
                                 : (nums[i] > nums[j] ? i : (nums[m] > nums[j] ? j : m));
    }

    void qsort_internal(std::vector<int>& nums, int l, int r, int target_idx) {
        int idx = partition(nums, l, r);
        if (idx == target_idx) {
            return;
        } else if (idx > target_idx) {
            qsort_internal(nums, l, idx - 1, target_idx);
        } else {
            qsort_internal(nums, idx + 1, r, target_idx);
        }
    }

    int partition(std::vector<int>& nums, int l, int r) {
        int m = l + ((r - l) >> 1);
        int medium_idx = medium3(nums, l, m, r);
        if (medium_idx != l) {
            myswap(nums, medium_idx, l);
        }
        int target = nums[l];
        int i = l;
        int j = r;
        while (i < j) {
            while (i < j && nums[j] >= target) {
                --j;
            }
            nums[i] = nums[j];
            while (i < j && nums[i] <= target) {
                ++i;
            }
            nums[j] = nums[i];
        }
        nums[i] = target;

        return i;
    }
};

TEST(ut_40_1, findKthLargest) {
    Solution40_1 s;

    std::vector<int> nums{4, 5, 1, 6, 2, 7, 3, 8};
    auto res = s.findKthLargest(nums, 2);
    EXPECT_EQ(res, 7);
}
