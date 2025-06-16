# 两个链表的第一个公共结点

> 输入两个链表，找出它们的第一个公共结点。

``` cpp
#include "list_node.h"

using namespace std;

class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2) {
            return NULL;
        }

        // A B C  D E     len1 = 5
        //       /
        //   X Y          len2 = 4

        int len1 = GetListLength(pHead1);
        int len2 = GetListLength(pHead2);
        ListNode *longList = pHead1;
        ListNode *shortList = pHead2;
        int diff = len1 - len2;
        if (diff < 0) {
            longList = pHead2;
            shortList = pHead1;
            diff = -diff;
        }

        // Long list walk diff steps.
        for (int i = 0; i < diff; i++) {
            longList = longList->next;
        }

        while (longList && shortList && longList != shortList) {
            longList = longList->next;
            shortList = shortList->next;
        }

        return longList;
    }

private:
    static int GetListLength(const ListNode *node) {
        int length = 0;
        while (node) {
            node = node->next;
            length++;
        }
        return length;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
```
