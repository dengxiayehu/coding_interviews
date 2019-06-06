# 连续子数组的最大和

> HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

``` cpp
#include <iostream>
#include <vector>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty()) {
            return 0;
        }

        int max_so_far = array[0];
        int max_sum = array[0];
        for (int i = 1; i < array.size(); i++) {
            max_so_far = mymax(max_so_far+array[i], array[i]);
            if (max_so_far > max_sum) {
                max_sum = max_so_far;
            }
        }

        return max_sum;
    }

private:
    int mymax(int a, int b) {
        return a > b ? a : b;
    }
};

int main(int argc, char *argv[])
{
    {
        int arr[] = { 6, -3, -2, 7, -15, 1, 2, 2 };
        cout << Solution().FindGreatestSumOfSubArray(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    {
        int arr[] = { -10, -2, -3, -4, -9 };
        cout << Solution().FindGreatestSumOfSubArray(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    return 0;
}
```

> 输出结果：  
8  
-2  