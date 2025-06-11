# 和为S的连续正数序列

> 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

输出描述：

> 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序。

``` cpp
#include <iostream>
#include <vector>

#define NELEM(arr) (sizeof(arr)/sizeof(arr[0]))

using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if (sum < 3 /*1+2=3*/) {
            return res;
        }
        int low = 1;
        int high = 2;
        int cursum = low+high;
        do {
            if (cursum == sum) {
                vector<int> tmpv;
                for (int i = low; i <= high; i++) {
                    tmpv.push_back(i);
                }
                res.push_back(tmpv);
                cursum -= low++;
            } else if (cursum < sum) {
                cursum += ++high;
            } else {
                cursum -= low++;
            }
        } while (low < high);
        return res;
    }
};

int main(int argc, char *argv[])
{
    {
        vector<vector<int> > res = Solution().FindContinuousSequence(100);
        for (vector<vector<int> >::const_iterator itvv = res.begin(); itvv != res.end(); itvv++) {
            const vector<int>& candidate = *itvv;
            for (vector<int>::const_iterator itv = candidate.begin(); itv != candidate.end(); itv++) {
                cout << *itv << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    {
        vector<vector<int> > res = Solution().FindContinuousSequence(1000);
        for (vector<vector<int> >::const_iterator itvv = res.begin(); itvv != res.end(); itvv++) {
            const vector<int>& candidate = *itvv;
            for (vector<int>::const_iterator itv = candidate.begin(); itv != candidate.end(); itv++) {
                cout << *itv << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
```

输出结果：

``` txt
9 10 11 12 13 14 15 16 
18 19 20 21 22 

28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 
55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 
198 199 200 201 202 

```
