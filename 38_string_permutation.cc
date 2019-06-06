#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.empty()) {
            return res;
        }

        permutaion_core(str, 0, res);

        return res;
    }

private:
    void permutaion_core(string& str, int idx, vector<string> &res) {
        if (idx == str.length()) {
            res.push_back(str);
            return;
        }

        permutaion_core(str, idx+1, res);
        for (int i = idx+1; i < str.length(); i++) {
            char t = str[idx];
            str[idx] = str[i];
            str[i] = t;

            permutaion_core(str, idx+1, res);

            t = str[idx];
            str[idx] = str[i];
            str[i] = t;
        }
    }
};

int main(int argc, char *argv[])
{
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