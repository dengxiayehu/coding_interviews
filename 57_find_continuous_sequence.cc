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