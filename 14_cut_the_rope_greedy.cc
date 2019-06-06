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
