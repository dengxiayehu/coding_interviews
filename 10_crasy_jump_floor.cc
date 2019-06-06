#include <iostream>

using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        if (number <= 0) {
            return 0;
        }

        return mypow(2, number-1);
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
