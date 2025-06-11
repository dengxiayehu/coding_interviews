#include <iostream>
#include <vector>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) {
            return false;
        }

        return verify_sequence_of_bst_core(sequence, 0, sequence.size() - 1);
    }

private:
    bool static verify_sequence_of_bst_core(vector<int>& sequence, int start, int end) {
        if (start >= end) {
            return true;
        }
        int i;
        int j;
        int root = sequence[end];
        for (i = start; i < end; i++) {
            if (sequence[i] > root) {
                break;
            }
        }
        if (i == end) {
            return true;
        }
        for (j = i + 1; j < end; j++) {
            if (sequence[j] < root) {
                return false;
            }
        }

        return verify_sequence_of_bst_core(sequence, start, i) && verify_sequence_of_bst_core(sequence, i + 1, end - 1);
    }
};

int main(int argc, char* argv[]) {
    {
        int arr[] = {5, 7, 6, 9, 11, 10};
        cout << Solution().VerifySquenceOfBST(vector<int>(arr, arr + NELEM(arr))) << endl;
    }

    {
        int arr[] = {7, 4, 6, 5};
        cout << Solution().VerifySquenceOfBST(vector<int>(arr, arr + NELEM(arr))) << endl;
    }

    {
        int arr[] = {1, 2, 3, 4};
        cout << Solution().VerifySquenceOfBST(vector<int>(arr, arr + NELEM(arr))) << endl;
    }

    {
        int arr[] = {4, 3, 2, 1};
        cout << Solution().VerifySquenceOfBST(vector<int>(arr, arr + NELEM(arr))) << endl;
    }

    return 0;
}