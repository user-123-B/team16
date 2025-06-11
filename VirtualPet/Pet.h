#ifndef PET_H
#define PET_H
#include <string>
#include "Location.h"
using namespace std;
class Pet {
protected:
    string name;
    string breed;  // 品種
    string color;  // 顏色
    int hunger;
    int happiness;
    int bondLevel; // 情感連結
    int eatLimit;
    int playLimit;
    int trainLimit;
    int sleepLimit;
    Location* currentLocation;//此指標指向家或是公園
    
public:
    Pet(const string& name, const string& breed, const string& color);
    virtual ~Pet() {}

    virtual void eat() = 0;
    virtual void play() = 0;
    virtual void train() = 0;
    virtual void sleep() = 0;
    virtual void reactToEnvironment() = 0;
    virtual void showStatus() const;
    string getName() const;
    void setLocation(Location* location);
    Location* getLocation() const;
    void increaseBond(int amount);
};
#endif

