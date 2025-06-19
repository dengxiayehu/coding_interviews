#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/majority-element/
// 题目：数组中有一个数字出现的次数超过了数组长度的一半，请找出这个数字。
// 思路：假设对这个数组进行排序，那么位置在 n/2 的元素必然是这个数字。
// 平均时间复杂度是 O(n)，但会对原始数组重排，若面试官说不允许修改数组元素，则此算法不适用。
class Solution39 {
public:
    int majorityElement(std::vector<int>& nums) {
        int res = 0;
        qsort_internal(nums, 0, nums.size() - 1, res);

        return res;
    }

private:
    void qsort_internal(std::vector<int>& nums, int l, int r, int& res) {
        int idx = partition(nums, l, r);
        int medium_idx = nums.size() / 2;
        if (idx == medium_idx) {
            res = nums[idx];
            return;
        } else if (idx < medium_idx) {
            qsort_internal(nums, idx + 1, r, res);
        } else {
            qsort_internal(nums, l, idx - 1, res);
        }
    }

    int partition(std::vector<int>& nums, int l, int r) {
        // 选取参考元素为区间最左侧元素
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

TEST(ut_39, majorityElement) {
    Solution39 s;

    std::vector<int> nums1{3, 2, 3};
    EXPECT_EQ(s.majorityElement(nums1), 3);
    std::vector<int> nums2{2, 2, 1, 1, 1, 2, 2};
    EXPECT_EQ(s.majorityElement(nums2), 2);
    std::vector<int> nums3{4, 5, 4};
    EXPECT_EQ(s.majorityElement(nums3), 4);
}
