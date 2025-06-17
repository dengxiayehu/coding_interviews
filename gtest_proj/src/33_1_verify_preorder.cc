#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// https://leetcode.cn/problems/verify-preorder-sequence-in-binary-search-tree/
// 题目：输入一个整数数组，判断该数组是不是某个二叉搜索树的前序遍历序列。假设输入的数组的任意两个数字互不相同。
// 二叉搜索树的定义是每个节点的左子树所有节点值都小于该节点值，右子树所有节点值都大于该节点值。
class Solution33_1 {
public:
    bool verifyPreorder(const std::vector<int>& preorder) {
        if (preorder.empty()) {
            return false;
        }

        return verify_preorder_internal(preorder, 0, preorder.size() - 1);
    }

private:
    bool verify_preorder_internal(const std::vector<int>& preorder, int l, int r) {
        if (l == r) {
            return true;
        }

        int range_root = preorder[l];
        int lr = -1;
        if (preorder[l + 1] < range_root) {
            // 存在左子树
            lr = l + 2;
            while (lr <= r && preorder[lr] < range_root) {
                ++lr;
            }
            if (lr > r) {
                // 都是左子树
                return verify_preorder_internal(preorder, l + 1, r);
            } else {
                --lr;
            }
        }

        // 肯定存在右子树
        int rr = lr < 0 ? l + 1 : lr + 1;
        while (rr <= r && preorder[rr] > range_root) {
            ++rr;
        }
        if (rr <= r) {
            // 不全是右子树
            return false;
        }

        int rl = l + 1;
        bool res = true;
        if (lr > 0) {
            // 存在左子树
            res = verify_preorder_internal(preorder, l + 1, lr);
            rl = lr + 1;  // 右子树左界
        }
        return res && verify_preorder_internal(preorder, rl, r);
    }
};

TEST(ut_33_1, verifyPreorder) {
    Solution33_1 s;

    EXPECT_TRUE(s.verifyPreorder(std::vector<int>{5, 2, 1, 3, 6}));
    EXPECT_FALSE(s.verifyPreorder(std::vector<int>{5, 2, 6, 1, 3}));
}
