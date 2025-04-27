#ifndef PET_H
#define PET_H
using namespace std;
#include <string>

class Pet {
protected:
    string name;
    int hunger;
    int happiness;

public:
    Pet(const string& name);
    virtual ~Pet() {}

    virtual void eat() = 0;
    virtual void play() = 0;
    virtual void sleep() = 0;
    virtual void showStatus() const;

    string getName() const;
};

#endif
