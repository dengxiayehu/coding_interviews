#include <iostream>
#include <string>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    int GetTranslationCount(int number) {
        string str_number = to_string(number);
        int *res = new int[str_number.size()];
        GetTranslationCount(str_number, res, str_number.size(), str_number.length()-1);
        int count = res[0];
        delete [] res;

        return count;
    }

private:
    // 状态转移方程：f(i) = f(i+1)+g(i,i+1)*f(i+2)。
    // 当str_number[i]str_number[i+1]在[10, 25]时，g(i,i+1)=1，否则为0。
    void GetTranslationCount(const string &str_number, int res[], const int n, int index) {
        if (index < 0) {
            return;
        }
        int count = 1;
        if (index < n-1) {
            count = res[index+1];
            int val = (str_number[index]-'0')*10+(str_number[index+1]-'0');
            if (val >= 10 && val <= 25) {
                if (index < n-2) {
                    count += res[index+2];
                } else {
                    count += 1;
                }
            }
        }
        res[index] = count;
        GetTranslationCount(str_number, res, n, index-1);
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().GetTranslationCount(12258) << endl;
    cout << Solution().GetTranslationCount(0) << endl;
    cout << Solution().GetTranslationCount(10) << endl;
    cout << Solution().GetTranslationCount(100) << endl;

    return 0;
}