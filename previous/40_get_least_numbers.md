# 最小的K个数

> 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

``` cpp
#include <iostream>
#include <vector>
#include <set>

#include "macro_util.h"

using namespace std;

// 注意：需要用到最大堆哦！每次将当前元素与最大堆中的最大的元素比较，
// 若比最大的元素小，则将最大元素丢掉，再塞入当前元素。
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (input.size() < k) {
            // 想要最小的k个数，但是输入的数组不够，返回空。
            return res;
        }

        // 在一堆数中间找出最小（大）的N个数，典型的堆算法。
        multiset<int, greater<int> > max_heap;
        for (vector<int>::iterator it = input.begin(); it != input.end(); it++) {
            if (max_heap.size() < k) {
                // 堆中元素不足k个，先往里面塞。
                max_heap.insert(*it);
            } else {
                // 堆中元素正好是k个，判断堆中最大元素是否比当前元素大，若是，则将最大元素丢掉，塞入当前元素。
                multiset<int, greater<int> >::iterator it1 = max_heap.begin(); // it1指向堆中的最大元素
                if (*it1 > *it) { // 堆中最大的元素比当前元素大，则用当前元素来“替换”最大的元素
                    max_heap.erase(it1);
                    max_heap.insert(*it);
                }
            }
        }

        // 最终将堆中元素存放入结果向量。
        for (multiset<int, greater<int> >::iterator it = max_heap.begin();
             it != max_heap.end();
             it++) {
            res.push_back(*it);
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    {
        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
        vector<int> res = Solution().GetLeastNumbers_Solution(vector<int>(arr, arr+NELEM(arr)), 4);
        for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    {
        int arr[] = { 1 };
        vector<int> res = Solution().GetLeastNumbers_Solution(vector<int>(arr, arr+NELEM(arr)), 2);
        for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    {
        int arr[] = { 1, 3, 5, 1, 0, 3, -1, 3, 9, 0 };
        vector<int> res = Solution().GetLeastNumbers_Solution(vector<int>(arr, arr+NELEM(arr)), 2);
        for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    {
        int arr[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
        vector<int> res = Solution().GetLeastNumbers_Solution(vector<int>(arr, arr+NELEM(arr)), 4);
        for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}
```

> 输出结果：  
4 3 2 1  
\
0 -1  
4 3 2 1