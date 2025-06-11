#include <iostream>
#include <stack>
#include <vector>

#include "macro_util.h"

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.empty() && popV.empty()) {
            return true;
        }

        stack<int> s;
        int iin = 0;
        int iout = 0;
        int target;
        while (iout < popV.size()) {
            target = popV[iout];                   // 当前需要弹出的数字
            if (s.empty() || s.top() != target) {  // 栈为空或者栈顶元素不是我们想要的
                // 从输入序列中压入更多的数字，直到栈顶元素为目标数字
                while (iin < pushV.size() && pushV[iin] != target) {
                    s.push(pushV[iin]);
                    iin++;
                }
                if (iin >= pushV.size()) {
                    // 没有找到目标数字
                    return false;
                }
                iin++;  // 从输入序列中取出target数字
            } else {
                s.pop();
            }
            iout++;
        }

        return iout == popV.size();
    }
};

int main(int argc, char* argv[]) {
    // 4,5,3,2,1 ok
    // 4,3,5,1,2 bad
    int arr_push[] = {1, 2, 3, 4, 5};
    // int arr_pop[] = { 4, 5, 3, 2, 1 };
    int arr_pop[] = {4, 3, 5, 1, 2};
    cout << Solution().IsPopOrder(vector<int>(arr_push, arr_push + NELEM(arr_push)),
                                  vector<int>(arr_pop, arr_pop + NELEM(arr_pop)));
    return 0;
}