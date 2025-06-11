#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.empty()) {
            return res;
        }

        permutaion_core(str, 0, str.length() - 1, res);
        sort(res.begin(), res.end());

        return res;
    }

private:
    static void permutaion_core(string& str, int k, const int m, vector<string>& res) {
        if (k == m) {
            // 因为最后一个字符无需再考虑与后面字符交换的场景，故已经是最终的一个排列了。
            res.push_back(str);
            return;
        }

        for (int i = k; i <= m; i++) {
            if (need_swap(str, k, i)) {
                // Current check value is str[i], if str[k .. i - 1] has char equals to str[i],
                // then str[i] cannot be swapped.
                // 假设str[k .. i - 1]中已经出现了和str[i]一样的字符，那说明以str[i]“开头”的子全排列已经
                // 被考虑了，所以需要略过当前的str[i]开头的子全排列。
                swap(str, k, i);
                permutaion_core(str, k + 1, m, res);
                swap(str, k, i);
            }
        }
    }

    static void swap(string& str, int i, int j) {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }

    static bool need_swap(string& str, int start, int end) {
        for (int i = start; i < end; i++) {
            if (str[i] == str[end]) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    {
        vector<string> res = Solution().Permutation("abc");
        for (vector<string>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    {
        vector<string> res = Solution().Permutation("a");
        for (vector<string>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    {
        vector<string> res = Solution().Permutation("ab");
        for (vector<string>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    {
        vector<string> res = Solution().Permutation("aa");
        for (vector<string>::iterator it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}