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
