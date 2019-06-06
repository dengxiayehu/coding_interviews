# 链表的倒数第k个结点

## 题目描述

输入一个链表，输出该链表的倒数第k个结点。

## 分析

这道题首先要知道使用双指针法，要求倒数第k个结点，可以使一个指针先往前走k-1步，另一个指针指向链表开头。然后两个指针一起往前移动，直到前面那个指针到链表的结尾。

这题主要考虑程序的鲁棒性，分为两个方面：

1. 当输入的链表头为NULL时，程序能正确处理
2. 当链表长度小于k时，程序也要能正确处理

``` cpp
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
```

> 输出结果：  
./kth_to_tail_run  
NULL  
(head, 0): NULL  
(head, 1): 5  
(head, 2): 4  
(head, 3): 3  
(head, 4): 2  
(head, 5): 1  
(head, 6): NULL  