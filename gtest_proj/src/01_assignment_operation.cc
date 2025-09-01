#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string.h>

#include "./matchers.h"

// 实现一个异常安全的赋值运算符。
class CMyString {
public:
    explicit CMyString(const char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString();
    CMyString& operator=(const CMyString& str);
    const char* c_str() const;

private:
    const char* m_pData;
};

CMyString::CMyString(const char* pData) : m_pData(nullptr) {
    if (pData == nullptr) {
        return;
    }
    size_t len = strlen(pData);
    char* tmp = new char[len + 1];
    // strncpy：
    // 从 pData 中拷贝前 n 个字符到 tmp 中
    // 若 pData 的长度小于 n，则少的部分用 '\0' 补齐；
    // 若 pData 的长度大于 n，则只会从 pData 中拷贝 n 个字符到 tmp 中；
    // tmp 中的 '\0' 需手动设置
    // 在这个示例中 tmp 的长度是根据 pData 来的，所以使用 strcpy 也没啥问题
    strncpy(tmp, pData, len);
    tmp[len] = '\0';
    m_pData = tmp;
}

CMyString::CMyString(const CMyString& str) : CMyString(str.m_pData) {
}

CMyString::~CMyString() {
    if (m_pData != nullptr) {
        delete[] m_pData;
        m_pData = nullptr;
    }
}

CMyString& CMyString::operator=(const CMyString& str) {
    // 检查自赋值场景
    if (this == &str) {
        return *this;
    }
    // 构造一个临时对象，若里面出现了异常则当前对象不受影响
    CMyString tmp(str);
    // 将临时对象“替换”当前对象
    const char* p = m_pData;
    m_pData = tmp.m_pData;
    tmp.m_pData = p;
    return *this;
}

const char* CMyString::c_str() const {
    return m_pData;
}

TEST(ut_01, CMyString) {
    CMyString str("hello");
    CMyString dst;
    dst = str;
    EXPECT_STREQ(dst.c_str(), str.c_str());

    str = str;
    EXPECT_STREQ(str.c_str(), dst.c_str());

    CMyString str1, str2;
    str2 = str1 = str;
    EXPECT_STREQ(str1.c_str(), str.c_str());
    EXPECT_STREQ(str2.c_str(), str.c_str());

    CMyString str_null;
    CMyString str3;
    str3 = str_null;
    EXPECT_THAT(str3.c_str(), IsNull());

    CMyString str_empty("");
    CMyString str4;
    str4 = str_empty;
    EXPECT_THAT(str4.c_str(), IsEmpty());

    // 注意：下面语句其实会调用拷贝构造函数，而不是赋值函数
    CMyString str5 = str;
    EXPECT_STREQ(str5.c_str(), str.c_str());
}
