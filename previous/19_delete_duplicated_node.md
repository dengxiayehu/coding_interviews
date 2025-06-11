
# 删除链表中重复的结点

> 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5。

解这道题需要思路清晰，不要打补丁式写程序。

``` cpp
#include <iostream>
#include "list_util.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (!pHead) {
            return NULL;
        }

        ListNode *prev = NULL;
        ListNode *p = pHead;
        while (p) { // travel list
            bool delete_current = false;
            if (p->next && p->next->val == p->val) { // node with value p->val should be deleted
                delete_current = true;
            }

            if (delete_current) {
                int val = p->val;
                while (p && p->val == val) { // these p nodes shoulde be deleted
                    ListNode *q = p->next;
                    delete p;
                    p = q;
                }
                if (prev) { // 已经找到了前驱结点，将前驱结点和后面的结点链接起来
                    prev->next = p;
                } else { // 删除的重复元素位于链表头部，更新pHead的值
                    pHead = p;
                }
            } else {
                // 没有重复的数据，继续往后遍历
                prev = p;
                p = p->next;
            }
        }

        return pHead;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = { 8, 8, 8, 8, 9, 9 };
    ListNode *head, *tail;
    create_list_by_array(arr, NELEM(arr), head, tail);
    head = Solution().deleteDuplication(head);
    print_list(head);
    destroy_list(head);

    return 0;
}
```

这个程序在一番思考过后，一把过，good。