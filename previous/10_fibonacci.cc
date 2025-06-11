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

int main(int argc, char const* argv[]) {
    cout << Solution().Fibonacci(0) << endl;
    cout << Solution().Fibonacci(1) << endl;
    cout << Solution().Fibonacci(2) << endl;
    cout << Solution().Fibonacci(3) << endl;
    cout << Solution().Fibonacci(10) << endl;

    return 0;
}
