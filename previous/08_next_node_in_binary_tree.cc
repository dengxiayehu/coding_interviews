#include <iostream>

#include "tree_link_node.h"

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (!pNode) {
            return NULL;
        }

        // 下面的判断错误，当前结点的下一个结点在中序遍历的时候和左结点没有关系！！
        // if (pNode->left) {
        //     // This node has left node, the next node must be the left node.
        //     return pNode->left;
        // }

        if (pNode->right) {
            // This node has right node, walk through the right tree to get the leftest node.
            TreeLinkNode* node = pNode->right;
            while (node && node->left) {
                node = node->left;
            }
            return node;
        } else {
            // 注意结点的层次关系，需要parent和current的配合，而不是parent与pNode。
            TreeLinkNode* parent = pNode->next;
            TreeLinkNode* current = pNode;
            while (parent && parent->right == current) {
                current = parent;
                parent = parent->next;
            }
            return parent;
        }
    }
};

int main(int argc, char const* argv[]) {
    // 根据书上的示例创建一个包含指向父结点的二叉树。
    TreeLinkNode* nodes[9];
    init_tree_in_book(nodes);

    for (int i = 0; i < 9; i++) {
        TreeLinkNode* node = Solution().GetNext(nodes[i]);
        if (node) {
            std::cout << static_cast<char>('a' + i) << "'s next is " << node->ch << std::endl;
        } else {
            std::cout << static_cast<char>('a' + i) << "'s next not found" << std::endl;
        }
    }

    destroy_tree(nodes);

    return 0;
}
