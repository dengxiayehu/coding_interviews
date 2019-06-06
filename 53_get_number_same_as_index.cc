#include <iostream>
#include <vector>

#define NELEM(arr) (sizeof(arr)/sizeof(arr[0]))

using namespace std;

class Solution {
public:
    int GetNumberSameAsIndex(vector<int> data) {
        int l = 0;
        int u = data.size()-1;
        while (l <= u) {
            int m = l+((u-l)>>1);
            if (data[m] == m) {
                return m;
            } else if (data[m] > m) {
                u = m-1;
            } else {
                l = m+1;
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[])
{
    {
        int arr[] = { -3, -1, 1, 3, 5 };
        cout << Solution().GetNumberSameAsIndex(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    return 0;
}