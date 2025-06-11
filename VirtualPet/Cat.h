#ifndef CAT_H
#define CAT_H
#include "Pet.h"
using namespace std;
class Cat : public Pet {
private:
    int eatCount, playCount, trainCount, sleepCount;
public:
    Cat(const string& name, const string& breed, const string& color);
    void eat() override;
    void play() override;
    void train() override;
    void sleep() override;
    void reactToEnvironment() override;
};
#endif


