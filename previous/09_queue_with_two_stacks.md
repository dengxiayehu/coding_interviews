# 用两个栈实现队列

> 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

``` cpp
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                int v = stack1.top();
                stack1.pop();
                stack2.push(v);
            }
        }
        if (stack2.empty()) {
            return -1;
        }
        int v = stack2.top();
        stack2.pop();
        return v;
    }

private:
    stack<int> stack1; // in
    stack<int> stack2; // out
};

int main(int argc, char const *argv[])
{
    Solution s;

    s.push(1);
    cout << s.pop() << endl;
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    return 0;
}
```

> 输出结果：  
1  
2  
3

这道题比较简单，掌握思想就可以写出代码。但这个pop()函数设计得不太合理，无法区分非法情况还是正常栈元素为-1的情况。