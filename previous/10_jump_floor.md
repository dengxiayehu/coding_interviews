# 跳台阶

> 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

``` cpp
#include <iostream>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 0) {
            return 0;
        }
        if (number == 1) {
            return 1;
        }
        if (number == 2) {
            return 2;
        }
        int floor_minus_1 = 2;
        int floor_minus_2 = 1;
        int floor;
        for (int i = 3; i <= number; i++) {
            floor = floor_minus_1 + floor_minus_2;
            floor_minus_2 = floor_minus_1;
            floor_minus_1 = floor;
        }

        return floor;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().jumpFloor(-1) << endl;
    cout << Solution().jumpFloor(0) << endl;
    cout << Solution().jumpFloor(1) << endl;
    cout << Solution().jumpFloor(4) << endl;

    return 0;
}
```

> 输出结果：  
0  
0  
1  
5

通过仔细考察题目描述的情况，发现它其实也是斐波那契数列数列的一种应用。