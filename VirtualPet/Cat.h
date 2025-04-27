#ifndef CAT_H
#define CAT_H
using namespace std;
#include "Pet.h"

class Cat : public Pet {
    private:
    int eatCount;
public:
    Cat(const string name);
    void eat() override;
    void play() override;
    void sleep() override;
};

#endif
