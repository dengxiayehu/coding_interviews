#include <limits.h>

#include <iostream>

using namespace std;

class Solution {
public:
    Solution() : index_(0) {
        for (int i = 0; i < 256; i++) {
            hash_table_[i] = -1;
        }
    }

    void Insert(char ch) {
        if (hash_table_[static_cast<int>(ch)] == -1) {
            // First apperance of char |ch|.
            hash_table_[static_cast<int>(ch)] = index_;
        } else if (hash_table_[static_cast<int>(ch)] >= 0) {
            // Char |ch| already found, set to -2 to indicates duplication.
            hash_table_[static_cast<int>(ch)] = -2;
        }
        index_++;
    }

    char FirstAppearingOnce() {
        char res = '#';
        int min_idx = INT_MAX;
        for (int i = 0; i < 256; i++) {
            if (hash_table_[i] >= 0) {            // 字符i出现了一次
                if (hash_table_[i] <= min_idx) {  // 字符i出现的位置比较靠前
                    min_idx = hash_table_[i];
                    res = static_cast<char>(i);
                }
            }
        }
        return res;
    }

private:
    int hash_table_[256];
    int index_;
};

int main(int argc, char* argv[]) {
    Solution s;
    s.Insert('g');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('o');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('o');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('g');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('l');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('e');
    cout << s.FirstAppearingOnce() << endl;

    return 0;
}