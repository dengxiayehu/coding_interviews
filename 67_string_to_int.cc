#include <iostream>
#include <ctype.h>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        const unsigned int strLen = str.length();
        unsigned int i = 0;
        bool negative = false;
        int res = 0;

        // Remove leading space(s).
        for (i = 0; i < strLen; i++) {
            if (!isspace(str[i])) {
                // Got a non-space char.
                break;
            }
        }
        if (i == strLen) {
            // Full of spaces, just return 0.
            return 0;
        }

        // Get the sign.
        if (str[i] == '-') {
            i++;
            negative = true;
        } else if (str[i] == '+') {
            i++;
        }

        while (i < strLen) {
            char ch = str[i];
            if (!isdigit(ch)) {
                // Illegale character occurred, just return 0.
                return 0;
            }

            int num = ch-'0';
            // Check overflow.
            if (negative) {
                if ((res < INT_MAX/10) || (res == INT_MAX/10 && num <= 8)) {
                    res = res*10 + num;
                } else {
                    // Negative overflow.
                    return INT_MIN;
                }
            } else {
                if ((res < INT_MAX/10) || (res == INT_MAX/10 && num <= 7)) {
                    res = res*10 + num;
                } else {
                    // Positive overflow.
                    return INT_MAX;
                }
            }

            i++;
        }

        return negative ? -res : res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str;

    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "     ";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "  +123";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "  -123";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "1a33";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "-2147483648";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "-2147483649";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "-2147483650";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "+2147483647";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "+2147483648";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "+2147483650";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    str = "123";
    cout << "str: [" + str + "], StrToInt: " << s.StrToInt(str) << endl;

    return 0;
}
