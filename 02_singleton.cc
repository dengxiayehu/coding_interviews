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
