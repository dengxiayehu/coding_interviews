#include <iostream>

using namespace std;

#define NELEM(arr) (sizeof(arr) / sizeof(arr[0]))

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL) {
    }
};

class Solution {
public:
    void delete_node(ListNode** head, ListNode* to_delete) {
        if (!head || !*head || !to_delete) {
            return;
        }

        // Suppose to_delete is in the list, otherwise we need to check it with O(n).
        if (to_delete->next) {
            ListNode* next = to_delete->next;
            to_delete->val = next->val;
            to_delete->next = next->next;
            delete next;
        } else if (to_delete == *head) {
            // Delete the only one node in list.
            delete to_delete;
            *head = NULL;
        } else {
            // Delete the tail.
            ListNode* p = *head;
            while (p->next != to_delete) {
                p = p->next;
            }
            delete to_delete;
            p->next = NULL;
        }
    }
};

int create_list_by_array(const int arr[], const int n, ListNode*& head, ListNode*& tail) {
    head = NULL;
    tail = NULL;

    if (!arr || n <= 0) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        ListNode* node = new ListNode(arr[i]);
        if (!head) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    return 0;
}

int destroy_list(ListNode*& head) {
    ListNode *p, *q;
    p = head;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }
    head = NULL;

    return 0;
}

void print_list(ListNode* head) {
    ListNode* p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main(int argc, char const* argv[]) {
    int arr[] = {1};
    ListNode *head, *tail;
    create_list_by_array(arr, NELEM(arr), head, tail);
    Solution().delete_node(&head, head);
    print_list(head);
    destroy_list(head);

    int arr1[] = {1, 2, 3, 4, 5};
    create_list_by_array(arr1, NELEM(arr1), head, tail);
    ListNode* p = head->next->next->next;
    Solution().delete_node(&head, p);
    print_list(head);
    destroy_list(head);

    return 0;
}
