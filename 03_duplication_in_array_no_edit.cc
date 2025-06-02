#include <iostream>

using namespace std;

#define NELEM(arr) sizeof(arr) / sizeof(arr[0])

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers, all elements are in [1, length-1]
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (!numbers || length <= 1) {
            // Illegale array or no duplication.
            return false;
        }

        int l = 1;
        int u = length - 1;
        while (l <= u) {
            int m = l + ((u - l) >> 1);                    // middle number of l~u
            int cnt = count_range(numbers, length, l, m);  // count numbers in [l, m]
            if (l == u) {
                if (cnt > 1) {
                    if (duplication) {
                        *duplication = l;
                    }
                    return true;
                } else {
                    break;
                }
            }
            if (cnt > (m - l + 1)) {
                // Duplication maybe in [l, m] for the numbers in [l, m] is more than m-l+1.
                u = m;
            } else {
                // Duplication maybe in [m+1, u].
                l = m + 1;
            }
        }

        return false;
    }

private:
    int count_range(int numbers[], int length, int start, int end) {
        int cnt = 0;
        for (int i = 0; i < length; i++) {
            if (numbers[i] >= start && numbers[i] <= end) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    int dup;

    int arr1[] = {1, 4, 3, 2, 3};
    if (s.duplicate(arr1, NELEM(arr1), &dup)) {
        cout << "arr1 dup: " << dup << endl;
    } else {
        cout << "arr1 no dup" << endl;
    }

    int arr2[] = {1, 4, 4, 3, 2, 3};
    if (s.duplicate(arr2, NELEM(arr2), &dup)) {
        cout << "arr2 dup: " << dup << endl;
    } else {
        cout << "arr2 no dup" << endl;
    }

    if (s.duplicate(NULL, 0, &dup)) {
        cout << "arr3 dup: " << dup << endl;
    } else {
        cout << "arr3 no dup" << endl;
    }

    return 0;
}
