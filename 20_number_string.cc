#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // 表示数值的字符串有如下两种形式：
    // （1）A[.[B]][e|EC]，eg: 2 2. 2e3 2.e3
    // （2）.B[e|EC]，eg: .2e3
    // 其中，A、C是有符号数，B是无符号数。
    bool isNumeric(char* string) {
        if (!string || !string[0]) {
            return false;
        }

        bool numberic = scan_int(string);
        if (*string == '.') {
            numberic = scan_uint(++string) || numberic;
        }
        if (*string == 'E' || *string == 'e') {
            numberic = scan_int(++string) && numberic;
        }

        return numberic && *string == '\0';
    }

private:
    static bool scan_int(char *&string) {
        if (*string == '+' || *string == '-') {
            ++string;
        }
        return scan_uint(string);
    }

    static bool scan_uint(char *&string) {
        char *save = string;
        while (*string && *string >= '0' && *string <= '9') {
            ++string;
        }
        return string > save; // got some digits
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().isNumeric(const_cast<char*>(string("2").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("2.").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("2.e").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("2.e3").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("2.e-3").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("2.1e-3").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string(".1e-3").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("1e+3").c_str())) << endl;
    cout << Solution().isNumeric(const_cast<char*>(string("1e").c_str())) << endl;

    return 0;
}
