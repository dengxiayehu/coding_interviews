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
