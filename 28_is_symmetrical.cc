#include <iostream>

#include "tree_util.h"

using namespace std;

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (!pRoot) {  // empty tree
            return true;
        }

        return is_symmetrical_core(pRoot->left, pRoot->right);
    }

private:
    static bool is_symmetrical_core(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2) {
            return true;
        }
        if ((node1 && !node2) || (!node1 && node2)) {
            return false;
        }
        if (node1->val != node2->val) {
            return false;
        }

        return is_symmetrical_core(node1->left, node2->right) && is_symmetrical_core(node1->right, node2->left);
    }
};

int main(int argc, char* argv[]) {
    {
        int arr[] = {8, 6, 5, -1, -1, 7, -1, -1, 6, 7, -1, -1, 5, -1, -1};
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        bool res = Solution().isSymmetrical(root);
        cout << res << endl;
        delete_postorder(root);
    }

    {
        bool res = Solution().isSymmetrical(NULL);
        cout << res << endl;
    }

    {
        int arr[] = {1, -1, -1};
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        bool res = Solution().isSymmetrical(root);
        cout << res << endl;
        delete_postorder(root);
    }

    {
        int arr[] = {1, 2, 3, -1, -1, -1, -1};
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        bool res = Solution().isSymmetrical(root);
        cout << res << endl;
        delete_postorder(root);
    }

    {
        int arr[] = {1, -1, 2, -1, 3, -1, -1};
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        bool res = Solution().isSymmetrical(root);
        cout << res << endl;
        delete_postorder(root);
    }

    return 0;
}