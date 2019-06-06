# 重建二叉树

> 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不包含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

``` cpp
#include <iostream>
#include <vector>

using namespace std;

#define NELEM(arr) (sizeof(arr)/sizeof(arr[0]))

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty() || vin.empty() || pre.size() != vin.size()) {
            return NULL;
        }

        return reConstructBinaryTreeCore(
            &pre[0], 0, pre.size()-1, &vin[0], 0, vin.size()-1);
    }

private:
    TreeNode *reConstructBinaryTreeCore(
        int pre[], int startpre, int endpre,
        int in[], int startin, int endin) {
        int node_val = pre[startpre];
        TreeNode *node = new TreeNode(node_val); // root node
        // Find this root node in inorder.
        int iin;
        for (iin = startin; iin <= endin; iin++) {
            if (in[iin] == node_val) {
                break;
            }
        }
        if (iin > endin) {
            // Illegale preorder and inorder, cant reconstruct the btree.
            return NULL;
        }

        int left_node_num = iin-startin; // 左子树结点个数
        int right_node_num = endin-iin; // 右子数结点个数
        node->left = reConstructBinaryTreeCore(pre, startpre+1, startpre+left_node_num, in, startin, iin-1);
        node->right = reConstructBinaryTreeCore(pre, endpre-right_node_num+1, endpre, in, iin+1, endin);
        
        return node;
    }
};

void postorder_and_delete(TreeNode *node)
{
    if (node) {
        postorder_and_delete(node->left);
        postorder_and_delete(node->right);
        printf("%d ", node->val);
        delete node;
    }
}

int main(int argc, char const *argv[])
{
    int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    vector<int> vpre(pre, pre+NELEM(pre));
    int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
    vector<int> vin(in, in+NELEM(in));

    TreeNode *root = Solution().reConstructBinaryTree(vpre, vin);
    postorder_and_delete(root);

    return 0;
}
```

> 输出结果：  
7 4 2 5 8 6 3 1

这道题之前刷过，但印象不大，这次能够凭借对题目对理解重新独立做出来，给自己点赞。主要是关注左/右子树结点的个数。