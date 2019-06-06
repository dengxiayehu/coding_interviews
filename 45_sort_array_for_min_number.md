# 数组排成最小的数

> 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

``` cpp
#include <iostream>
#include <vector>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string res;
        if (numbers.empty()) {
            return res;
        }

        // 将数字转换为字符串。
        vector<string> str_numbers(numbers.size());
        for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
            str_numbers.push_back(to_string(*it));
        }

        // 将字符串数字向量排序，最小的元素放到最前面。
        const int n = str_numbers.size();
        int i;
        for (i = 0; i < n; i++) {
            bool swap = false;
            for (int j = n-1; j > i; j--) {
                if (str_numbers[j]+str_numbers[j-1] < str_numbers[j-1]+str_numbers[j]) {
                    string tmp(str_numbers[j]);
                    str_numbers[j] = str_numbers[j-1];
                    str_numbers[j-1] = tmp;
                    swap = true;
                }
            }
            if (!swap) {
                break;
            }

            // 将最小的元素添加到res中。
            res += str_numbers[i];
        }
        for (i = 0; i < n; i++) {
            res += str_numbers[i];
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    {
        int arr[] = { 3, 32, 321 };
        cout << Solution().PrintMinNumber(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    {
        int arr[] = { 3, 3, 3 };
        cout << Solution().PrintMinNumber(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    {
        int arr[] = { 1, 2, 3, 4, 5 };
        cout << Solution().PrintMinNumber(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    {
        int arr[] = { 5, 4, 3, 2, 1 };
        cout << Solution().PrintMinNumber(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    {
        int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
        cout << Solution().PrintMinNumber(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    return 0;
}
```

> 输出结果：  
321323  
333  
12345  
12345  
10123456789  