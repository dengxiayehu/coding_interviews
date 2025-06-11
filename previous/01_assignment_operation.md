# 赋值运算符函数

考察C++的基础知识，尤其注意以下几点：
1. 函数需返回自身的引用，这样才可以进行连续赋值，语意上也和基础类型类似。
2. 函数要处理自己给自己赋值的情况，避免一些出乎意料的场景，例如成员指针指向的内容其实已经被释放了
3. **函数要满足异常安全性**，当需要分配空间失败时，原来的CMyString对象要保持不变
4. 传入的参数应该为常量引用，可以有两个好处：1-参数传递无需构造临时对象，2-参数在函数内不会更改
5. 拷贝构造函数中也需要初始化数据成员

``` cpp
#include <iostream>
#include <cstring>

using namespace  std;

class CMyString {
public:
    CMyString(const char *pData = NULL);
    CMyString(const CMyString& other);
    ~CMyString();
    CMyString& operator=(const CMyString& other);

private:
    char *m_pData;
};

CMyString::CMyString(const char *pData)
    : m_pData(NULL)
{
    if (pData) {
        // If pData is not NULL, dup the string.
        int len = strlen(pData);
        char *tmp = new char[len+1];
        strcpy(tmp, pData);
        m_pData = tmp;
    }
}

// 注意拷贝构造函数的书写。
CMyString::CMyString(const CMyString& other)
    : m_pData(NULL) // 需要将成员m_pData设置为NULL
{
    if (this == &other) {
        // Self cp constructor check.
        return;
    }

    if (other.m_pData) {
        int len = strlen(other.m_pData);
        char *tmp = new char[len+1];
        strcpy(tmp, other.m_pData);
        m_pData = tmp;
    }
}

CMyString& CMyString::operator=(const CMyString& other)
{
    if (this != &other) {
        CMyString str_temp(other); // 利用拷贝构造函数来创建str_temp对象

        // Swap and auto release.
        char* tmp = m_pData;
        str_temp.m_pData = m_pData;
        m_pData = tmp;
    }

    return *this;
}

CMyString::~CMyString()
{
    // 在析构函数中释放分配的内存空间。
    if (m_pData) {
        delete [] m_pData;
        m_pData = NULL;
    }
}

int main(int argc, char const *argv[])
{
    CMyString mystr("Hello");
    CMyString mystr2;
    CMyString mystr3;

    mystr2 = mystr = mystr3;

    return 0;
}
```
