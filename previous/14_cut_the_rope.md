# 剪绳子

> 给定一根长度为n的绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0],k[1],…,k[m]。请问k[0]* k[1] *…*k[m]可能的最大乘积是多少？  
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

首先可以使用自底向上的动态规划算法，这样就避免了自顶向下算法需要的临时数组（用以保存中间情况的值）。

``` cpp
#include <iostream>

using namespace std;

// 至少切一刀。

class Solution {
public:
    int foo(int length) {
        if (length <= 1) {
            return 0;
        }
        if (length == 2) {
            // 切成1+1两段。
            return 1;
        }
        if (length == 3) {
            // 切成1+2两段。
            return 2;
        }
        // 之所以只要判断到length=3是因为在length=4时，可以被length=2+2的情况考虑到。

        int *max = new int[length+1]();

        max[0] = 0;
        max[1] = 1;
        max[2] = 2;
        max[3] = 3;

        for (int i = 4; i <= length; i++) {
            for (int j = 1; j <= (i>>1); j++) { // j从1开始表示至少切一刀。
                int tmp = max[j]*max[i-j];
                if (tmp > max[i]) {
                    max[i] = tmp;
                }
            }
        }

        delete [] max;

        return max[length];
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().foo(0) << endl;
    cout << Solution().foo(1) << endl;
    cout << Solution().foo(2) << endl;
    cout << Solution().foo(3) << endl;
    cout << Solution().foo(4) << endl;
    cout << Solution().foo(8) << endl;

    return 0;
}
```

> 输出结果：  
0  
0  
1  
2  
4  
18

## 贪心算法

尽可能得多切出长度为3的绳子。当剩余绳子的长度是4时，则将绳子切成2+2两段这样最优。

贪心算法是一个难点，还需证明为何这样的选择是最优的。

``` cpp
#include <iostream>

using namespace std;

class Solution {
public:
    int foo(int length) {
        if (length <= 1) {
            return 0;
        }
        if (length == 2) {
            return 1;
        }
        if (length == 3) {
            return 2;
        }

        int times_of_3 = length/3;
        int left = length - times_of_3*3;
        if (left == 1) {
            times_of_3 -= 1;
            left += 3;
        }
        int times_of_2 = (left>>1);

        return mypow(3, times_of_3) * mypow(2, times_of_2);
    }

private:
    int mypow(int num, int exp) {
        if (exp == 0) {
            return 1;
        }

        return ((exp&1) ? num : 1)*mypow(num*num, exp>>1);
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().foo(0) << endl;
    cout << Solution().foo(1) << endl;
    cout << Solution().foo(2) << endl;
    cout << Solution().foo(3) << endl;
    cout << Solution().foo(4) << endl;
    cout << Solution().foo(8) << endl;

    return 0;
}
```

注意其中的快速乘方算法。