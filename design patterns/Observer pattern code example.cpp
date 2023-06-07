#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

class IObserver {
public: 
    virtual void update(int state) = 0;
    virtual ~IObserver() {};
};

class IObservable {
public:
    virtual void addObserver(IObserver* observer) = 0;
    virtual void removeObserver(IObserver* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~IObservable() {};
};

class Subject : public IObservable {
int state = 10;
public:
    void addObserver(IObserver* observer) {
        observers.insert(observer);
    }

    void removeObserver(IObserver* observer) {
        observers.erase(observer);
    }

    void notifyObservers() {
        for (const auto& observer: observers) {
            observer->update(state);
        }
    }

    void changeState(int newState) {
        state = newState;
        notifyObservers();
    }

private:
    set<IObserver*> observers;
};

class Observer1 : public IObserver {
    void update(int state) {
        cout<<" Update called obs1, state: "<<state<<endl;
    }
};

class Observer2 : public IObserver {
    void update(int state) {
        cout<<" Update called obs2, state: "<<state<<endl;
    }
};

int main() {
    Subject s;
    Observer1 ob1;
    Observer2 ob2;

    s.addObserver(&ob1);
    s.addObserver(&ob2);

    s.changeState(20);
    return 0;
}
