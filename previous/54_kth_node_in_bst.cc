#include <iostream>

#include "tree_util.h"

using namespace std;

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (k <= 0) {
            return NULL;
        }
        TreeNode* res = NULL;
        kth_node_core(pRoot, k, res);
        return res;
    }

private:
    static void kth_node_core(TreeNode* node, int& k, TreeNode*& res) {
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

int main(int argc, char* argv[]) {
    {
        int arr[] = {5, 3, 2, -1, -1, 4, -1, -1, 7, 6, -1, -1, 8, -1, -1};
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        TreeNode* res = Solution().KthNode(root, 3);
        if (res) {
            cout << res->val << endl;
        } else {
            cout << "NULL" << endl;
        }
        delete_postorder(root);
    }

    return 0;
}