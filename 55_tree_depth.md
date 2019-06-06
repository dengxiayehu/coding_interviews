# 二叉树的深度

> 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

``` cpp
#include <iostream>

#include "tree_util.h"

using namespace std;

class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (!pRoot) {
            return 0;
        }
        return 1+std::max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
    }
};

int main(int argc, char *argv[])
{
    {
        int arr[] = { 5, 3, 2, -1, -1, 4, -1, -1, 7, 6, -1, -1, 8, -1, -1 };
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        cout << Solution().TreeDepth(root) << endl;
        delete_postorder(root);
    }

    return 0;
}
```

> 输出结果：

``` txt
3
```