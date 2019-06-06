#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
    }
};

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
            TreeLinkNode *node = pNode->right;
            while (node && node->left) {
                node = node->left;
            }
            return node;
        } else {
            // 注意结点的层次关系，需要parent和current的配合，而不是parent与pNode。
            TreeLinkNode *parent = pNode->next;
            TreeLinkNode *current = pNode;
            while (parent && parent->right == current) {
                current = parent;
                parent = parent->next;
            }
            return parent;
        }
    }
};

void init_tree(TreeLinkNode *nodes[9])
{
    for (int i = 1; i <= 9; i++) {
        TreeLinkNode *node = new TreeLinkNode(i);
        nodes[i-1] = node;
    }
    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[2];

    nodes[1]->left = nodes[3];
    nodes[1]->right = nodes[4];
    nodes[1]->next = nodes[0];

    nodes[2]->left = nodes[5];
    nodes[2]->right = nodes[6];
    nodes[2]->next = nodes[0];

    nodes[3]->next = nodes[1];

    nodes[4]->left = nodes[7];
    nodes[4]->right = nodes[8];
    nodes[4]->next = nodes[1];

    nodes[5]->next = nodes[2];

    nodes[6]->next = nodes[2];

    nodes[7]->next = nodes[4];

    nodes[8]->next = nodes[4];
}

void destroy_tree(TreeLinkNode *nodes[9])
{
    for (int i = 1; i <= 9; i++) {
        delete nodes[i-1];
    }
}

int main(int argc, char const *argv[])
{
    // 根据书上的示例创建一个包含指向父结点的二叉树。
    TreeLinkNode *nodes[9];
    init_tree(nodes);

    for (int i = 0; i < 9; i++) {
        TreeLinkNode *node = Solution().GetNext(nodes[i]);
        if (node) {
            cout << static_cast<char>('a'+i) << "'s next is " << static_cast<char>(node->val+'a'-1) << endl;
        } else {
            cout << static_cast<char>('a'+i) << "'s next not found" << endl;
        }
    }

    destroy_tree(nodes);

    return 0;
}
