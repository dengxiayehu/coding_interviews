#include <gtest/gtest.h>

#include <iostream>

// 单例工具类
template <typename T>
class ISingleton {
public:
    static T& GetInstance() {
        static T instance;
        return instance;
    }
};

// 基类，只能通过子类来实例化
class President {
protected:
    President() {
        std::cout << "President ctor" << std::endl;
    }
    virtual ~President() {
        std::cout << "President dtor" << std::endl;
    }

public:
    President(const President&) = delete;
    President& operator=(const President&) = delete;

    virtual void foo() const {
        std::cout << "President is making a speech. (" << this << ")" << std::endl;
    }
};

// 子类构造函数为私有
// 添加工具类为友元用来构造子类对象
class FrenchPresident : public President {
    friend class ISingleton<FrenchPresident>;

private:
    FrenchPresident() {
        std::cout << "FrenchPresident ctor" << std::endl;
    }

public:
    virtual ~FrenchPresident() {
        std::cout << "FrenchPresident dtor" << std::endl;
    }

    virtual void foo() const {
        std::cout << "FrenchPresident is making a speech. (" << this << ")" << std::endl;
    }
};

class AmericanPresident : public President {
    friend class ISingleton<AmericanPresident>;

private:
    AmericanPresident() {
        std::cout << "AmericanPresident ctor" << std::endl;
    }

public:
    virtual ~AmericanPresident() {
        std::cout << "AmericanPresident dtor" << std::endl;
    }

    virtual void foo() const {
        std::cout << "AmericanPresident is making a speech. (" << this << ")" << std::endl;
    }
};

TEST(ut_02, President) {
    President& p = ISingleton<FrenchPresident>::GetInstance();
    p.foo();
    President& p1 = ISingleton<FrenchPresident>::GetInstance();
    p1.foo();
    EXPECT_TRUE(&p == &p1);

    President& p2 = ISingleton<AmericanPresident>::GetInstance();
    p2.foo();
}
