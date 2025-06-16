#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <stack>
#include <vector>

// https://leetcode.cn/problems/validate-stack-sequences/description/
// 题目：输入两个整数序列，第一个序列表示的栈的压入顺序，请判断第二个序列是否为该栈的弹出序列。（注意：每个序列中的值均
// 不相同）
// 思路：使用一个栈来模拟压栈和弹出，最后若栈为空则表示是一个弹出序列。压入一个元素之后尽量去弹栈。
class Solution31 {
public:
    bool validateStackSequences(const std::vector<int>& pushed, const std::vector<int>& popped) {
        if (pushed.empty() || popped.empty() || pushed.size() != popped.size()) {
            return false;
        }

        std::stack<int> st;
        const size_t pushed_size = pushed.size();
        size_t poped_idx = 0;
        for (size_t i = 0; i < pushed_size; i++) {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[poped_idx]) {
                st.pop();
                poped_idx++;
            }
        }

        return st.empty();
    }
};

TEST(ut_31, validateStackSequences) {
    Solution31 s;

    EXPECT_FALSE(s.validateStackSequences(std::vector<int>{1, 2, 3, 4, 5}, std::vector<int>{4, 5, 3, 1, 2}));
    EXPECT_TRUE(s.validateStackSequences(std::vector<int>{1, 2, 3, 4, 5}, std::vector<int>{4, 5, 3, 2, 1}));
    EXPECT_TRUE(s.validateStackSequences(std::vector<int>{2, 1, 0}, std::vector<int>{1, 2, 0}));
}
