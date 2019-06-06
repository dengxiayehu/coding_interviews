#ifndef TREE_UTIL_H
#define TREE_UTIL_H

#include <iostream>
#include <queue>
#include <stack>

#include "macro_util.h"

#define WALK_WITH_STACK 1

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

static TreeNode *__create_pre_order(std::queue<int> &q)
{
    if (q.empty()) {
        return NULL;
    }

    int v = q.front();
    q.pop();
    if (v == -1) {
        return NULL;
    }

    TreeNode *node = new TreeNode(v);
    node->left = __create_pre_order(q);
    node->right = __create_pre_order(q);

    return node;
}

static TreeNode *create_pre_order(int arr[], const int n)
{
    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(arr[i]);
    }

    return __create_pre_order(q);
}

static void pre_order(TreeNode *root)
{
    if (!root) {
        return;
    }

#if ! defined(WALK_WITH_STACK) || (WALK_WITH_STACK == 0)
    std::cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
#else
    std::cout << "walk with stack: " << std::endl;
    TreeNode *node = root;
    std::stack<TreeNode*> s;
    while (node || !s.empty()) {
        if (node) { // find a node in tree, print it first
            std::cout << node->val << " ";
            s.push(node); // push this node into stack
            node = node->left; // try left sub-tree first
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

static void delete_postorder(TreeNode *&node)
{
    if (!node) {
        return;
    }

    delete_postorder(node->left);
    delete_postorder(node->right);
    delete node;
    node = NULL;
}

#endif