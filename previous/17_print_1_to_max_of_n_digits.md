# 打印1到最大的N位数

> 输入数字n,按顺序打印出从1到最大的n位十进制数，比如输入3,则打印出1,2,3一直到最大的3位数即999。

题目没有告诉我们n的范围，那么默认这是一道大数题。需要结合字符串来进行解决。

``` cpp
#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    void print_1_to_max_of_n_digits(int n) {
        if (n <= 0) {
            return;
        }

        char *str = new char[n+1];
        memset(str, '0', n);
        str[n] = '\0';

        while (increment(str, n)) {
            print(str);
        }

        delete [] str;
    }

private:
    static bool increment(char *str, const int n) {
        int take = 0;
        for (int i = n-1; i >= 0; i--) {
            int num = str[i]-'0'+take;
            if (i == n-1) {
                ++num;
            }
            if (num >= 10) {
                if (i == 0) {
                    // Overflow.
                    return false;
                }

                int units = num-10;
                take = 1;
                str[i] = units+'0';
            } else {
                str[i] = num+'0';
                break;
            }
        }

        return true;
    }

    static void print(const char *str) {
        const char *p = str;
        while (*p == '0') {
            p++;
        }
        cout << p << endl;
    }
};

int main(int argc, char const *argv[])
{
    Solution().print_1_to_max_of_n_digits(1);
    Solution().print_1_to_max_of_n_digits(2);
    Solution().print_1_to_max_of_n_digits(3);

    return 0;
}
```

这道题的另一种解法是将其看成一个全排列的问题。每个位上都可能存在'0'~'9'。

``` cpp
#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    void print_1_to_max_of_n_digits(int n) {
        if (n <= 0) {
            return;
        }

        char *str = new char[n+1];
        memset(str, '0', n);
        str[n] = '\0';

        print_1_to_max_of_n_digits_core(str, n, 0);

        delete [] str;
    }

private:
    static void print_1_to_max_of_n_digits_core(char *str, int n, int idx) {
        if (str[idx] == '\0') {
            print(str);
            return;
        }

        for (char ch = '0'; ch <= '9'; ch++) {
            str[idx] = ch;
            print_1_to_max_of_n_digits_core(str, n, idx+1);
        }
    }

    static void print(const char *str) {
        const char *p = str;
        while (*p == '0') {
            p++;
        }
        cout << p << endl;
    }
};

int main(int argc, char const *argv[])
{
    Solution().print_1_to_max_of_n_digits(1);
    Solution().print_1_to_max_of_n_digits(2);
    Solution().print_1_to_max_of_n_digits(3);

    return 0;
}
```