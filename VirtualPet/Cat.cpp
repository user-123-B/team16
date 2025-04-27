#include "Cat.h"
#include <iostream>
Cat::Cat(const string name) : Pet(name), eatCount(0) {}



void Cat::eat() {
    hunger -= 8;
    if(hunger<0){hunger=0;};
    cout << getName() << " 吃了貓罐頭，飢餓值下降。\n";
    eatCount++;
    if (eatCount >= 3) {
        eatCount = 0;
        hunger+=4;
        happiness += 8;
        if (happiness > 100) happiness = 100;
        cout << getName() << " 吃太多了，拉屎了💩！快樂值上升。\n";
    }
}


void Cat::play() {
    happiness += 8;
    hunger += 4;
    if(hunger>100){
        hunger=100;
    }
    if(happiness>100){
        happiness=100;
    }
    cout << getName() << " 玩了毛線球，快樂值上升，飢餓值上升。\n";
}

void Cat::sleep() {
    happiness += 4;
    if(happiness>100){
        happiness=100;
    }
    cout << getName() << " 躺在窗邊睡覺，好舒服。\n";
}
