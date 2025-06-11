# 二叉搜索树与双向链表

> 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

``` cpp
#include <iostream>

#include "tree_util.h"

using namespace std;

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree) {
            return NULL;
        }

        TreeNode *prev_last = NULL;
        convert_core(pRootOfTree, prev_last);
        while (prev_last->left) {
            prev_last = prev_last->left;
        }

        return prev_last;
    }

private:
    static void convert_core(TreeNode *node, TreeNode *&prev_last) {
        if (node->left) {
            convert_core(node->left, prev_last);
        }
        if (prev_last) {
            prev_last->right = node;
        }
        node->left = prev_last;
        prev_last = node;

        if (node->right) {
            convert_core(node->right, prev_last);
        }
    }
};

int main(int argc, char *argv[])
{
    {
        int arr[] = { 10, 6, 4, -1, -1, 8, -1, -1, 14, 12, -1, -1, 16, -1, -1 };
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        TreeNode *p = Solution().Convert(root), *q;
        while (p) {
            q = p->right;
            cout << p->val << " ";
            delete p;
            p = q;
        }
        cout << endl;
        // delete_postorder(root);
    }

     {
        int arr[] = { 10, 9, 8, -1, -1, -1, -1 };
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        TreeNode *p = Solution().Convert(root), *q;
        while (p) {
            q = p->right;
            cout << p->val << " ";
            delete p;
            p = q;
        }
        cout << endl;
        // delete_postorder(root);
    }

    {
        int arr[] = { 10, -1, 11, -1, 12, -1, -1 };
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        TreeNode *p = Solution().Convert(root), *q;
        while (p) {
            q = p->right;
            cout << p->val << " ";
            delete p;
            p = q;
        }
        cout << endl;
        // delete_postorder(root);
    }

    return 0;
}
```

> 输出结果：  
walk with stack:  
10 6 4 8 14 12 16  
4 6 8 10 12 14 16  
walk with stack:  
10 9 8  
8 9 10  
walk with stack:  
10 11 12  
10 11 12