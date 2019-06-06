#include <iostream>

#include "random_list_util.h"

using namespace std;

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (!pHead) {
            return NULL;
        }

        RandomListNode *node = pHead;
        RandomListNode *tmp;
        RandomListNode *q;
        while (node) {
            tmp = new RandomListNode(node->label);
            q = node->next;
            tmp->next = q;
            node->next = tmp;
            node = q;
        }

        node = pHead;
        while (node) {
            tmp = node->next; // cloned node
            if (node->random) {
                tmp->random = node->random->next;
            }
            node = tmp->next;
        }

        RandomListNode *chead = pHead->next;
        RandomListNode *ctail = chead;
        RandomListNode *tail = pHead;
        node = chead->next;
        while (node) {
            q = node->next; // cloned node
            tail->next = node;
            tail = node;
            ctail->next = q;
            ctail = q;
            node = q->next;
        }
        // Don't forget to set orig link's tail->next to NULL!
        tail->next = NULL;

        return chead;
    }
};

int main(int argc, char *argv[])
{
    {
        int arr[] = { 1, 2, 3, 4, 5 };
        RandomListNode *head, *tail;
        create_list_by_array(arr, NELEM(arr), head, tail);
        random_list(head, 0, 2, 3, 1, 1, 4, -1);
        RandomListNode *cloned = Solution().Clone(head);
        print_list(head);
        print_list(cloned);
        destroy_list(head);
        destroy_list(cloned);
    }

    {
        int arr[] = { 1 };
        RandomListNode *head, *tail;
        create_list_by_array(arr, NELEM(arr), head, tail);
        random_list(head, 0, 0, -1);
        RandomListNode *cloned = Solution().Clone(head);
        print_list(head);
        print_list(cloned);
        destroy_list(head);
        destroy_list(cloned);
    }

    {
        int arr[] = { '1', '2', '3', '4', '5', '3', '5', '#', '2', '#' };
        RandomListNode *head, *tail;
        create_list_by_array(arr, NELEM(arr), head, tail);
        RandomListNode *cloned = Solution().Clone(head);
        print_list(head);
        print_list(cloned);
        destroy_list(head);
        destroy_list(cloned);
    }

    return 0;
}