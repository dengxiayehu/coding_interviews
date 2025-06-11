# 数组中只出现一次的数字

> 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

``` cpp
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
        if (data.size() < 2 || !num1 || !num2) {
            // 非法的输入，此时不可能找到两个仅出现一次的数字。
            return;
        }
        // 先将数组中所有元素都异或起来。
        int xor_val = data[0];
        for (int i = 1; i < data.size(); i++) {
            xor_val ^= data[i];
        }
        // 找到xor_val中最低的比特位。
        int lowest_bit_index = get_lowest_bit_index(xor_val);
        bool num1_candidate = false;
        bool num2_candidate = false;
        for (vector<int>::const_iterator it = data.begin(); it != data.end(); it++) {
            if (is_bit_set(*it, lowest_bit_index)) {
                if (!num1_candidate) {
                    *num1 = *it;
                    num1_candidate = true;
                } else {
                    *num1 ^= *it;
                }
            } else {
                if (!num2_candidate) {
                    *num2 = *it;
                    num2_candidate = true;
                } else {
                    *num2 ^= *it;
                }
            }
        }
    }

private:
    static int get_lowest_bit_index(int xor_val) {
        int mask = 1;
        for (int i = 0; i < sizeof(int)*8; i++) {
            if (mask&xor_val) {
                return i;
            }
            mask <<= 1;
        }
        return -1;
    }

    static bool is_bit_set(int xor_val, int index) {
        return xor_val&(1<<index);
    }
};
```

> 输出结果：

``` txt
2, 4
2, 4
```

上面的代码忽略了这么一个细节：任何数异或0还等于该数。所以，更精简的代码如下。

``` cpp
#include <iostream>
#include <vector>

#define NELEM(arr) (sizeof(arr)/sizeof(arr[0]))

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
        if (data.size() < 2 || !num1 || !num2) {
            // 非法的输入，此时不可能找到两个仅出现一次的数字。
            return;
        }
        // 先将数组中所有元素都异或起来。
        int xor_val = 0;
        for (vector<int>::const_iterator it = data.begin(); it != data.end(); it++) {
            xor_val ^= *it;
        }
        // 找到xor_val中最低的比特位。
        int lowest_bit_index = get_lowest_bit_index(xor_val);
        *num1 = *num2 = 0;
        // 根据该最低比特位作为分割线，分别在两组数中找到唯一出现的那个数。
        for (vector<int>::const_iterator it = data.begin(); it != data.end(); it++) {
            if (is_bit_set(*it, lowest_bit_index)) {
                *num1 ^= *it;
            } else {
                *num2 ^= *it;
            }
        }
    }

private:
    static int get_lowest_bit_index(int xor_val) {
        int mask = 1;
        for (int i = 0; i < sizeof(int)*8; i++) {
            if (mask&xor_val) {
                return i;
            }
            mask <<= 1;
        }
        return -1;
    }

    static bool is_bit_set(int xor_val, int index) {
        return xor_val&(1<<index);
    }
};

int main(int argc, char *argv[])
{
    {
        int arr[] = { 1, 1, 2, 3, 3, 4 };
        int num1, num2;
        Solution().FindNumsAppearOnce(vector<int>(arr, arr+NELEM(arr)), &num1, &num2);
        cout << num1 << ", " << num2 << endl;
    }

    {
        int arr[] = { 2, 4 };
        int num1, num2;
        Solution().FindNumsAppearOnce(vector<int>(arr, arr+NELEM(arr)), &num1, &num2);
        cout << num1 << ", " << num2 << endl;
    }

    return 0;
}
```