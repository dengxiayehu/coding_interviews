# 青蛙变态跳台阶

> 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

若n=1，则跳法有1种；  
若n=2，则跳法有1（跳1阶后再跳1阶）+1（直接跳两阶）=2种，也就是f(1)+1，2^1  
若n=3，则跳法有f(2)+f(1)+1=2+1+1=4，2^2  
若n=4，则跳法有f(3)+f(2)+f(1)+1=4+2+1+1=8，2^3  
...  
总结下来就是2^(n-1)

``` cpp
#include <iostream>

using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        if (number <= 0) {
            return 0;
        }

        return mypow(2, number-1); // 快速乘方算法
    }

private:
    int mypow(int x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n&1) { // n is odd
            return x*mypow(x*x, n/2);
        } else { // n is even
            return mypow(x*x, n/2);
        }
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().jumpFloorII(-1) << endl;
    cout << Solution().jumpFloorII(0) << endl;
    cout << Solution().jumpFloorII(1) << endl;
    cout << Solution().jumpFloorII(2) << endl;
    cout << Solution().jumpFloorII(3) << endl;
    cout << Solution().jumpFloorII(10) << endl;

    return 0;
}
```

> 输出结果：  
0  
0  
1  
2  
4  
512

这道题可以换个思路，在台阶n下面的所有的台阶上，都可以选择跳还是不跳，所以总的情况就是2^(n-1)。