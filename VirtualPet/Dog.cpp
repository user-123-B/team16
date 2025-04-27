#include "Dog.h"
#include <iostream>

Dog::Dog(const string name) : Pet(name) ,eatCount{0}{}

void Dog::eat() {
    hunger -= 8;
    cout << getName() << " 吃了狗飼料，飢餓值下降。"<<endl;
    eatCount++;
    if (eatCount >= 3) {
        eatCount = 0;
        hunger+=4;
        happiness += 8;
        if (happiness > 100) happiness = 100;
        cout << getName() << " 吃太多了，拉屎了💩！快樂值上升。"<<endl;
    }
}

void Dog::play() {
    happiness += 10;
    hunger += 5;
    if(happiness>100){happiness=100;}
    if(hunger>100){hunger=100;}
    cout << getName() << " 玩了接球遊戲，快樂值上升，飢餓值上升。"<<endl;;
}

void Dog::sleep() {
    happiness += 5;
    if(happiness>100){happiness=100;}
    cout << getName() << " 睡了一覺，恢復精神。"<<endl;
}
