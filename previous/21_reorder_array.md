# 调整数组顺序使奇数位于偶数前面

> 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

这道题的算法不难，只要用两个指针分别指向数组的头部和尾部，到前部遇到偶数时，由后往前搜索一个奇数，将两者交换。一直到前后两个指针相遇。  
这道题要考虑良好到软件扩展思想。

``` cpp
#include <iostream>
#include <vector>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.empty()) {
            return;
        }
        reorder_array_core(array, is_odd);
    }

private:
    typedef bool (*Func)(const int v);

    void reorder_array_core(vector<int> &array, Func func) {
        int i = 0;
        int j = array.size()-1;
        while (i != j) {
            while (i < j && func(array[i])) {
                ++i;
            }
            while (i < j && !func(array[j])) {
                --j;
            }
            swap(array, i, j);
        }
    }

    static bool is_odd(const int v) {
        return v&1;
    }

    static void swap(vector<int> &array, int i, int j) {
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = { 1, 3, 3, 4, 5, 6 };
    vector<int> v(arr, arr+NELEM(arr));
    Solution().reOrderArray(v);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
```

注意：上面算法在牛客网上通不过，因为它可能改变求奇数和奇数，偶数和偶数之间的相对次序。

> 用例：  
1,2,3,4,5,6,7]

> 期望输出：  
[1,3,5,7,2,4,6]

> 上述算法输出：  
[1,7,3,5,4,6,2]

符合牛客网上要求但解法：

``` cpp
#include <iostream>
#include <vector>
#include <queue>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.empty()) {
            return;
        }
        reorder_array_core(array, is_odd);
    }

private:
    typedef bool (*Func)(const int v);

    void reorder_array_core(vector<int> &array, Func func) {
        const int n = array.size();
        int k = 0;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (func(array[i])) {
                array[k++] = array[i];
            } else {
                q.push(array[i]);
            }
        }
        while (!q.empty()) {
            array[k++] = q.front();
            q.pop();
        }
    }

    static bool is_odd(const int v) {
        return v&1;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    vector<int> v(arr, arr+NELEM(arr));
    Solution().reOrderArray(v);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
```

这道题经过牛客网修改之后，瞬间就没有灵气了。🤦‍♂️。