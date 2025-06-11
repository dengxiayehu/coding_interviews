#include <iostream>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        int len = str.length();
        if (len <= 1) {
            return str;
        }
        reverse_string(str, 0, len - 1);
        int begin = -1;
        int end = -1;
        for (int i = 0; i < len; i++) {
            while (str[i] && (str[i] == ' ' || str[i] == '\t')) {
                i++;
            }
            if (!str[i]) {
                return str;
            }
            begin = i;
            while (str[i] && (str[i] != ' ' && str[i] != '\t')) {
                i++;
            }
            end = i - 1;
            reverse_string(str, begin, end);
        }
        return str;
    }

private:
    static void reverse_string(string& str, int begin, int end) {
        while (begin < end) {
            char tmp = str[begin];
            str[begin] = str[end];
            str[end] = tmp;
            begin++;
            end--;
        }
    }
};

int main(int argc, char* argv[]) {
    cout << Solution().ReverseSentence("I am a student.") << endl;
    return 0;
}