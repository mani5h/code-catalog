#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

class IAsteroid {
public:
    virtual void printShape() = 0;

    virtual ~IAsteroid() {};
};

class SphericalAsteroid: public IAsteroid {
    void printShape() {
        cout<<"I am a spherical Asteroid"<<endl;
    }
};

class CubicalAsteroid: public IAsteroid {
    void printShape() {
        cout<<"I am a cubical Asteroid"<<endl;
    }
};

class IAsteroidFactory {
public:
    virtual unique_ptr<IAsteroid> createAsteroid() = 0;
    virtual ~IAsteroidFactory() {};
};

class RandomAsteroidFactory: public IAsteroidFactory {
public:
    RandomAsteroidFactory() {
        srand(time(0));
    }

    unique_ptr<IAsteroid> createAsteroid() {
        int type = rand() % 2;
        if (type == 0) {
            return make_unique<SphericalAsteroid>();
        } else {
            return make_unique<CubicalAsteroid>();
        }
    }
};

class BalancedAsteroidFactory: public IAsteroidFactory {
    int sphericalAsteroidCount = 0;
    int cubicalAsteroidCount = 0;
public:    
    unique_ptr<IAsteroid> createAsteroid() {
        if (sphericalAsteroidCount <= cubicalAsteroidCount) {
            sphericalAsteroidCount++;
            return make_unique<SphericalAsteroid>();
        } else {
            cubicalAsteroidCount++;
            return make_unique<CubicalAsteroid>();
        }
    }
};


vector<unique_ptr<IAsteroid>> createAsteroids(const unique_ptr<IAsteroidFactory>& asteroidFactory, int count) {
    vector<unique_ptr<IAsteroid>> asteroids;
    
    cout<<"Creating "<<count<<" asteroids"<<endl;
    for (int i = 0; i < count; i++) {
        unique_ptr<IAsteroid> asteroid = asteroidFactory->createAsteroid();
        asteroid->printShape();
        asteroids.emplace_back(std::move(asteroid));
    }

    return asteroids;
}

int main() {
    unique_ptr<IAsteroidFactory> asteroidFactory1 = std::make_unique<BalancedAsteroidFactory>();
    unique_ptr<IAsteroidFactory> asteroidFactory2 = std::make_unique<RandomAsteroidFactory>();

    createAsteroids(asteroidFactory1, 10);
    createAsteroids(asteroidFactory2, 10);

    return 0;
}
