# 整数中1出现的次数（从1到n整数中1出现的次数）

> 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。

``` cpp
#include <iostream>
#include <cstdio>
#include <cstring>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        if (n <= 0) {
            // 不存在任何有1的数字。
            return 0;
        }

        char str[128];
        sprintf(str, "%d", n);

        return number_of_1_between_1_and_n_core(str);;
    }

private:
    static int number_of_1_between_1_and_n_core(const char *str) {
        if (!*str) {
            return 0;
        }

        // 21345: 1345~21345 1~1345
        const int length = strlen(str);
        const char first = str[0]-'0';
        int count = 0;
        if (first > 1) {
            count += myxpow(10, length-1);
        } else if (first == 1) {
            // 当前数字为0时，当前肯定没有1的数字。
            count += atoi(str+1)+1;
        }
        int other = first*(length-1)*myxpow(10, length-2);

        return count+other+number_of_1_between_1_and_n_core(str+1);
    }

    // 特殊的乘方函数，当exp为负数时，返回值为0。
    static int myxpow(int base, int exp) {
        if (exp < 0) {
            return 0;
        }

        if (exp == 0) {
            return 1;
        }

        int result = (exp&1) ? base : 1;

        return result*myxpow(base*base, exp>>1);
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().NumberOf1Between1AndN_Solution(12) << endl;
    cout << Solution().NumberOf1Between1AndN_Solution(1) << endl;
    cout << Solution().NumberOf1Between1AndN_Solution(13) << endl;
    cout << Solution().NumberOf1Between1AndN_Solution(1345) << endl;
    cout << Solution().NumberOf1Between1AndN_Solution(21345) << endl;
    cout << Solution().NumberOf1Between1AndN_Solution(10) << endl;

    return 0;
}
```

> 输出结果：  
5  
1  
6  
821  
18821  
2  