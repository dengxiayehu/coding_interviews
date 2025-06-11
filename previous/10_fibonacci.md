# 斐波那契数列

> 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39

``` cpp
#include <iostream>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int fb_minus_1 = 1;
        int fb_minus_2 = 0;
        int fb;
        for (int i = 2; i <= n; i++) {
            fb = fb_minus_1 + fb_minus_2;
            fb_minus_2 = fb_minus_1;
            fb_minus_1 = fb;
        }
        return fb;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().Fibonacci(0) << endl;
    cout << Solution().Fibonacci(1) << endl;
    cout << Solution().Fibonacci(2) << endl;
    cout << Solution().Fibonacci(3) << endl;
    cout << Solution().Fibonacci(10) << endl;

    return 0;
}
```

> 输出结果：  
0  
1  
1  
2  
55

这道题主要考察递归算法的非递归算法。