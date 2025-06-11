#include "Pet.h"
#include <iostream>
Pet::Pet(const string& name, const string& breed, const string& color)
    : name(name),breed(breed), color(color), hunger(50), happiness(50), bondLevel(0),
      eatLimit(3), playLimit(3), trainLimit(2), sleepLimit(2) ,currentLocation(nullptr){}
      //eatLimit(3), playLimit(3), trainLimit(2), sleepLimit(2)為互動之極限值

void Pet::showStatus() const {
    cout << name << " 狀態：" << endl;
    cout << "名字：" << name << endl;
    cout << "品種：" << breed << endl;
    cout << "顏色：" << color << endl;
    cout << "飢餓值：" << hunger << endl;
    cout << "快樂值：" << happiness << endl;
    cout << "情感連結：" << bondLevel << "/100" << endl;
}

string Pet::getName() const {
    return name;
}
void Pet::setLocation(Location* location) {
    currentLocation = location;
}

Location* Pet::getLocation() const {//取得現在之位置之function
    return currentLocation;
}
void Pet::increaseBond(int amount) {//情感連結之function
    bondLevel += amount;
    if (bondLevel > 100) bondLevel = 100;
}