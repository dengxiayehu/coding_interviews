#include <gtest/gtest.h>

#include <vector>

#include "tree_util.h"

// https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/description/
class Solution07 {
public:
    TreeNode* deduceTree(const std::vector<int>& preorder, const std::vector<int>& inorder) {
        // 无需做参数校验了，题目保证 preorder 和 inorder 输入非空且合法 [错误]
        // 虽然题目提示说 preorder 数组长度至少为 1，但用例里还是有空 vector 的存在，基本的判断还是需要
        if (preorder.empty() || preorder.size() != inorder.size()) {
            return nullptr;
        }
        return CreateInternal(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* CreateInternal(const std::vector<int>& preorder, int pl, int pr, const std::vector<int>& ineorder, int il,
                             int ir) {
        // 根节点
        int cur_root = preorder[pl];
        // 在中序遍历中定位根节点所在索引
        int in_idx = -1;
        for (int i = il; i <= ir; i++) {
            if (ineorder[i] == cur_root) {
                in_idx = i;
                break;
            }
        }
        // 在中序遍历中，左边部分为左子树
        int left_nodes_num = in_idx - il;
        // 在中序遍历中，右边部分为右子树
        int right_nodes_num = ir - in_idx;
        TreeNode* node = new TreeNode(cur_root);
        // 下面下标的计算尤其要注意，否则提交 leetcode 会出现不停递归栈溢出崩溃
        if (left_nodes_num > 0) {
            node->left = CreateInternal(preorder, pl + 1, pl + left_nodes_num, ineorder, il, in_idx - 1);
        }
        if (right_nodes_num > 0) {
            node->right = CreateInternal(preorder, pr - right_nodes_num + 1, pr, ineorder, in_idx + 1, ir);
        }

        return node;
    }
};

TEST(ut_07, DeduceTree) {
    Solution07 s;

    {
        std::vector<int> preorder = {3, 9, 20, 15, 7};
        std::vector<int> ineorder = {9, 3, 15, 20, 7};
        TreeNode* tree = s.deduceTree(preorder, ineorder);
        pre_order(tree);
        delete_postorder(tree);
    }

    {
        std::vector<int> preorder = {1, 2, 3};
        std::vector<int> ineorder = {2, 3, 1};
        TreeNode* tree = s.deduceTree(preorder, ineorder);
        pre_order(tree);
        delete_postorder(tree);
    }

    {
        std::vector<int> preorder = {3};
        std::vector<int> ineorder = {3};
        TreeNode* tree = s.deduceTree(preorder, ineorder);
        pre_order(tree);
        delete_postorder(tree);
    }

    {
        std::vector<int> preorder;
        std::vector<int> ineorder;
        TreeNode* tree = s.deduceTree(preorder, ineorder);
        pre_order(tree);
        delete_postorder(tree);
    }
}
