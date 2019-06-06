# 左旋转字符串

> 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

``` cpp
#include <iostream>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty() || n < 0) {
            return "";
        }
        n %= str.length();
        if (n == 0) {
            return str;
        }
        reverse_string(str, 0, n-1);
        reverse_string(str, n, str.length()-1);
        reverse_string(str, 0, str.length()-1);
        return str;
    }

private:
    static void reverse_string(string& str, int begin_idx, int end_idx) {
        while (begin_idx < end_idx) {
            char ch = str[begin_idx];
            str[begin_idx] = str[end_idx];
            str[end_idx] = ch;
            begin_idx++;
            end_idx--;
        }
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().LeftRotateString("abcXYZdef", 3) << endl;

    return 0;
}
```

输出结果：

``` txt
XYZdefabc
```