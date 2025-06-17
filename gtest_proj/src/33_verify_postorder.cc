#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

// 题目：输入一个整数数组，判断该数组是不是某个二叉搜索树的后序遍历序列。假设输入的数组的任意两个数字互不相同。
// 二叉搜索树的定义是每个节点的左子树所有节点值都小于该节点值，右子树所有节点值都大于该节点值。
class Solution33 {
public:
    bool verifyPostorder(const std::vector<int>& postorder) {
        if (postorder.empty()) {
            return false;
        }

        return verify_postorder_internal(postorder, 0, postorder.size() - 1);
    }

private:
    bool verify_postorder_internal(const std::vector<int>& postorder, int l, int r) {
        if (l == r) {
            return true;
        }

        int range_root = postorder[r];
        int rl = -1;
        if (postorder[r - 1] > range_root) {
            // 肯定存在右子树，找到所有比 range_root 大的元素
            rl = r - 2;
            while (rl >= l && postorder[rl] > range_root) {
                rl--;
            }
            if (rl < l) {
                // 只有右子树
                return verify_postorder_internal(postorder, l, r - 1);
            } else {
                ++rl;
            }
        }

        // 必然存在左子树，找到所有比 range_root 小的元素
        int ll = rl > 0 ? rl - 1 : r - 1;
        while (ll >= l && postorder[ll] < range_root) {
            ll--;
        }
        if (ll >= l) {
            return false;
        }
        ++ll;

        int lr = r - 1;
        bool res = true;
        if (rl > 0) {
            lr = rl - 1;
            res = verify_postorder_internal(postorder, rl, r - 1);
        }
        return res && verify_postorder_internal(postorder, ll, lr);
    }
};

TEST(ut_33, verifyPostorder) {
    Solution33 s;

    EXPECT_TRUE(s.verifyPostorder(std::vector<int>{5, 7, 6, 9, 11, 10, 8}));
    EXPECT_FALSE(s.verifyPostorder(std::vector<int>{7, 4, 6, 5}));
}
