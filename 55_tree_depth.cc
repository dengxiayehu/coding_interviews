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