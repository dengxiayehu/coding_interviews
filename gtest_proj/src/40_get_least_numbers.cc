#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "./matchers.h"

// 题目：输入 n 个整数，找出其中最小的 k 个数。例如输入 4, 5, 1, 6, 2, 7, 3, 8 这 8 个数字，则最小的 4 个数 1, 2, 3, 4。
// 其实就是求排序后数组中 index=k-1 的元素
class Solution40 {
public:
    std::vector<int> getLeastNumber(std::vector<int>& nums, int k) {
        std::vector<int> res;

        if (k <= 0 || nums.size() <= k - 1) {
            return res;
        }

        qsort_internal(nums, 0, nums.size() - 1, k - 1);

        res.assign(nums.begin(), nums.begin() + k);

        return res;
    }

private:
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

TEST(ut_40, getLeastNumber) {
    Solution40 s;

    std::vector<int> nums{4, 5, 1, 6, 2, 7, 3, 8};
    auto res = s.getLeastNumber(nums, 4);
    EXPECT_THAT(res, UnorderedElementsAreArray(std::vector{1, 3, 2, 4}));
}
