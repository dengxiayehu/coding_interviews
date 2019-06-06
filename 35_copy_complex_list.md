# 复杂链表的复制

> 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

``` cpp
#include <iostream>
#include <unordered_map>

#include "random_list_util.h"

using namespace std;

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        unordered_map<RandomListNode*, RandomListNode*> map;
        RandomListNode *chead = NULL;
        RandomListNode *ctail = NULL;
        RandomListNode *node = pHead;
        RandomListNode *tmp;
        while (node) {
            // Clone "normal" list.
            tmp = new RandomListNode(node->label);
            if (!chead) {
                chead = ctail = tmp;
            } else {
                ctail->next = tmp;
                ctail = tmp;
            }
            map.insert(make_pair(node, tmp));
            node = node->next;
        }

        // Handle random pointer.
        node = pHead;
        while (node) {
            if (node->random) {
                map[node]->random = map[node->random];
            }
            node = node->next;
        }

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
        print_list(head);
        RandomListNode *cloned = Solution().Clone(head);
        print_list(cloned);
        destroy_list(head);
        destroy_list(cloned);
    }

    return 0;
}
```

> 输出结果：  
1:3 2:5 3 4:2 5  
1:3 2:5 3 4:2 5  

另外一种方式，避免哈希表带来的空间复杂度。

``` cpp
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
```

**注意事项：**  
开始忘记将“原始”链表的尾结点的next设置为NULL，这样就会导致“原始“链表的最后拖着”克隆“链表的最后一个结点。这样牛客网就会判空！

> 输出结果：  
./35_copy_complex_list_run1  
0x7ff619c02990@1:3 0x7ff619c029a8@2:5 0x7ff619c029c0@3 0x7ff619c029d8@4:2 0x7ff619c029f0@5  
0x7ff619c00360@1:3 0x7ff619c02a10@2:5 0x7ff619c02a30@3 0x7ff619c02a50@4:2 0x7ff619c02a70@5  
0x7ff619c00360@1:1  
0x7ff619c02990@1:1  
0x7ff619c02a90@49 0x7ff619c02aa8@50 0x7ff619c02ac0@51 0x7ff619c02ad8@52 0x7ff619c02af0@53 0x7ff619c02b08@51 0x7ff619c02b20@53 0x7ff619c02b38@35 0x7ff619c02b50@50 0x7ff619c02b68@35  
0x7ff619c02990@49 0x7ff619c00360@50 0x7ff619c029b0@51 0x7ff619c029d0@52 0x7ff619c029f0@53 0x7ff619c02b80@51 0x7ff619c02ba0@53 0x7ff619c02bc0@35 0x7ff619c02be0@50 0x7ff619c02c00@35