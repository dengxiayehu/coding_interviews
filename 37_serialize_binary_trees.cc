#include <iostream>
#include <string>
#include <strstream>

#include "tree_util.h"

using namespace std;

class Solution {
public:
    char* Serialize(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        strm_.clear();
        searialize_core(root, strm_);

        return strm_.str();
    }

    TreeNode* Deserialize(char* str) {
        if (!str || !*str) {
            return NULL;
        }

        TreeNode* node = NULL;
        deserialize_core(&node, &str);

        return node;
    }

private:
    static void searialize_core(TreeNode* node, ostrstream& strm) {
        if (!node) {
            strm << "#,";
            return;
        }
        strm << node->val << ",";
        searialize_core(node->left, strm);
        searialize_core(node->right, strm);
    }

    static void deserialize_core(TreeNode** node, char** str) {
        int val;
        if (read_node(val, str)) {
            *node = new TreeNode(val);
            deserialize_core(&(*node)->left, str);
            deserialize_core(&(*node)->right, str);
        }
    }

    static bool read_node(int& val, char** str) {
        char* p = *str;
        if (*p == '#') {
            if (*(p + 1) == ',') {
                *str += 2;
            }
            return false;
        }

        char* q = strchr(p, ',');
        if (!q) {  // error format
            return false;
        }

        // Reconstruct val.
        bool ret = true;
        *q = '\0';
        if (sscanf(p, "%d", &val) < 0) {
            ret = false;
        }
        *q = ',';
        *str += (q - p + 1);
        return ret;
    }

private:
    std::ostrstream strm_;
};

int main(int argc, char* argv[]) {
    {
        int arr[] = {10, -1, 11, -1, 12, -1, -1};
        TreeNode* root = create_pre_order(arr, NELEM(arr));
        char* str = Solution().Serialize(root);
        pre_order(root);
        cout << "Searalized string: " << str << endl;
        TreeNode* searialized = Solution().Deserialize(str);
        pre_order(searialized);
        delete_postorder(root);
        delete_postorder(searialized);
    }

    return 0;
}