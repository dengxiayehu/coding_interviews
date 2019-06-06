# 旋转数组的最小数字

> 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

这道题也需要非常小心，需要使用pre和post两个索引分别指向前半块递增序列和后半块递增序列。当pre+1==post时，最小的数字就是post所指向的数字。

``` cpp
#include <iostream>
#include <vector>

using namespace std;

#define NELEM(arr) (sizeof(arr)/sizeof(arr[0]))

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) {
            return 0;
        }

        int *arr = &rotateArray[0];
        const int n = rotateArray.size();
        if (n == 1) {
            // 特殊出来只有一个元素的情况。
            return arr[0];
        }
        if (n == 2) {
            // 特殊处理只有两个元素的情况。
            return arr[0] < arr[1] ? arr[0] : arr[1];
        }
        int pre = 0;
        int post = n-1;
        while (pre+1 < post) { // 前后区域的两个指针还未相邻
            int m = pre+((post-pre)>>1);
            if (arr[pre] == arr[m] && arr[m] == arr[post]) { // 特殊情况：arr[pre] == arr[m] == arr[post]
                int min = arr[pre];
                for (int i = pre+1; i <= post; i++) {
                    if (arr[i] < min) {
                        min = arr[i];
                    }
                }
                return min;
            } else {
                if (arr[pre] >= arr[m]) { // 数组右区域可能有序
                    if (arr[m] >= arr[post]) { // 数组arr[pre .. post]区域是一个递减序列，则最小元素就是arr[post]
                        return arr[post];
                    } else {
                        post = m;
                    }
                } else { // 数组左区域可能有序
                    if (arr[m] <= arr[post]) { // 数组arr[pre .. post]区域是一个递增序列，则最小元素就是arr[pre]
                        return arr[pre];
                    } else {
                        pre = m;
                    }
                }
            }
        }

        return arr[post];
    }
};

int main(int argc, char const *argv[])
{
    int arr1[] = { 3, 4, 5, 1, 2 };
    vector<int> v1(arr1, arr1+NELEM(arr1));
    cout << Solution().minNumberInRotateArray(v1) << endl;

    int arr2[] = { 1, 2, 3, 4, 5 };
    vector<int> v2(arr2, arr2+NELEM(arr2));
    cout << Solution().minNumberInRotateArray(v2) << endl;

    int arr3[] = { 5, 4, 3, 2, 1 };
    vector<int> v3(arr3, arr3+NELEM(arr3));
    cout << Solution().minNumberInRotateArray(v3) << endl;

    int arr4[] = { 1, 0, 1, 1, 1 };
    vector<int> v4(arr4, arr4+NELEM(arr4));
    cout << Solution().minNumberInRotateArray(v4) << endl;

    int arr5[] = { 1, 1, 1, 0, 1 };
    vector<int> v5(arr5, arr5+NELEM(arr5));
    cout << Solution().minNumberInRotateArray(v5) << endl;

    int arr6[] = { 2, 1 };
    vector<int> v6(arr6, arr6+NELEM(arr6));
    cout << Solution().minNumberInRotateArray(v6) << endl;

    int arr7[] = { 3, 2, 1 };
    vector<int> v7(arr7, arr7+NELEM(arr7));
    cout << Solution().minNumberInRotateArray(v7) << endl;

    return 0;
}
```

> 输出结果：  
1  
1  
1  
0  
0  
1  
1

这道题一把成功，赞。