# 二叉搜索树的第k结点

> 给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。

``` txt
    5
 3    7
2 4  6 8
中序遍历结果为：2 3 4 5 6 7 8，可以看出，中序遍历的第k个结点正好是第k小的数。
```

``` cpp
#include <iostream>

#include "tree_util.h"

using namespace std;

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (k <= 0) {
            return NULL;
        }
        TreeNode *res = NULL;
        kth_node_core(pRoot, k, res);
        return res;
    }

private:
    static void kth_node_core(TreeNode *node, int &k, TreeNode *&res) {
        if (!node || k == 0) {
            return;
        }
        kth_node_core(node->left, k, res);
        if (k-- == 1) {
            res = node;
            return;
        }
        kth_node_core(node->right, k, res);
    }
};

int main(int argc, char *argv[])
{
    {
        int arr[] = { 5, 3, 2, -1, -1, 4, -1, -1, 7, 6, -1, -1, 8, -1, -1 };
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        TreeNode *res = Solution().KthNode(root, 3);
        if (res) {
            cout << res->val << endl;
        } else {
            cout << "NULL" << endl;
        }
        delete_postorder(root);
    }

    return 0;
}
```

> 输出结果：

``` txt
walk with stack: 
5 3 2 4 7 6 8 
4
```