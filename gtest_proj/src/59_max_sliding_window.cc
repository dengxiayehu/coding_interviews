#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <deque>
#include <vector>

// https://leetcode.cn/problems/sliding-window-maximum/
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，如果输入数组{2, 3, 4, 2, 6, 2, 5, 1} 以及滑动
// 窗口的大小为 3，那么一共存在 6 个滑动窗口，它们的最大值分别为 {4, 4, 6, 6, 6, 5}。
//
// 1. 单调队列
// 2. front 永远是当前窗口的最大值
// 3. 遇到一个新的值时，由 back 往前打，小于等于它的都被干掉
// 4. front 在超过窗口区域时自己退出
// 5. 循环结束时别忘记还有一个值
class Solution59 {
public:
    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
        std::vector<int> res;
        if (nums.empty() || k < 1 || nums.size() < k) {
            return res;
        }

        std::deque<int> dque;
        for (int i = 0; i < k; ++i) {
            int n = nums[i];
            while (!dque.empty() && n >= nums[dque.back()]) {
                dque.pop_back();
            }
            dque.push_back(i);
        }

        const int nums_size = nums.size();
        for (int i = k; i < nums_size; ++i) {
            int n = nums[i];
            res.push_back(nums[dque.front()]);

            while (!dque.empty() && n >= nums[dque.back()]) {
                dque.pop_back();
            }

            if (!dque.empty() && dque.front() <= (i - k)) {
                dque.pop_front();
            }

            dque.push_back(i);
        }
        res.push_back(nums[dque.front()]);

        return res;
    }
};

MATCHER_P(VectorContentMatcher, vi, "") {
    const std::vector<int>& v = arg;
    for (size_t i = 0; i < vi.size(); i++) {
        if (v[i] != vi[i]) {
            return false;
        }
    }

    return true;
}

TEST(ut_59, maxSlidingWindow) {
    Solution59 s;

    EXPECT_THAT(s.maxSlidingWindow(std::vector<int>{1, 3, -1, -3, 5, 3, 6, 7}, 3),
                VectorContentMatcher(std::vector<int>{3, 3, 5, 5, 6, 7}));
}
