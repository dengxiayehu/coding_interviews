# 数组中重复的数字

这道题最大的特点是：长度为n的数组，它里面所有元素的值均在0~n-1内。由于所有元素的值均在0~n-1内，那么比较自然地将其与数组下标结合起来。

``` cpp
#include <iostream>

#define NELEM(arr) sizeof(arr)/sizeof(arr[0])

using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        // Empty array or invalid value of length.
        if (!numbers || length <= 0) {
            return false;
        }

        // Check whether element is between 0~length-1
        for (int i = 0; i < length; i++) {
            if (numbers[i] < 0 || numbers[i] >= length) {
                return false;
            }
        }

        int m;
        int t;
        for (int i = 0; i < length; i++) {
            for ( ; ; ) {
                m = numbers[i];
                if (m == i) {
                    break;
                }
                if (numbers[m] == m) {
                    // m is occurred both on index i and index m.
                    if (duplication) {
                        *duplication = m;
                        return true;
                    }
                }
                t = numbers[m];
                numbers[m] = m;
                numbers[i] = t;
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    bool res;
    int dup;

    int numbers[] = { 2, 3, 1, 0, 2, 5, 3 };
    cout << "{ 2, 3, 1, 0, 2, 5, 3 }: ";
    res = s.duplicate(numbers, NELEM(numbers), &dup);
    if (res) {
        cout << "dup " << dup << endl;
    } else {
        cout << "no dup" << endl;
    }

    int numbers1[] = { 2, 3, 1, 0, 2, 5 };
    cout << "{ 2, 3, 1, 0, 2, 5 }: ";
    res = s.duplicate(numbers1, NELEM(numbers1), &dup);
    if (res) {
        cout << "dup " << dup << endl;
    } else {
        cout << "no dup" << endl;
    }

    int numbers2[] = { 1, 0, 2, 5, 3 };
    cout << "{ 1, 0, 2, 5, 3 } ";
    res = s.duplicate(numbers2, NELEM(numbers2), &dup);
    if (res) {
        cout << "dup " << dup << endl;
    } else {
        cout << "no dup" << endl;
    }

    int numbers3[] = { 2, 3, 1, 0, 2, 5, 3, 9 };
    cout << "{ 2, 3, 1, 0, 2, 5, 3, 9 } ";
    res = s.duplicate(numbers3, NELEM(numbers3), &dup);
    if (res) {
        cout << "dup " << dup << endl;
    } else {
        cout << "no dup" << endl;
    }

    int numbers4[] = { 2, 3, 1, 0, 2, 5, 3, -1 };
    cout << "{ 2, 3, 1, 0, 2, 5, 3, -1 } ";
    res = s.duplicate(numbers4, NELEM(numbers4), &dup);
    if (res) {
        cout << "dup " << dup << endl;
    } else {
        cout << "no dup" << endl;
    }

    res = s.duplicate(NULL, 0, &dup);
    cout << "NULL: ";
    if (res) {
        cout << "dup " << dup << endl;
    } else {
        cout << "no dup" << endl;
    }

    return 0;
}
```

> 输出结果：  
./03_duplication_in_array_run  
{ 2, 3, 1, 0, 2, 5, 3 }: dup 2  
{ 2, 3, 1, 0, 2, 5 }: dup 2  
{ 1, 0, 2, 5, 3 } no dup  
{ 2, 3, 1, 0, 2, 5, 3, 9 } no dup  
{ 2, 3, 1, 0, 2, 5, 3, -1 } no dup  
NULL: no dup  