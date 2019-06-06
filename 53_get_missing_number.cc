#include <iostream>
#include <vector>

#define NELEM(arr) (sizeof(arr)/sizeof(arr[0]))

using namespace std;

class Solution {
public:
    int GetMissingNumber(vector<int> data)
    {
        const int data_size = data.size();
        int l = 0;
        int u = data_size-1;
        while (l <= u) {
            int m = l+((u-l)>>1);
            if (data[m] == m) { // 左半区域
                l = m+1;
            } else if (data[m] > m) {
                if (m == 0 || data[m-1] == m-1) { // 找到
                    return m;
                } else { // 再往左侧找找
                    u = m-1;
                }
            } else {
                // Never happen.
            }
        }
        if (l == data_size) {
            return data_size;
        }
        return -1;
    }
};

int main(int argc, char *argv[])
{
    {
        int arr[] = { 0, 1, 2, 4, 5 }; // n=6，数字的范围是0~5，数组长度是5
        // index is:  0, 1, 2, 3, 4, so get the first number greater than its index.
        cout << Solution().GetMissingNumber(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    {
        int arr[] = { 1, 2, 3, 4, 5 };
        // index is:  0, 1, 2, 3, 4
        cout << Solution().GetMissingNumber(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    {
        int arr[] = { 0, 2, 3, 4, 5 };
        // index is:  0, 1, 2, 3, 4
        cout << Solution().GetMissingNumber(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    {
        int arr[] = { 0, 1, 2, 3, 4 };
        // index is:  0, 1, 2, 3, 4
        cout << Solution().GetMissingNumber(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    return 0;
}