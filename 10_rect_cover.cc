#include <iostream>

using namespace std;

class Solution {
public:
    int rectCover(int number) {
        if (number <= 0) {
            return 0;
        }
        if (number == 1) {
            return 1;
        }
        if (number == 2) {
            return 2;
        }
        int res;
        int fb_minus_1 = 2;
        int fb_minus_2 = 1;
        for (int i = 3; i <= number; i++) {
            res = fb_minus_1 + fb_minus_2;
            fb_minus_2 = fb_minus_1;
            fb_minus_1 = res;
        }

        return res;
    }
};

int main(int argc, char const* argv[]) {
    cout << Solution().rectCover(-1) << endl;
    cout << Solution().rectCover(0) << endl;
    cout << Solution().rectCover(1) << endl;
    cout << Solution().rectCover(2) << endl;
    cout << Solution().rectCover(3) << endl;
    cout << Solution().rectCover(8) << endl;
    cout << Solution().rectCover(10) << endl;

    return 0;
}
