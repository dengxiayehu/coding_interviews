#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "./matchers.h"

// 题目：不修改数组找出重复的数字。
// 在一个长度为 n + 1 的数组里的所有数字都在 [1, n] 的范围内，所以数组中至少有一个数字是重复的。请找出数组中任意一个重复
// 的数字，但不能修改输入的数组。
// leetcode 287: https://leetcode.cn/problems/find-the-duplicate-number/description/
// 本题 duplicate_binary_count 算法能解决 leetcode 287 问题，但不是最优，因为该题有限制只有一个重复的数字
class Solution03_1 {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        // return duplicate_use_tmp_array(numbers, length, duplication);
        return duplicate_binary_count(numbers, length, duplication);
    }

private:
    // 时间复杂度 O(n)，空间复杂度 O(n)
    bool duplicate_use_tmp_array(int numbers[], int length, int* duplication) {
        // 数组为空或者不可能出现重复数字的情况
        if (numbers == nullptr || length <= 1) {
            return false;
        }
        // 分配临时数组并元素均初始化为 0
        int* tmp_array = new int[length]();
        for (int i = 0; i < length; i++) {
            int val = numbers[i];
            // 判定元素的值在 [1, length - 1] 之间
            if (val < 1 || val >= length) {
                return false;
            }
            if (tmp_array[val] != 0) {
                if (duplication != nullptr) {
                    *duplication = val;
                }
                return true;
            }
            // 将元素 val 放置到 tmp_array 的 val 索引处，相当于一种映射关系
            tmp_array[val] = val;
        }
        // 删除临时数组
        delete[] tmp_array;
        return false;
    }

    // 时间复杂度 O(nlog(n))，空间复杂度 O(1)
    // 两分思想，[l, r] 中间的数字 m = (l + r) / 2，则
    // [l, m] 若有超过 m + 1 - l 个数则存在重复数字，[m + 1, r] 若有超过 r - m 个数则存在重复数字
    bool duplicate_binary_count(int numbers[], int length, int* duplication) {
        if (numbers == nullptr || length <= 1) {
            return false;
        }
        int l = 1;
        int r = length - 1;
        while (true) {
            int m = l + (r - l) / 2;  // 比 (l + r) / 2 更优，避免了整型益处
            int expect_left_num = m + 1 - l;
            int actual_left_num = count_in_range(numbers, length, l, m);
            if (actual_left_num > expect_left_num) {
                if (expect_left_num == 1) {
                    if (duplication != nullptr) {
                        *duplication = l;
                        return true;
                    }
                }
                r = m;
                continue;
            }

            int expect_right_num = r - m;
            int actual_right_num = count_in_range(numbers, length, m + 1, r);
            if (actual_right_num > expect_right_num) {
                if (expect_right_num == 1) {
                    if (duplication != nullptr) {
                        *duplication = r;
                        return true;
                    }
                }
                l = m + 1;
                continue;
            }
        }
        return false;
    }

    int count_in_range(int numbers[], int length, int l, int r) {
        int count = 0;
        for (int i = 0; i < length; i++) {
            int val = numbers[i];
            if (val >= l && val <= r) {
                ++count;
            }
        }
        return count;
    }
};

TEST(ut_03_1, DuplicationInArrayNoEdit) {
    Solution03_1 s;
    int duplication = 0;

    // 多个重复的数字
    std::vector<int> numbers = {2, 3, 5, 4, 3, 2, 6, 7};
    EXPECT_TRUE(s.duplicate(numbers.data(), numbers.size(), &duplication));
    EXPECT_THAT(duplication, AnyOfArray({2, 3}));

    duplication = 0;
    std::vector<int> numbers1 = {1, 4, 3, 2, 3};
    EXPECT_TRUE(s.duplicate(numbers1.data(), numbers1.size(), &duplication));
    EXPECT_THAT(duplication, AnyOfArray({3}));

    duplication = 0;
    std::vector<int> numbers2 = {1, 4, 4, 3, 2, 3};
    EXPECT_TRUE(s.duplicate(numbers2.data(), numbers2.size(), &duplication));
    EXPECT_THAT(duplication, AnyOfArray({3, 4}));

    duplication = 0;
    std::vector<int> numbers3;
    EXPECT_FALSE(s.duplicate(numbers3.data(), numbers3.size(), &duplication));
}
