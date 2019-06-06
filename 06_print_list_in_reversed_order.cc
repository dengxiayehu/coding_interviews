#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if (!head) {
            // Empty list returns empty result.
            return res;
        }
        stack<int> s;
        while (head) {
            // Push val into stack.
            s.push(head->val);
            head = head->next;
        }
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};

int create_list_by_array(const int arr[], const int n, ListNode *&head, ListNode *&tail)
{
    head = NULL;
    tail = NULL;

    if (!arr || n <= 0) {
        return -1;
    }
    
    for (int i = 0; i < n; i++) {
        ListNode *node = new ListNode(arr[i]);
        if (!head) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    return 0;
}

int destroy_list(ListNode *&head)
{
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

int main(int argc, char const *argv[])
{
    ListNode *head, *tail;
    const int arr[] = { 1, 2, 3, 4, 5 };
    const int n = sizeof(arr)/sizeof(arr[0]);
    create_list_by_array(arr, n, head, tail);
    vector<int> res = Solution().printListFromTailToHead(head);
    for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
    destroy_list(head);

    return 0;
}
