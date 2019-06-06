#include <iostream>

#include "tree_util.h"

using namespace std;

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (!pRoot) {
            return;
        }

        // Exchange left right sub-tree's root node.
        TreeNode *t = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = t;

        // Handle left sub-tree.
        Mirror(pRoot->left);
        // Handle right sub-tree.
        Mirror(pRoot->right);
    }
};

int main(int argc, char *argv[])
{
/*
  1
 2
3
*/
    {
        int arr[] = { 1, 2, 3, -1, -1, -1, -1 };
        TreeNode *root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        Solution().Mirror(root);
        pre_order(root);
        delete_postorder(root);
    }

    {
/*
   1
 2  3
4  5
    6

  1
3  2
 5  4
6
1 3 5 6 2 4
*/
        int arr[] = { 1, 2, 4, -1, -1, -1, 3, 5, -1, 6, -1, -1, -1 };
        TreeNode *root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        Solution().Mirror(root);
        pre_order(root);
        delete_postorder(root);
    }

    {
/*
  1

  1
*/
        int arr[] = { 1, -1, -1 };
        TreeNode *root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        Solution().Mirror(root);
        pre_order(root);
        delete_postorder(root);
    }

    return 0;
}