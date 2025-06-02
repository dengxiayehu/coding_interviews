#include <iostream>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.empty() || n < 0) {
            return "";
        }
        n %= str.length();
        if (n == 0) {
            return str;
        }
        reverse_string(str, 0, n - 1);
        reverse_string(str, n, str.length() - 1);
        reverse_string(str, 0, str.length() - 1);
        return str;
    }

private:
    static void reverse_string(string& str, int begin_idx, int end_idx) {
        while (begin_idx < end_idx) {
            char ch = str[begin_idx];
            str[begin_idx] = str[end_idx];
            str[end_idx] = ch;
            begin_idx++;
            end_idx--;
        }
    }
};

int main(int argc, char* argv[]) {
    cout << Solution().LeftRotateString("abcXYZdef", 3) << endl;

    return 0;
}