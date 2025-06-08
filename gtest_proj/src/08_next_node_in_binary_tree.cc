#include "./test_helper.h"
#include "tree_link_node.h"

// leetcode 510：二叉搜索树中的中序后继 II
// 数据结构上将 TreeLinkNode 替换为 Node 结构，代码中的 next 替换为 parent
class Solution08 {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        // 分以下几种情况讨论：
        // 1. 若 pNode 是左叶子节点，则下一个节点是其父节点
        // 2. 若 pNode
        // 是中间有右子树的节点，则下一个节点是其右子树的最底最左叶子节点（考虑完全没有左叶子的情况，那应该返回右子树的根节点）
        // 3. 若 pNode 是中间无右子树的节点，则下一个节点是沿着右子节点回溯，找到第一个左子节点的父节点

        if (pNode == nullptr || IsOnlyRoot(pNode)) {
            return nullptr;
        }

        if (IsLeaf(pNode) && IsLeftChild(pNode)) {
            return pNode->next;
        } else if (pNode->right != nullptr) {
            return GetBottomLeft(pNode->right);
        } else {
            while (IsRightChild(pNode)) {
                pNode = pNode->next;
            }
            return pNode->next;
        }

        return nullptr;
    }

private:
    TreeLinkNode* GetBottomLeft(TreeLinkNode* pNode) {
        TreeLinkNode* candidate = pNode;
        while (true) {
            if (pNode->left == nullptr) {
                break;
            }
            pNode = pNode->left;
            candidate = pNode;
        }

        return candidate;
    }

    bool IsOnlyRoot(TreeLinkNode* pNode) {
        return pNode != nullptr && pNode->next == nullptr && pNode->left == nullptr && pNode->right == nullptr;
    }

    bool IsLeaf(TreeLinkNode* pNode) {
        return pNode != nullptr && pNode->left == nullptr && pNode->right == nullptr;
    }

    bool IsLeftChild(TreeLinkNode* pNode) {
        return pNode != nullptr && pNode->next != nullptr && pNode->next->left == pNode;
    }

    bool IsRightChild(TreeLinkNode* pNode) {
        return pNode != nullptr && pNode->next != nullptr && pNode->next->right == pNode;
    }
};

TEST(ut_08, GetNext) {
    Solution08 s;
    TreeLinkNode* nodes[9];
    /*
     *       a
     *     /   \
     *    b     c
     *   / \   / \
     *  d   e f   g
     *     / \
     *    h   i
     * */
    // array: [a, b, c, d, e, f, g, h, i]
    // index:  0  1  2  3  4  5  6  7  8
    init_tree_in_book(nodes);
    TreeLinkNode* node = nullptr;

    node = s.GetNext(nodes[0]);  // 'a'
    EXPECT_TRUE(node != nullptr && node->ch == 'f');

    node = s.GetNext(nodes[1]);  // 'b'
    EXPECT_TRUE(node != nullptr && node->ch == 'h');

    node = s.GetNext(nodes[2]);  // 'c'
    EXPECT_TRUE(node != nullptr && node->ch == 'g');

    node = s.GetNext(nodes[3]);  // 'd'
    EXPECT_TRUE(node != nullptr && node->ch == 'b');

    node = s.GetNext(nodes[4]);  // 'e'
    EXPECT_TRUE(node != nullptr && node->ch == 'i');

    node = s.GetNext(nodes[5]);  // 'f'
    EXPECT_TRUE(node != nullptr && node->ch == 'c');

    node = s.GetNext(nodes[6]);  // 'g'
    EXPECT_THAT(node, IsNull());

    node = s.GetNext(nodes[7]);  // 'h'
    EXPECT_TRUE(node != nullptr && node->ch == 'e');

    node = s.GetNext(nodes[8]);  // 'i'
    EXPECT_TRUE(node != nullptr && node->ch == 'a');

    destroy_tree(nodes);
}

TEST(ut_08, GetNextNoLeftChilds) {
    Solution08 s;
    TreeLinkNode* nodes[2];
    for (int i = 0; i < 2; i++) {
        TreeLinkNode* node = new TreeLinkNode('2' + i);
        nodes[i] = node;
    }
    nodes[0]->right = nodes[1];
    nodes[1]->next = nodes[0];
    TreeLinkNode* node = nullptr;

    node = s.GetNext(nodes[0]);  // '2'
    ASSERT_THAT(node, NotNull());
    EXPECT_EQ(node->ch, '3');

    for (int i = 0; i < 2; i++) {
        delete[] nodes[i];
    }
}
