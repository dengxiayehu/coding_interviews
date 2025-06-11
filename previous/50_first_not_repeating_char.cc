#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty()) {
            return -1;
        }

        int hash_table[128] = {0};
        for (const char* p = str.c_str(); *p; p++) {
            hash_table[static_cast<int>(*p)]++;
        }
        for (const char* p = str.c_str(); *p; p++) {
            if (hash_table[static_cast<int>(*p)] == 1) {
                return p - str.c_str();
            }
        }

        return -1;
    }
};

int main(int argc, char* argv[]) {
    cout << Solution().FirstNotRepeatingChar("") << endl;
    cout << Solution().FirstNotRepeatingChar("abc") << endl;
    cout << Solution().FirstNotRepeatingChar("aabc") << endl;
    cout << Solution().FirstNotRepeatingChar("aabbcc") << endl;
    cout << Solution().FirstNotRepeatingChar("abbc") << endl;

    return 0;
}