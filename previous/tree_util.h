#pragma once

#include <iostream>
#include <queue>
#include <stack>

#include "macro_util.h"

#define WALK_WITH_STACK 1

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

inline TreeNode* __create_pre_order(std::queue<int>& q) {
    if (q.empty()) {
        return nullptr;
    }

    int v = q.front();
    q.pop();
    if (v == -1) {
        return nullptr;
    }

    TreeNode *node = new TreeNode(v);
    node->left = __create_pre_order(q);
    node->right = __create_pre_order(q);

    return node;
}

// 前序遍历创建二叉数
inline TreeNode* create_pre_order(int arr[], const int n) {
    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(arr[i]);
    }

    return __create_pre_order(q);
}

// 前序遍历打印二叉数，分递归法和非递归法
inline void pre_order(TreeNode* root) {
    if (!root) {
        return;
    }

#if !defined(WALK_WITH_STACK) || (WALK_WITH_STACK == 0)
    std::cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
#else
    std::cout << "walk with stack: " << std::endl;
    TreeNode *node = root;
    std::stack<TreeNode*> s;
    while (node || !s.empty()) {
        if (node) {  // find a node in tree, print it first
            std::cout << node->val << " ";
            s.push(node);       // push this node into stack
            node = node->left;  // try left sub-tree first
        } else {
            // walk right sub-tree
            node = s.top();
            s.pop();
            node = node->right;
        }
    }
    std::cout << std::endl;
#endif
}

// 后序遍历删除二叉树，根节点必须最后被删除
inline void delete_postorder(TreeNode*& node) {
    if (!node) {
        return;
    }

    delete_postorder(node->left);
    delete_postorder(node->right);
    delete node;
    node = nullptr;
}
