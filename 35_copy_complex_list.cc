#include <iostream>
#include <unordered_map>

#include "random_list_util.h"

using namespace std;

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        unordered_map<RandomListNode*, RandomListNode*> map;
        RandomListNode* chead = NULL;
        RandomListNode* ctail = NULL;
        RandomListNode* node = pHead;
        RandomListNode* tmp;
        while (node) {
            // Clone "normal" list.
            tmp = new RandomListNode(node->label);
            if (!chead) {
                chead = ctail = tmp;
            } else {
                ctail->next = tmp;
                ctail = tmp;
            }
            map.insert(make_pair(node, tmp));
            node = node->next;
        }

        // Handle random pointer.
        node = pHead;
        while (node) {
            if (node->random) {
                map[node]->random = map[node->random];
            }
            node = node->next;
        }

        return chead;
    }
};

int main(int argc, char* argv[]) {
    {
        int arr[] = {1, 2, 3, 4, 5};
        RandomListNode *head, *tail;
        create_list_by_array(arr, NELEM(arr), head, tail);
        random_list(head, 0, 2, 3, 1, 1, 4, -1);
        print_list(head);
        RandomListNode* cloned = Solution().Clone(head);
        print_list(cloned);
        destroy_list(head);
        destroy_list(cloned);
    }

    return 0;
}