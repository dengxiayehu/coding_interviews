#include "./test_helper.h"

class Singleton {
public:
    ~Singleton() {
    }

    static Singleton* GetInstance() {
        if (instance != nullptr) {
            return instance;
        }
        {
            const std::lock_guard<std::mutex> lock(mu);
            if (instance == nullptr) {
                instance = new Singleton;
            }
        }
        return instance;
    }

    // 单例模式拷贝构造和赋值函数使用 = delete 可以阻止编译器生成的默认版本，阻止下面两种情况：
    // Singleton s = *Singleton::GetInstance();
    // *s = *Singleton::GetInstance();
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton() {
    }

    class GC {
    public:
        ~GC() {
            const std::lock_guard<std::mutex> lock(mu);
            if (instance != nullptr) {
                delete instance;
                instance = nullptr;
            }
        }
    };

private:
    static std::mutex mu;
    static Singleton* instance;
    static GC gc;
};

// 类静态成员要在类体外定义
std::mutex Singleton::mu;
Singleton* Singleton::instance = nullptr;
Singleton::GC Singleton::gc;

TEST(ut_02, Singleton) {
    Singleton* instance = Singleton::GetInstance();
    EXPECT_THAT(instance, NotNull());
}
