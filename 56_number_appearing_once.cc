#include <iostream>
#include <vector>

#define NELEM(arr) (sizeof(arr)/sizeof(arr[0]))

using namespace std;

class Solution {
public:
    int FindNumberappearingOnce(vector<int> data) {
        if (data.empty()) {
            return 0;
        }
        int *bit_num = new int[sizeof(int)<<3]();
        for (vector<int>::const_iterator it = data.begin(); it != data.end(); it++) {
            for (int idx = 0, mask = 1;  idx < sizeof(int)<<3; idx++) {
                if (mask&*it) {
                    ++bit_num[idx];
                }
                mask <<= 1;
            }
        }
        int res = 0;
        for (int i = (sizeof(int)<<3)-1; i >= 0; i--) {
            // 尤其注意下面这句话，先左移1位后再相与。
            res <<= 1;
            res |= bit_num[i]%3;
        }
        delete [] bit_num;

        return res;
    }
};

int main(int argc, char *argv[])
{
    {
        // 11
        // 10
        // 10
        // 10
        int arr[] = { 3, 2, 2, 2 }; // 返回3
        cout << Solution().FindNumberappearingOnce(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    {
        int arr[] = { 3 }; // 返回3
        cout << Solution().FindNumberappearingOnce(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    {
        int arr[] = { 2, 2, 2 }; // 返回0
        cout << Solution().FindNumberappearingOnce(vector<int>(arr, arr+NELEM(arr))) << endl;
    }

    return 0;
}