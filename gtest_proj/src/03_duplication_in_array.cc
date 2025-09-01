#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "./matchers.h"

// 题目：找出数组中重复的数字
// 在一个长度为 n 的数组里的所有数字都在 [0, n - 1] 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道
// 每个数字重复了几次。请找出数组中任意一个重复的数字。
// https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/description/
class Solution03 {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        // 快速校验
        if (numbers == nullptr || length <= 1) {
            return false;
        }
        // 判定元素的值符合题目预期
        for (int i = 0; i < length; i++) {
            if (numbers[i] < 0 || numbers[i] >= length) {
                return false;
            }
        }
        for (int i = 0; i < length; i++) {
            // 既然数组元素的值范围在 [0, n - 1]，则我们将这些值放置到数组对应的索引上。
            while (numbers[i] != i) {  // 值 numbers[i] 不在预期位置上
                int tmp = numbers[i];
                int remote = numbers[tmp];  // 现在预期位置上的值
                if (tmp == remote) {        // 现在预期位置上的值已经摆放正确了，则找到一个重复元素
                    if (duplication != nullptr) {
                        *duplication = tmp;
                    }
                    return true;
                }
                numbers[tmp] = tmp;
                numbers[i] = remote;
            }
        }
        return false;
    }
};

TEST(ut_03, DuplicationInArray) {
    Solution03 s;
    int duplication = 0;

    // 多个重复的数字
    std::vector<int> numbers = {2, 3, 1, 0, 2, 5, 3};
    EXPECT_TRUE(s.duplicate(numbers.data(), numbers.size(), &duplication));
    EXPECT_THAT(duplication, AnyOfArray({2, 3}));

    // 一个重复的数字
    duplication = 0;
    std::vector<int> numbers1 = {2, 3, 1, 0, 2, 5};
    EXPECT_TRUE(s.duplicate(numbers1.data(), numbers1.size(), &duplication));
    EXPECT_THAT(duplication, AnyOfArray({2}));

    // 不包含重复的数字
    duplication = 0;
    std::vector<int> numbers2 = {1, 0, 2, 5, 3};
    EXPECT_FALSE(s.duplicate(numbers2.data(), numbers2.size(), &duplication));

    // 长度为 n 的数组中包含 [0, n-1] 之外的数字
    duplication = 0;
    std::vector<int> numbers3 = {2, 3, 1, 0, 2, 5, 3, -1};
    EXPECT_FALSE(s.duplicate(numbers3.data(), numbers3.size(), &duplication));

    // 输入空指针
    duplication = 0;
    std::vector<int> numbers4;
    EXPECT_FALSE(s.duplicate(numbers4.data(), numbers3.size(), &duplication));
}
