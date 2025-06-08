#pragma once

struct TreeLinkNode {
    char ch;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* next;

    explicit TreeLinkNode(char c) : ch(c), left(nullptr), right(nullptr), next(nullptr) {
    }
};

/*
 *       a
 *     /   \
 *    b     c
 *   / \   / \
 *  d   e f   g
 *     / \
 *    h   i
 * */
inline void init_tree_in_book(TreeLinkNode* nodes[9]) {
    // array: [a, b, c, d, e, f, g, h, i]
    // index:  0  1  2  3  4  5  6  7  8
    for (int i = 0; i < 9; i++) {
        TreeLinkNode* node = new TreeLinkNode('a' + i);
        nodes[i] = node;
    }
    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[2];

    nodes[1]->left = nodes[3];
    nodes[1]->right = nodes[4];
    nodes[1]->next = nodes[0];

    nodes[2]->left = nodes[5];
    nodes[2]->right = nodes[6];
    nodes[2]->next = nodes[0];

    nodes[3]->next = nodes[1];

    nodes[4]->left = nodes[7];
    nodes[4]->right = nodes[8];
    nodes[4]->next = nodes[1];

    nodes[5]->next = nodes[2];

    nodes[6]->next = nodes[2];

    nodes[7]->next = nodes[4];

    nodes[8]->next = nodes[4];
}

inline void destroy_tree(TreeLinkNode* nodes[9]) {
    for (int i = 1; i <= 9; i++) {
        delete nodes[i - 1];
    }
}
