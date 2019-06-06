#include <iostream>

using namespace std;

class Solution {
public:
    int  NumberOf1(int n) {
        int count = 0;
        while (n) {
            n &= (n-1);
            count++;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().NumberOf1(-8) << endl;
    cout << Solution().NumberOf1(0xFFFFFFF8) << endl;
    cout << Solution().NumberOf1(0x7FFFFFFF) << endl;
    cout << Solution().NumberOf1(0x80000000) << endl;
    cout << Solution().NumberOf1(-1) << endl;

    return 0;
}
