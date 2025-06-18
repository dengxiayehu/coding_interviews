#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "./matchers.h"
#include "tree_util.h"

// https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/
// 题目：请实现两个函数，分别用来序列化和反序列化二叉树。
// 这道题我们可以借鉴 tree_util.h 里的 create_pre_order() 函数实现。
class Codec {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        std::string sep;
        std::ostringstream oss;
        serialize_internal(root, oss, sep);

        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const std::string& data) {
        if (data.empty()) {
            return nullptr;
        }

        const char* str = data.c_str();
        return deserialize_internal(str);
    }

private:
    void serialize_internal(TreeNode* node, std::ostringstream& oss, std::string& sep) {
        if (node == nullptr) {
            oss << sep << "$";
            return;
        }

        oss << sep << node->val;
        if (sep.empty()) {
            sep = ",";
        }

        serialize_internal(node->left, oss, sep);
        serialize_internal(node->right, oss, sep);
    }

    TreeNode* deserialize_internal(const char*& str) {
        if (*str == '\0') {
            return nullptr;
        }

        std::string val_str;
        const char* pos = strchr(str, ',');
        if (pos == nullptr) {
            val_str = str;
            str += strlen(str);
        } else {
            val_str = std::string(str, pos - str);
            str = pos + 1;
        }
        if (val_str == "$") {
            return nullptr;
        }

        int val = stoi(val_str);
        TreeNode* node = new TreeNode(val);
        node->left = deserialize_internal(str);
        node->right = deserialize_internal(str);

        return node;
    }
};

MATCHER_P(SerializedStringMatcher, vi, "") {
    const std::string& serialized_string = arg;
    std::ostringstream oss;
    std::string sep;
    for (const auto& v : vi) {
        oss << sep;
        if (v == -1) {
            oss << "$";
        } else {
            oss << v;
        }
        if (sep.empty()) {
            sep = ",";
        }
    }
    EXPECT_THAT(oss.str(), StrEq(serialized_string));

    return true;
}

bool is_tree_node_equal(TreeNode* n1, TreeNode* n2) {
    return (n1 == nullptr && n2 == nullptr) || (n1 != nullptr && n2 != nullptr && n1->val == n2->val);
}

MATCHER_P(TreeMatcher, other_root, "") {
    TreeNode* root = arg;
    return is_tree_the_same(root, other_root);
}

bool is_tree_the_same(TreeNode* r1, TreeNode* r2) {
    if (!is_tree_node_equal(r1, r2)) {
        return false;
    }

    if (r1 == nullptr && r2 == nullptr) {
        return true;
    }

    return is_tree_the_same(r1->left, r2->left) && is_tree_the_same(r1->right, r2->right);
}

TEST(ut_37, serializeAndDeserialize) {
    Codec c;

    std::vector<int> nums{10, 6, 4, -1, -1, 8, -1, -1, 14, 12, -1, -1, 16, -1, -1};
    TreeNode* root = create_pre_order(nums.data(), nums.size());
    std::string res = c.serialize(root);
    EXPECT_THAT(res, SerializedStringMatcher(nums));

    TreeNode* deserialized_root = c.deserialize(res);
    EXPECT_THAT(deserialized_root, TreeMatcher(root));
    delete_postorder(root);
    delete_postorder(deserialized_root);
}
