#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <optional>
#include <stack>
#include <vector>

// https://leetcode.cn/problems/verify-preorder-sequence-in-binary-search-tree/
// 借助单调栈来做。
class Solution33_2 {
public:
    bool verifyPreorder(const std::vector<int>& preorder) {
        if (preorder.empty()) {
            return false;
        }

        std::optional<int> min;  // 若不用 std::optional 也可以初始化 min = INT_MIN
        std::stack<int> st;
        for (const auto v : preorder) {
            if (st.empty()) {
                st.push(v);
            } else {
                if (min && v < *min) {
                    return false;
                }
                // 下面过程虽可以合并，但更好理解一些
                if (st.top() > v) {
                    st.push(v);
                } else {
                    // v 比栈顶元素大，说明 v 是“某个节点”的右节点
                    while (!st.empty() && st.top() < v) {
                        min = st.top();  // min 保存的最后一个比 v 小的节点，就是“某个节点”
                        st.pop();
                    }
                    st.push(v);
                }
            }
        }

        return true;
    }
};

TEST(ut_33_2, verifyPreorderMonoStack) {
    Solution33_2 s;

    EXPECT_TRUE(s.verifyPreorder(std::vector<int>{5, 2, 1, 3, 6}));
    EXPECT_FALSE(s.verifyPreorder(std::vector<int>{5, 2, 6, 1, 3}));
}
