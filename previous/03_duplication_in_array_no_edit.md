# 数组中重复的数字

> 在一个长度为n+1的数组里的所有数字都在1~n的范围内，所以数组中至少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的数组。

算法思想如下：  
对1~n范围内的数字，选取其中间的那个数字m（也就是(1+n)/2），然后遍历整个数组，看在1~m范围内以及m+1~n范围内数字的个数。假如1~m范围内数字的个数多于m个，那么重复的数字必然是在1~m范围内；反之，重复的数字就是在m+1~n内。然后对半分之后，小问题又和大问题类似，直到范围内只有一个元素。

测试用例：

1. 含有一个重复数字
2. 有多个重复数字
3. 异常输入，例如数组为NULL，长度<=1等

``` cpp
#include <iostream>

using namespace std;

#define NELEM(arr) sizeof(arr)/sizeof(arr[0])

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers, all elements are in [1, length-1]
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (!numbers || length <= 1) {
            // Illegale array or no duplication.
            return false;
        }

        int l = 1;
        int u = length-1;
        while (l <= u) {
            int m = l+((u-l)>>1); // middle number of l~u
            int cnt = count_range(numbers, length, l, m); // count numbers in [l, m]
            if (l == u) {
                if (cnt > 1) {
                    if (duplication) {
                        *duplication = l;
                    }
                    return true;
                } else {
                    break;
                }
            }
            if (cnt > (m-l+1)) {
                // Duplication maybe in [l, m] for the numbers in [l, m] is more than m-l+1.
                u = m;
            } else {
                // Duplication maybe in [m+1, u].
                l = m+1;
            }
        }

        return false;
    }

private:
    int count_range(int numbers[], int length, int start, int end) {
        int cnt = 0;
        for (int i = 0; i < length; i++) {
            if (numbers[i] >= start && numbers[i] <= end) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int dup;

    int arr1[] = { 1, 4, 3, 2, 3 };
    if (s.duplicate(arr1, NELEM(arr1), &dup)) {
        cout << "arr1 dup: " << dup << endl;
    } else {
        cout << "arr1 no dup" << endl;
    }

    int arr2[] = { 1, 4, 4, 3, 2, 3 };
    if (s.duplicate(arr2, NELEM(arr2), &dup)) {
        cout << "arr2 dup: " << dup << endl;
    } else {
        cout << "arr2 no dup" << endl;
    }

    if (s.duplicate(NULL, 0, &dup)) {
        cout << "arr3 dup: " << dup << endl;
    } else {
        cout << "arr3 no dup" << endl;
    }

    return 0;
}
```

> 输出：  
arr1 dup: 3  
arr2 dup: 3  
arr3 no dup  
