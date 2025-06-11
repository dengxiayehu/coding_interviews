#include <string.h>

#include <iostream>

using namespace std;

class Solution {
public:
    void print_1_to_max_of_n_digits(int n) {
        if (n <= 0) {
            return;
        }

        char* str = new char[n + 1];
        memset(str, '0', n);
        str[n] = '\0';

        while (increment(str, n)) {
            print(str);
        }

        delete[] str;
    }

private:
    static bool increment(char* str, const int n) {
        int take = 0;
        for (int i = n - 1; i >= 0; i--) {
            int num = str[i] - '0' + take;
            if (i == n - 1) {
                ++num;
            }
            if (num >= 10) {
                if (i == 0) {
                    // Overflow.
                    return false;
                }

                int units = num - 10;
                take = 1;
                str[i] = units + '0';
            } else {
                str[i] = num + '0';
                break;
            }
        }

        return true;
    }

    static void print(const char* str) {
        const char* p = str;
        while (*p == '0') {
            p++;
        }
        cout << p << endl;
    }
};

int main(int argc, char const* argv[]) {
    Solution().print_1_to_max_of_n_digits(1);
    Solution().print_1_to_max_of_n_digits(2);
    Solution().print_1_to_max_of_n_digits(3);

    return 0;
}
