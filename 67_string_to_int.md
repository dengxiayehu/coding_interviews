# 字符串转整数

## 题目描述

将一个字符串转换成一个整数（实现`Integer.valueOf(string)`的功能，但是`string`不符合数字要求时返回0），要求不能使用字符串转换整数的库函数。数值为0或者字符串不是一个合法的数值则返回0。

输入描述：
> 输入一个字符串，包括数字字母符号，可以为空

输出描述：
> 如果是合法的数值表达式则返回该数字，否则返回0

示例1
> 输入
>> +2147483647  
>> &nbsp; &nbsp; &nbsp; &nbsp; 1a33

> 输出
>> 2147483647  
>> 0

## 分析

这道题主要考察的是程序的鲁棒性，充分考虑各种可能的输入后程序还能正常工作。我们先想一下这个程序的测试case：

1. 输入的字符串为空“”
2. 输入的字符串包含前导空格
3. 输入的字符串包含正负符号
4. 输入的字符串中包含非数字字符（除了开始的+-）
5. 输入的字符串相对于int的表示范围越界

难点在于合法性的检测以及越界时的处理。首先要清楚int型数字表示的范围是[-2147483648, +2147483647]。我们的代码中最好不要出现long型等范围更宽的类型。所以在判断是否越界时，可以如下进行：

1. 数字若为负，则在计算当前字符时，判断之前的和是否<=214748364，且当前数字是'0'~'8'，若此，则没越界；否则就越界了，返回-2147483648
2. 若数字为正，则在计算当前字符时，判断之前的和是否<=214748364，且当前数字是'0'~'7'，若此，则没越界；否则就越界了，返回2147483647
3. 214748364这个数可以通过INT_MAX/10得到

``` cpp
#include <iostream>
#include <ctype.h>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        const unsigned int strLen = str.length();
        unsigned int i = 0;
        bool negative = false;
        int res = 0;

        // Remove leading space(s).
        for (i = 0; i < strLen; i++) {
            if (!isspace(str[i])) {
                // Got a non-space char.
                break;
            }
        }
        if (i == strLen) {
            // Full of spaces, just return 0.
            return 0;
        }

        // Get the sign.
        if (str[i] == '-') {
            i++;
            negative = true;
        } else if (str[i] == '+') {
            i++;
        }

        while (i < strLen) {
            char ch = str[i];
            if (!isdigit(ch)) {
                // Illegale character occurred, just return 0.
                return 0;
            }

            int num = ch-'0';
            // Check overflow.
            if (negative) {
                if ((res < INT_MAX/10) || (res == INT_MAX/10 && num <= 8)) {
                    res = res*10 + num;
                } else {
                    // Negative overflow.
                    return INT_MIN;
                }
            } else {
                if ((res < INT_MAX/10) || (res == INT_MAX/10 && num <= 7)) {
                    res = res*10 + num;
                } else {
                    // Positive overflow.
                    return INT_MAX;
                }
            }

            i++;
        }

        return negative ? -res : res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str;

    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "     ";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "  +123";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "  -123";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "1a33";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "-2147483648";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "-2147483649";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "-2147483650";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "+2147483647";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "+2147483648";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "+2147483650";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "123";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    return 0;
}
```

> 输出结果：  
./string_to_int_run  
str: [], StrToInt: 0  
str: [     ], StrToInt: 0  
str: [  +123], StrToInt: 123  
str: [  -123], StrToInt: -123  
str: [1a33], StrToInt: 0  
str: [-2147483648], StrToInt: -2147483648  
str: [-2147483649], StrToInt: -2147483648  
str: [-2147483650], StrToInt: -2147483648  
str: [+2147483647], StrToInt: 2147483647  
str: [+2147483648], StrToInt: 2147483647  
str: [+2147483650], StrToInt: 2147483647  
str: [123], StrToInt: 123  
