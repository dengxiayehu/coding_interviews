#include <iostream>

#include "list_util1.h"
#include "macro_util.h"

using namespace std;

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (!pHead) {
            return NULL;
        }

        ListNode* slow = pHead->next;
        if (!slow) {
            return NULL;
        }
        ListNode* fast = slow->next;

        while (fast && fast != slow) {
            slow = slow->next;  // slow walks +1
            fast = fast->next;  // fast walks +2
            if (fast) {
                fast = fast->next;
            }
        }
        if (fast != slow) {  // no loop
            return NULL;
        }

        // We get a node inside the loop.

        // Get the loop's size.
        int loop_size = 1;
        ListNode* tmp = slow->next;
        while (tmp != slow) {
            ++loop_size;
            tmp = tmp->next;
        }

        fast = pHead;
        slow = pHead;
        for (int i = 0; i < loop_size; i++) {
            fast = fast->next;
        }
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};

int main(int argc, char* argv[]) {
    int arr[] = {1, 2, 3, 4, 5};
    ListNode *head = NULL, *tail = NULL;
    create_list_by_array(arr, NELEM(arr), head, tail);
    ListNode* tmp = Solution().EntryNodeOfLoop(head);
    if (tmp) {
        cout << "Found " << tmp->val << endl;
    } else {
        cout << "No found" << endl;
    }
    destroy_list(head);

    int arr1[] = {1};
    create_list_by_array(arr1, NELEM(arr1), head, tail);
    tmp = Solution().EntryNodeOfLoop(head);
    if (tmp) {
        cout << "Found " << tmp->val << endl;
    } else {
        cout << "No found" << endl;
    }
    destroy_list(head);

    int arr2[] = {1, 2};
    create_list_by_array(arr2, NELEM(arr2), head, tail);
    tmp = Solution().EntryNodeOfLoop(head);
    if (tmp) {
        cout << "Found " << tmp->val << endl;
    } else {
        cout << "No found" << endl;
    }
    destroy_list(head);

    int arr3[] = {1};
    create_list_by_array(arr3, NELEM(arr3), head, tail);
    head[0].next = &head[0];
    tmp = Solution().EntryNodeOfLoop(head);
    if (tmp) {
        cout << "Found " << tmp->val << endl;
    } else {
        cout << "No found" << endl;
    }
    destroy_list(head);

    int arr4[] = {1, 2};
    create_list_by_array(arr4, NELEM(arr4), head, tail);
    head[1].next = &head[0];
    tmp = Solution().EntryNodeOfLoop(head);
    if (tmp) {
        cout << "Found " << tmp->val << endl;
    } else {
        cout << "No found" << endl;
    }
    destroy_list(head);

    int arr5[] = {1, 2, 3};
    create_list_by_array(arr5, NELEM(arr5), head, tail);
    head[2].next = &head[0];
    tmp = Solution().EntryNodeOfLoop(head);
    if (tmp) {
        cout << "Found " << tmp->val << endl;
    } else {
        cout << "No found" << endl;
    }
    destroy_list(head);

    int arr6[] = {1, 2, 3, 4};
    create_list_by_array(arr6, NELEM(arr6), head, tail);
    head[3].next = &head[0];
    tmp = Solution().EntryNodeOfLoop(head);
    if (tmp) {
        cout << "Found " << tmp->val << endl;
    } else {
        cout << "No found" << endl;
    }
    destroy_list(head);

    int arr7[] = {1, 2, 3, 4, 5};
    create_list_by_array(arr7, NELEM(arr7), head, tail);
    head[4].next = &head[2];
    tmp = Solution().EntryNodeOfLoop(head);
    if (tmp) {
        cout << "Found " << tmp->val << endl;
    } else {
        cout << "No found" << endl;
    }
    destroy_list(head);

    // NULL list.
    print_list(Solution().EntryNodeOfLoop(NULL));

    return 0;
}