#include <iostream>
#include <cstring>

using namespace std;

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
