#include <iostream>

#include "tree_util.h"

using namespace std;

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;

        if (pRoot1 && pRoot2) {
            if (pRoot1->val == pRoot2->val) {
                // Found the node with the same value of sub-tree's root.
                // Let check whether they are the same.
                result = is_same_tree(pRoot1, pRoot2);
            }
            if (!result) {
                // Let's find out in the left sub-tree.
                result = HasSubtree(pRoot1->left, pRoot2);
            }
            if (!result) {
                // Let's find out in the right sub-tree.
                result = HasSubtree(pRoot1->right, pRoot2);
            }
        }

        return result;
    }

private:
    static bool is_same_tree(TreeNode *t, TreeNode *sub) {
        if (!sub) { // sub comes to the end of leaf
            return true;
        }
        if (!t) { // t comes to the end of leaf, not match
            return false;
        }
        if (t->val != sub->val) { // value not match
            return false;
        }
        return is_same_tree(t->left, sub->left) &&
               is_same_tree(t->right, sub->right);
    }
};

int main(int argc, char *argv[])
{
/*
   1
 2  3
4  5
    6
*/
    int arr[] = { 1, 2, 4, -1, -1, -1, 3, 5, -1, 6, -1, -1, -1 };
    // int arr[] = { 1, 2, 4, -1, -1, -1, -1 };
    TreeNode *root = create_pre_order(arr, NELEM(arr));
    pre_order(root);

    int arr_sub[] = { 3, 5, -1, 6, -1, -1, -1 };
    // int arr_sub[] = { 3, 5, -1, -1, -1, -1 };
    // int arr_sub[] = { 3, -1, -1 };
    TreeNode *root_sub = create_pre_order(arr_sub, NELEM(arr_sub));
    pre_order(root_sub);

    bool res = Solution().HasSubtree(root, root_sub);
    cout << res << endl;

    res = Solution().HasSubtree(root, NULL);
    cout << res << endl;

    res = Solution().HasSubtree(NULL, root_sub);
    cout << res << endl;

    res = Solution().HasSubtree(root_sub, root);
    cout << res << endl;

    delete_postorder(root);
    delete_postorder(root_sub);
    
    return 0;
}