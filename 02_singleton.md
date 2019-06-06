# 单例模式

考察C++中的设计模式，这个单例模式的考察代码不多，但能说明不少问题。我们准备采用如下的方案执行：

1. 单例模式采用懒汉式，即用到的时候才会真正去创建这个单例
2. 适用于多线程的场景，所以需要加锁。但要注意效率，避免每次获得单例的时候都要加锁解锁
3. 单例模式产生的对象要能够被自动回收
4. 单例模式的析构函数一般是声明为public的，不然若是声明为private属性的话，那么对象是无法在栈上生成的，同时若是用new的方式生成的对象，也是无法进行delete调用的（可以通过提供一个成员函数，在其中调用delete）。

``` cpp
#include <iostream>
#include <pthread.h>

using namespace std;

class Singleton {
public:
    ~Singleton() {
        cout << "Singleton destructor" << endl;
    }

    // 懒汉式生成单例对象。
    static Singleton *GetInstance() {
        if (!instance) {
            pthread_mutex_lock(&mutex);
            instance = new Singleton;
            pthread_mutex_unlock(&mutex);
        }
        return instance;
    }

private:
    Singleton() {
        cout << "Singleton constructor" << endl;
    }

    // 内部回收器，用来在程序结束时自动释放单例对象。
    class GC {
    public:
        ~GC() {
            if (instance != NULL) {
                cout << "delete instance" << endl;
                delete instance; // 释放单例对象，注意无需加[]，因为不是数组类型
                instance = NULL;
            }
        }
    };

    static Singleton *instance;
    static pthread_mutex_t mutex;
    static GC gc;
};

Singleton *Singleton::instance = NULL;
pthread_mutex_t Singleton::mutex = PTHREAD_MUTEX_INITIALIZER;
Singleton::GC Singleton::gc;

int main(int argc, char const *argv[])
{
    Singleton::GetInstance();

    return 0;
}
```

> 输出结果：  
Singleton constructor  
delete instance  
Singleton destructor  