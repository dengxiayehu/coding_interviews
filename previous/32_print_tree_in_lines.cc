#include <iostream>
#include <queue>
#include <vector>

#include "tree_util.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (!pRoot) {
            return res;
        }

        queue<TreeNode*> q;
        TreeNode* node;
        int cur_lvl = 1;
        int next_lvl = 0;
        vector<int> v;

        q.push(pRoot);
        while (!q.empty()) {
            node = q.front();
            q.pop();
            v.push_back(node->val);
            if (node->left) {
                q.push(node->left);
                ++next_lvl;
            }
            if (node->right) {
                q.push(node->right);
                ++next_lvl;
            }
            if (--cur_lvl == 0) {
                res.push_back(v);
                v.clear();
                cur_lvl = next_lvl;
                next_lvl = 0;
            }
        }

        return res;
    }
};

int main(int argc, char* argv[]) {
    {
        int arr[] = {8, 6, 5, -1, -1, 7, -1, -1, 10, 9, -1, -1, 11, -1, -1};
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        vector<vector<int>> res = Solution().Print(root);
        for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); it++) {
            for (vector<int>::iterator it1 = it->begin(); it1 != it->end(); it1++) {
                cout << *it1 << " ";
            }
            cout << endl;
        }
        delete_postorder(root);
    }

    {
        int arr[] = {8, -1, -1};
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        vector<vector<int>> res = Solution().Print(root);
        for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); it++) {
            for (vector<int>::iterator it1 = it->begin(); it1 != it->end(); it1++) {
                cout << *it1 << " ";
            }
            cout << endl;
        }
        delete_postorder(root);
    }

    {
        int arr[] = {8, 7, 6, -1, -1, -1, -1};
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        vector<vector<int>> res = Solution().Print(root);
        for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); it++) {
            for (vector<int>::iterator it1 = it->begin(); it1 != it->end(); it1++) {
                cout << *it1 << " ";
            }
            cout << endl;
        }
        delete_postorder(root);
    }

    return 0;
}