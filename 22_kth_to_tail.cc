#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
        val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (!pListHead || k == 0) {
            // Empty list or illegale k.
            return NULL;
        }

        ListNode *fast = pListHead;
        ListNode *slow = pListHead;
        for (unsigned i = 0; i < k-1 && fast; i++) {
            fast = fast->next;
        }
        // Check if fast is already NULL, that means the kth node to tail not exists.
        if (!fast) {
            return NULL;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode* p = NULL;

    p = s.FindKthToTail(NULL, 0);
    if (p) {
        cout << p->val << endl;
    } else {
        cout << "NULL" << endl;
    }

    // Create a list by array.
    const int arr[] = { 1, 2, 3, 4, 5 };
    const int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = NULL, *tail = NULL;
    for (unsigned i = 0; i < n; i++) {
        ListNode *node = new ListNode(arr[i]);
        if (!head) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    p = s.FindKthToTail(head, 0);
    cout << "(head, 0): ";
    if (p) {
        cout << p->val << endl;
    } else {
        cout << "NULL" << endl;
    }

    p = s.FindKthToTail(head, 1);
    cout << "(head, 1): ";
    if (p) {
        cout << p->val << endl;
    } else {
        cout << "NULL" << endl;
    }

    p = s.FindKthToTail(head, 2);
    cout << "(head, 2): ";
    if (p) {
        cout << p->val << endl;
    } else {
        cout << "NULL" << endl;
    }

    p = s.FindKthToTail(head, 3);
    cout << "(head, 3): ";
    if (p) {
        cout << p->val << endl;
    } else {
        cout << "NULL" << endl;
    }

    p = s.FindKthToTail(head, 4);
    cout << "(head, 4): ";
    if (p) {
        cout << p->val << endl;
    } else {
        cout << "NULL" << endl;
    }

    p = s.FindKthToTail(head, 5);
    cout << "(head, 5): ";
    if (p) {
        cout << p->val << endl;
    } else {
        cout << "NULL" << endl;
    }

    p = s.FindKthToTail(head, 6);
    cout << "(head, 6): ";
    if (p) {
        cout << p->val << endl;
    } else {
        cout << "NULL" << endl;
    }

    // Destroy the list.
    ListNode *q = NULL;
    p = head;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }

    return 0;
}
