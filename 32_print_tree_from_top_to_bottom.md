# 从上至下打印二叉树

> 从上往下打印出二叉树的每个节点，同层节点从左至右打印。

``` cpp
#include <iostream>
#include <vector>
#include <queue>

#include "tree_util.h"

using namespace std;

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            res.push_back(node->val);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    {
        int arr[] = { 8, 6, 5, -1, -1, 7, -1, -1, 10, 9, -1, -1, 11, -1, -1 };
        TreeNode *root = create_pre_order(arr, NELEM(arr));
        pre_order(root);
        vector<int> res = Solution().PrintFromTopToBottom(root);
        for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
        delete_postorder(root);
    }
    return 0;
}
```

> 输出结果：  
walk with stack:  
8 6 5 7 10 9 11  
8 6 10 5 7 9 11