# 字符串的排列

> 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

这道题还有个坑坑，输出的结果是按照字典序排列的，故还需要对res进行sort。  
这个牛客网改题目弄得。。

``` cpp
// 注意：此算法无法正确处理字符串中有重复字符的情况。
// 故剑指offer上的算法不能适用于牛客网中的测试用例。
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
```

> 输出结果：  
abc acb bac bca cba cab  
a  
ab ba  
aa aa

***注意：上述算法不能正确处理字符串中有重复字符的情况***  
例如最后的输入示例："aa"，生成了两个相同的排列。

``` cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.empty()) {
            return res;
        }

        permutaion_core(str, 0, str.length()-1, res);
        sort(res.begin(), res.end());

        return res;
    }

private:
    static void permutaion_core(string& str, int k, const int m, vector<string> &res) {
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
                permutaion_core(str, k+1, m, res);
                swap(str, k, i);
            }
        }
    }

    static void swap(string &str, int i, int j) {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }

    static bool need_swap(string &str, int start, int end) {
        for (int i = start; i < end; i++) {
            if (str[i] == str[end]) {
                return false;
            }
        }

        return true;
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
```

> 输出结果：  
abc acb bac bca cab cba  
a  
ab ba  
aa