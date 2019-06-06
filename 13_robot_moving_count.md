# 机器人运动范围

> 地上有一个m行n列的方格。一个机器人从坐标（0,0）的格子开始移动，它每次可以向左，向右，向上，向下移动一格，但不能进入行坐标和列坐标的位数之和大于k的格子。例如：当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18；但它不能进入方格（35,38），因为3 + 5+3+8 = 19.请问该机器人最多能到达多少个格子？

这道题同样是在二维数组中运动的，使用回溯法。

``` cpp
#include <iostream>

using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        if (threshold < 0 || rows <= 0 || cols <= 0) {
            return 0;
        }

        bool *v = new bool[rows*cols]();

        int res = moving_count_core(threshold, rows, cols, v, 0, 0);

        delete [] v;

        return res;
    }

private:
    int moving_count_core(const int threshold, const int rows, const int cols, bool v[],
                          const int i, const int j) {
        if (v[i*cols+j] || i < 0 || i >= rows || j < 0 || j >= cols ||
            get_digit_sum(i)+get_digit_sum(j) > threshold) {
            return 0;
        }

        v[i*cols+j] = true;

        return 1 + moving_count_core(threshold, rows, cols, v, i-1, j) +
                   moving_count_core(threshold, rows, cols, v, i+1, j) +
                   moving_count_core(threshold, rows, cols, v, i, j-1) +
                   moving_count_core(threshold, rows, cols, v, i, j+1);
    }

    static int get_digit_sum(int n) {
        int sum = 0;

        while (n) {
            sum += n%10;
            n /= 10;
        }

        return sum;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().movingCount(4, 6, 6) << endl;

    return 0;
}
```

再次强调：回溯法都需要一个标记数组。