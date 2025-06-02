#include <cstdio>
#include <cstring>
#include <iostream>

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

        return number_of_1_between_1_and_n_core(str);
        ;
    }

private:
    static int number_of_1_between_1_and_n_core(const char* str) {
        if (!*str) {
            return 0;
        }

        // 21345: 1345~21345 1~1345
        const int length = strlen(str);
        const char first = str[0] - '0';
        int count = 0;
        if (first > 1) {
            count += myxpow(10, length - 1);
        } else if (first == 1) {
            // 当前数字为0时，当前肯定没有1的数字。
            count += atoi(str + 1) + 1;
        }
        int other = first * (length - 1) * myxpow(10, length - 2);

        return count + other + number_of_1_between_1_and_n_core(str + 1);
    }

    // 特殊的乘方函数，当exp为负数时，返回值为0。
    static int myxpow(int base, int exp) {
        if (exp < 0) {
            return 0;
        }

        if (exp == 0) {
            return 1;
        }

        int result = (exp & 1) ? base : 1;

        return result * myxpow(base * base, exp >> 1);
    }
};

int main(int argc, char* argv[]) {
    cout << Solution().NumberOf1Between1AndN_Solution(12) << endl;
    cout << Solution().NumberOf1Between1AndN_Solution(1) << endl;
    cout << Solution().NumberOf1Between1AndN_Solution(13) << endl;
    cout << Solution().NumberOf1Between1AndN_Solution(1345) << endl;
    cout << Solution().NumberOf1Between1AndN_Solution(21345) << endl;
    cout << Solution().NumberOf1Between1AndN_Solution(10) << endl;

    return 0;
}