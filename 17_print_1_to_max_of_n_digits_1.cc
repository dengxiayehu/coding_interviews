#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    void print_1_to_max_of_n_digits(int n) {
        if (n <= 0) {
            return;
        }

        char *str = new char[n+1];
        memset(str, '0', n);
        str[n] = '\0';

        print_1_to_max_of_n_digits_core(str, n, 0);

        delete [] str;
    }

private:
    static void print_1_to_max_of_n_digits_core(char *str, int n, int idx) {
        if (str[idx] == '\0') {
            print(str);
            return;
        }

        for (char ch = '0'; ch <= '9'; ch++) {
            str[idx] = ch;
            print_1_to_max_of_n_digits_core(str, n, idx+1);
        }
    }

    static void print(const char *str) {
        const char *p = str;
        while (*p == '0') {
            p++;
        }
        cout << p << endl;
    }
};

int main(int argc, char const *argv[])
{
    Solution().print_1_to_max_of_n_digits(1);
    Solution().print_1_to_max_of_n_digits(2);
    Solution().print_1_to_max_of_n_digits(3);

    return 0;
}
