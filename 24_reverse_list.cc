#include <iostream>

#include "list_util1.h"
#include "macro_util.h"

using namespace std;

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead) {
            return NULL;
        }

        ListNode* prev = NULL;
        ListNode* p = pHead;
        ListNode* q;
        while (p) {
            q = p->next;
            p->next = prev;
            prev = p;
            p = q;
        }

        return prev;
    }
};

int main(int argc, char* argv[]) {
    int arr[] = {1, 2, 3, 4, 5};
    ListNode *head = NULL, *tail = NULL;
    create_list_by_array(arr, NELEM(arr), head, tail);
    print_list(Solution().ReverseList(head));
    destroy_list(head);

    int arr1[] = {1};
    create_list_by_array(arr1, NELEM(arr1), head, tail);
    print_list(Solution().ReverseList(head));
    destroy_list(head);

    print_list(Solution().ReverseList(NULL));

    return 0;
}