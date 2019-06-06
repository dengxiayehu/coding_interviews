# 翻转单词顺序列

> 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

``` cpp
#include <iostream>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        int len = str.length();
        if (len <= 1) {
            return str;
        }
        reverse_string(str, 0, len-1);
        int begin = -1;
        int end = -1;
        for (int i = 0; i < len; i++) {
            while (str[i] && (str[i] == ' ' || str[i] == '\t')) {
                i++;
            }
            if (!str[i]) {
                return str;
            }
            begin = i;
            while (str[i] && (str[i] != ' ' && str[i] != '\t')) {
                i++;
            }
            end = i-1;
            reverse_string(str, begin, end);
        }
        return str;
    }

private:
    static void reverse_string(string& str, int begin, int end) {
        while (begin < end) {
            char tmp = str[begin];
            str[begin] = str[end];
            str[end] = tmp;
            begin++;
            end--;
        }
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().ReverseSentence("I am a student.") << endl;
    return 0;
}
```

输出结果：

```txt
student. a am I
```
