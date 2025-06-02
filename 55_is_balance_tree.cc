#include <iostream>

#include "tree_util.h"

using namespace std;

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return is_balanced(pRoot, depth);
    }

private:
    static bool is_balanced(TreeNode* node, int& depth) {
        if (!node) {
            depth = 0;
            return true;
        }
        int left, right;
        if (is_balanced(node->left, left) && is_balanced(node->right, right)) {
            if (left - right >= -1 && left - right <= 1) {
                depth = 1 + std::max(left, right);
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    {
        int arr[] = {5, 3, 2, -1, -1, 4, -1, -1, 7, 6, -1, -1, 8, -1, -1};
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        cout << Solution().IsBalanced_Solution(root) << endl;
        delete_postorder(root);
    }

    return 0;
}