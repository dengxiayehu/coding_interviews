#include <iostream>

using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0) {
            // Invalid index.
            return 0;
        }

        int* ugly_numbers = new int[index];
        ugly_numbers[0] = 1;

        int* ugly_mul2 = ugly_numbers;
        int* ugly_mul3 = ugly_numbers;
        int* ugly_mul5 = ugly_numbers;

        for (int next_ugly_index = 1; next_ugly_index < index; next_ugly_index++) {
            ugly_numbers[next_ugly_index] = min3(*ugly_mul2 * 2, *ugly_mul3 * 3, *ugly_mul5 * 5);
            while (*ugly_mul2 * 2 <= ugly_numbers[next_ugly_index]) {
                ++ugly_mul2;
            }
            while (*ugly_mul3 * 3 <= ugly_numbers[next_ugly_index]) {
                ++ugly_mul3;
            }
            while (*ugly_mul5 * 5 <= ugly_numbers[next_ugly_index]) {
                ++ugly_mul5;
            }
        }

        int res = ugly_numbers[index - 1];

        delete[] ugly_numbers;

        return res;
    }

private:
    static int min3(int a, int b, int c) {
        return std::min(std::min(a, b), c);
    }
};

int main(int argc, char* argv[]) {
    cout << Solution().GetUglyNumber_Solution(1) << endl;
    cout << Solution().GetUglyNumber_Solution(2) << endl;
    cout << Solution().GetUglyNumber_Solution(3) << endl;
    cout << Solution().GetUglyNumber_Solution(4) << endl;
    cout << Solution().GetUglyNumber_Solution(5) << endl;
    cout << Solution().GetUglyNumber_Solution(6) << endl;
    cout << Solution().GetUglyNumber_Solution(7) << endl;
    cout << Solution().GetUglyNumber_Solution(8) << endl;

    return 0;
}