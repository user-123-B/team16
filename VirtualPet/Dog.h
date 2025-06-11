#ifndef DOG_H
#define DOG_H
#include "Pet.h"
using namespace std;
class Dog : public Pet {
private:
    int eatCount, playCount, trainCount, sleepCount;
public:
    Dog(const string& name, const string& breed, const string& color);
    void eat() override;
    void play() override;
    void train() override;
    void sleep() override;
    void reactToEnvironment() override;
};
#endif

