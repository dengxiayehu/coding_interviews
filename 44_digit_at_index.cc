#include <iostream>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    int digitAtIndex(int index) {
        if (index < 0) {
            return -1;
        }

        int digits = 1;
        for ( ; ; ) {
            int num_count = get_digit_num_count(digits);
            if (index < num_count) {
                return get_digit(digits, index);
            }
            index -= num_count;
            digits++;
        }

        return 0;
    }

private:
    static int get_digit_num_count(int digits) {
        if (digits == 1) {
            return 10; // 0~9
        }

        // digit=2 10~99=90个
        // digit=3 100~999=900个
        // digit=n 10^(n-1)~10^n-1=10^n-10^(n-1)
        return mypow(10, digits)-mypow(10, digits-1);
    }

    static int mypow(int base, int exp) {
        if (exp == 0) {
            return 1;
        }

        return ((exp&1)?base:1)*(mypow(base*base, exp>>1));
    }

    static int get_digit(int digits, int index) {
        int begin_num = get_begin_number(digits);
        int num = begin_num+index/digits;
        int digit_off_right = digits-index%digits;
        for (int i = 1; i < digit_off_right; i++) {
            num /= 10;
        }
        return num%10;
    }

    static int get_begin_number(int digits) {
        if (digits == 1) {
            return 0;
        }

        // digits=2 10
        // digits=3 100
        // digits=4 1000
        return mypow(10, digits-1);
    }
};

int main(int argc, char *argv[])
{
    cout << 0 << "th " << Solution().digitAtIndex(0) << endl;
    cout << 1 << "st " << Solution().digitAtIndex(1) << endl;
    cout << 9 << "th " << Solution().digitAtIndex(9) << endl;
    cout << 10 << "th " << Solution().digitAtIndex(10) << endl;
    cout << 13 << "th " << Solution().digitAtIndex(13) << endl;
    cout << 19 << "th " << Solution().digitAtIndex(19) << endl;

    return 0;
}