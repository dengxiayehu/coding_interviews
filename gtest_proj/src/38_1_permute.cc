#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// 全排列算法。
// https://leetcode.cn/problems/permutations/
// 结合标记数组使用。固定一个元素，然后在整个数组中查找其他剩余值的可能值，用完就重置标志被其他排列使用。
class Solution38_1 {
public:
    std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        if (nums.empty()) {
            return res;
        }

        std::vector<int> cand;
        std::vector<bool> used(nums.size(), false);
        permute_internal(res, nums, cand, used);

        return res;
    }

private:
    void permute_internal(std::vector<std::vector<int>>& res, const std::vector<int>& nums, std::vector<int>& cand,
                          std::vector<bool>& used) {
        if (cand.size() == nums.size()) {
            res.push_back(cand);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            used[i] = true;
            cand.push_back(nums[i]);
            permute_internal(res, nums, cand, used);
            cand.pop_back();
            used[i] = false;
        }
    }
};

MATCHER_P(PermutedMatcher, vi, "") {
    std::vector<std::vector<int>> res = arg;
    for (const auto& v : vi) {
        auto found_it = std::find(res.begin(), res.end(), v);
        if (found_it == res.end()) {
            return false;
        }
        res.erase(found_it);
    }
    EXPECT_TRUE(res.empty());
    return true;
}

TEST(ut_38_1, permuteMarker) {
    Solution38_1 s;

    std::vector<int> nums{1, 2, 3};
    auto res = s.permute(nums);
    std::vector<std::vector<int>> wanted{std::vector<int>{1, 2, 3}, std::vector<int>{1, 3, 2},
                                         std::vector<int>{2, 1, 3}, std::vector<int>{2, 3, 1},
                                         std::vector<int>{3, 2, 1}, std::vector<int>{3, 1, 2}};
    EXPECT_THAT(res, PermutedMatcher(wanted));
}
