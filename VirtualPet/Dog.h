#ifndef DOG_H
#define DOG_H

#include "Pet.h"
using namespace std;
class Dog : public Pet {
    private:
        int eatCount;
public:
    
    Dog(const string name);
    void eat() override;
    void play() override;
    void sleep() override;
};

#endif

