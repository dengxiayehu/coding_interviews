# 之字形打印二叉树

> 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

``` cpp
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if (!pRoot) {
            return res;
        }

        TreeNode *node;
        bool left2right = true;
        vector<int> v;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        stack<TreeNode*> *s_cur = &s1;
        stack<TreeNode*> *s_next = &s2;
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
                stack<TreeNode*> *tmp = s_cur;
                s_cur = s_next;
                s_next = tmp;
            }
        }

        return res;
    }
};
```

> 输出结果：  
walk with stack:  
8 6 5 7 10 9 11  
8  
10 6  
5 7 9 11  
walk with stack:  
1 2 4 8 9 5 10 11 3 6 12 13 7 14 15  
1  
3 2  
4 5 6 7  
15 14 13 12 11 10 9 8  
walk with stack:  
1 2 3  
1  
2  
3