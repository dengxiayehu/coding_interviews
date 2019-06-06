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
