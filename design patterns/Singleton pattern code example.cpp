#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() {

    }

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void printHello() {
        cout<<"hello, I am a Singleton obj with address:"<<(this)<<endl;
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    // Client

    Singleton* singletonObj = Singleton::getInstance();
    singletonObj->printHello();


    Singleton* singletonObj2 = Singleton::getInstance();
    singletonObj2->printHello();
    return 0;
}
