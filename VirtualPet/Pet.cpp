#include "Pet.h"
#include <iostream>

Pet::Pet(const string& name) : name(name), hunger(50), happiness(50) {}

void Pet::showStatus() const {
    cout << name << " 狀態："<<endl;
    cout << "飢餓值：" << hunger << endl;
    cout << "快樂值：" << happiness << endl;
}

string Pet::getName() const {
    return name;
}
