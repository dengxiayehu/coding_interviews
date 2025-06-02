#include <iostream>

#include "list_util1.h"
#include "macro_util.h"

using namespace std;

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1) {  // list1 is empty, just use list2
            return pHead2;
        }
        if (!pHead2) {  // list2 is empty, just use list1
            return pHead1;
        }

        ListNode* cur;
        // Choose the smaller node between list1 and list2's head node.
        if (pHead1->val < pHead2->val) {
            cur = pHead1;
            pHead1 = pHead1->next;
        } else {
            cur = pHead2;
            pHead2 = pHead2->next;
        }

        // Link current node and its remaining nodes.
        cur->next = Merge(pHead1, pHead2);

        return cur;
    }
};

int main(int argc, char* argv[]) {
    int arr[] = {1, 3, 5, 7, 9};
    ListNode *head = NULL, *tail = NULL;
    create_list_by_array(arr, NELEM(arr), head, tail);

    int arr1[] = {2, 4, 6, 8, 10};
    ListNode *head1 = NULL, *tail1 = NULL;
    create_list_by_array(arr1, NELEM(arr1), head1, tail1);

    print_list(Solution().Merge(head, head1));

    destroy_list(head);
    destroy_list(head1);

    print_list(Solution().Merge(NULL, NULL));

    int arr2[] = {1};
    ListNode *head2 = NULL, *tail2 = NULL;
    create_list_by_array(arr2, NELEM(arr2), head2, tail2);

    int arr3[] = {2};
    ListNode *head3 = NULL, *tail3 = NULL;
    create_list_by_array(arr3, NELEM(arr3), head3, tail3);

    print_list(Solution().Merge(head2, head3));

    destroy_list(head2);
    destroy_list(head3);

    return 0;
}