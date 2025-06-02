#include <iostream>
#include <stack>

#include "tree_util.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (!pRoot) {
            return res;
        }

        TreeNode* node;
        bool left2right = true;
        vector<int> v;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        stack<TreeNode*>* s_cur = &s1;
        stack<TreeNode*>* s_next = &s2;
        s_cur->push(pRoot);
        while (!s_cur->empty() || !s_next->empty()) {
            node = s_cur->top();
            s_cur->pop();
            v.push_back(node->val);
            if (left2right) {
                if (node->left) {
                    s_next->push(node->left);
                }
                if (node->right) {
                    s_next->push(node->right);
                }
            } else {
                if (node->right) {
                    s_next->push(node->right);
                }
                if (node->left) {
                    s_next->push(node->left);
                }
            }
            if (s_cur->empty()) {
                // 当前层打印完毕。
                res.push_back(v);
                v.clear();

                left2right = !left2right;
                stack<TreeNode*>* tmp = s_cur;
                s_cur = s_next;
                s_next = tmp;
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
        int arr[] = {1, 2, 4,  8,  -1, -1, 9,  -1, -1, 5,  10, -1, -1, 11, -1, -1,
                     3, 6, 12, -1, -1, 13, -1, -1, 7,  14, -1, -1, 15, -1, -1};
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
        int arr[] = {1, 2, 3, -1, -1, -1, -1};
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