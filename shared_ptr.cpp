#include<bits/stdc++.h>
using namespace std;

class A {
public:
    void show()
    {
        cout << "A::show()" << endl;
    }
};

class shrPtr {
private:
    shrPtr* ptr = nullptr;
    shrPtr* parPtr = nullptr;
    A* data = nullptr;
    int cnt = 0;

public:
    shrPtr(A* a) {
        this->data = a;
        increaseCnt();
    }

    shrPtr(shrPtr& shr) {
        shr.addPar(this);
        this->ptr = &shr;
        increaseCnt();
    }

    ~shrPtr() {
        this->reset();
    }

    A* operator->() {
        return this->get();
    }
    
    void addPar(shrPtr* parPtr) {
        this->parPtr = parPtr;
    }

    void increaseCnt() {
        if (data)
            this->cnt++;
        else
            this->ptr->increaseCnt();
    }

    void decreaseCnt() {
        if (data)
            this->cnt--;
        else if (this->ptr)
            this->ptr->decreaseCnt();
    }

    A* get() {
        if (data) {
            return data;
        } else if (ptr) {
            return ptr->get();
        } else {
            return nullptr;
        }
    }   

    int use_count() {
        if (data) {
            return cnt;
        } else if (ptr) {
            return ptr->use_count();
        } else {
            return 0;
        }
    } 

    void reset() {
        this->decreaseCnt();
        if (parPtr) {
            // transfer ownership to the parent
            if (this->ptr) {
                parPtr->ptr = this->ptr;
            } else if (data) {
                parPtr->data = data;
                parPtr->ptr = nullptr;
            }
            parPtr->cnt = this->cnt;
        }
        if (data && this->use_count() == 0) {
            delete data;
        }
        this->data = nullptr;
        this->ptr = nullptr;
    }
};

int main() {
    ios;
    shrPtr p1(new A);
    cout << p1.get() << endl;
    p1->show();
    shrPtr p2(p1);
    p2->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
  
    // Returns the number of shared_ptr objects
    // referring to the same managed object.
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
  
    // Relinquishes ownership of p1 on the object
    // and pointer becomes NULL
    p1.reset();
    cout << p1.get() << endl;
    cout << p2.use_count() << endl;
    cout << p2.get() << endl;
}

/* 

00xdc1430
A::show()
A::show()
0xdc1430
0xdc1430
2
2
0
1
0xdc1430

*/
