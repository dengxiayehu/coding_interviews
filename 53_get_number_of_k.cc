#include <iostream>
#include <vector>

#define NELEM(arr) (sizeof(arr) / sizeof(arr[0]))

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        int first = get_first_number_of_k(data, k);
        int last = get_last_number_of_k(data, k);
        if (first != -1 && last != -1) {
            return last - first + 1;
        }
        return 0;
    }

private:
    static int get_first_number_of_k(const vector<int>& data, int k) {
        int l = 0;
        int u = data.size() - 1;
        while (l <= u) {
            int m = l + ((u - l) >> 1);
            if (data[m] == k) {
                if (m == 0 || data[m - 1] != k) {
                    return m;
                } else {
                    u = m - 1;
                }
            } else if (data[m] >= k) {
                u = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }

    static int get_last_number_of_k(const vector<int>& data, int k) {
        int l = 0;
        int u = data.size() - 1;
        while (l <= u) {
            int m = l + ((u - l) >> 1);
            if (data[m] == k) {
                if (m == data.size() - 1 || data[m + 1] != k) {
                    return m;
                } else {
                    l = m + 1;
                }
            } else if (data[m] >= k) {
                u = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
    {
        int arr[] = {1, 2, 2, 3};
        cout << Solution().GetNumberOfK(vector<int>(arr, arr + NELEM(arr)), 2) << endl;
    }

    {
        int arr[] = {1, 2, 2, 3};
        cout << Solution().GetNumberOfK(vector<int>(arr, arr + NELEM(arr)), 0) << endl;
    }

    {
        int arr[] = {2, 2, 2, 2};
        cout << Solution().GetNumberOfK(vector<int>(arr, arr + NELEM(arr)), 2) << endl;
    }

    {
        int arr[] = {2};
        cout << Solution().GetNumberOfK(vector<int>(arr, arr + NELEM(arr)), 2) << endl;
    }

    return 0;
}