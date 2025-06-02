#include <iostream>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if (n * m == 0) {
            // 非法的输入
            return -1;
        }
        int last = 0;
        for (int i = 2; i <= n; i++) {
            last = (last + m) % i;
        }
        return last;
    }
};

int main(int argc, char* argv[]) {
    cout << Solution().LastRemaining_Solution(10, 3) << endl;
    return 0;
}