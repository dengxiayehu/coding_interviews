#include <iostream>
#include <vector>

#include "tree_util.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int> > res;
        if (!root) {
            return res;
        }

        vector<int> path;
        int current_sum = 0;
        find_path_core(root, expectNumber, current_sum, path, res);

        return res;
    }

private:
    static void find_path_core(TreeNode *node, const int expect_number, int current_sum,
                               vector<int> &path, vector<vector<int> > &res) {
        path.push_back(node->val);
        current_sum += node->val;
        if (current_sum == expect_number && (!node->left) && (!node->right)) {
            // 当前结点就是叶结点且路径和就是current_sum，将路径添加到结果，并将当前结点从路径上删除。
            res.push_back(path);
            path.pop_back();
            return;
        }
        if (node->left) {
            find_path_core(node->left, expect_number, current_sum, path, res);
        }
        if (node->right) {
            find_path_core(node->right, expect_number, current_sum, path, res);
        }
        // 当前结点以及其子结点都已经被处理了，将其从路径上删除。
        path.pop_back();
    }
};

int main(int argc, char *argv[])
{
    {
        int arr[] = { 10, 5, 4, -1, -1, 7, -1, -1, 12, -1, -1 };
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        vector<vector<int> > res = Solution().FindPath(root, 22);
        for (vector<vector<int> >::iterator it = res.begin(); it != res.end(); it++) {
            for (vector<int>::iterator it1 = it->begin(); it1 != it->end(); it1++) {
                cout << *it1 << " ";
            }
            cout << endl;
        }
        delete_postorder(root);
    }

    {
        int arr[] = { 10, 5, 4, -1, -1, 7, -1, -1, 12, -1, -1 };
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        vector<vector<int> > res = Solution().FindPath(root, 0);
        for (vector<vector<int> >::iterator it = res.begin(); it != res.end(); it++) {
            for (vector<int>::iterator it1 = it->begin(); it1 != it->end(); it1++) {
                cout << *it1 << " ";
            }
            cout << endl;
        }
        delete_postorder(root);
    }

    {
        int arr[] = { 10, 5, 4, -1, -1, 7, -1, -1, 12, -1, -1 };
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        vector<vector<int> > res = Solution().FindPath(root, 12);
        for (vector<vector<int> >::iterator it = res.begin(); it != res.end(); it++) {
            for (vector<int>::iterator it1 = it->begin(); it1 != it->end(); it1++) {
                cout << *it1 << " ";
            }
            cout << endl;
        }
        delete_postorder(root);
    }

    return 0;
}