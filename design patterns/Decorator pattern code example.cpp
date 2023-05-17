#include<bits/stdc++.h>
#define hell        1000000007
#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl "\n"
using namespace std;

class Beverage{
public:
    virtual string getDesc() = 0;
    virtual int cost() = 0;
};

class Decaf: public Beverage {
public:
    string getDesc() {
        return "Decaf";
    }

    int cost() {
        return 10;
    }
};

class Espresso: public Beverage {
public:
    string getDesc() {
        return "Espresso";
    }

    int cost() {
        return 20;
    }
};

class AddOnDecorator: public Beverage {
public:
    Beverage* b;
    AddOnDecorator(Beverage* b) : b(b) {
        if (b == nullptr) {
            throw runtime_error("Base beverage cannot be null");
        }
    }
};

class CaramelDecorator: public AddOnDecorator {
public:
    CaramelDecorator(Beverage* b) : AddOnDecorator(b) {

    }

    string getDesc() {
        return "Caramel " + b->getDesc();
    }

    int cost() {
        return 5 + b->cost();
    }
};

class SoyDecorator: public AddOnDecorator {
public:
    SoyDecorator(Beverage* b) : AddOnDecorator(b) {

    }

    string getDesc() {
        return "Soy " + b->getDesc();
    }

    int cost() {
        return 30 + b->cost();
    }
};

int main() {
    Beverage* d = new Decaf();
    Beverage* b = new CaramelDecorator(d);
    Beverage* scd = new SoyDecorator(new CaramelDecorator(b));
    cout<<scd->cost()<<endl;
    cout<<scd->getDesc();
    return 0;
}
