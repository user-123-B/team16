#include "Dog.h"
#include <iostream>
Dog::Dog(const string& name, const string& breed, const string& color) : Pet(name, breed, color),
    eatCount(0), playCount(0), trainCount(0), sleepCount(0) {}

void Dog::eat() {
    if (eatCount >= eatLimit) {
        cout << getName() << " 旺旺，可能吃太飽了，想拉屎了。\n";
        return;
    }
    if(sleepCount>= sleepLimit) {
        sleepCount = 0; // 如果達睡覺次數上限 則按下eat會重製sleepcount
    }
    hunger -= 10;
    if (hunger < 0) hunger = 0;
    eatCount++;
    cout << getName() << " 狂吃 A5牛排 啃骨頭，好餓啊！\n";
    increaseBond(2);
    if (eatCount == eatLimit)
        cout << getName() << " 撲過來舔你臉：『汪！你最棒！』\n";
}
void Dog::play() {
    if (playCount >= playLimit) {
        cout << getName() << " 累了，躺在地上喘氣...\n";
        return;
    }
    if(sleepCount>= sleepLimit) {
        sleepCount = 0; // 如果達睡覺次數上限 則按下play會重製sleepcount
    }
    happiness += 12;
    hunger += 5;
    if (hunger > 100) hunger = 100;
    if (happiness > 100) happiness = 100;
    playCount++;
    cout << getName() << " 玩了丟球遊戲，開心得不得了！\n";
    increaseBond(6);
}
void Dog::train() {
    if (trainCount >= trainLimit) {
        cout << getName() << " 旺旺，不太想再訓練了...\n";
        return;
    }
    if(sleepCount>= sleepLimit) {
        sleepCount = 0; // 如果達睡覺次數上限 則按下train會重製sleepcount
    }
    trainCount++;
    happiness += 5;
    increaseBond(8);
    cout << getName() << " 接飛盤，好聰明！\n";
}
void Dog::sleep() {
    if (sleepCount >= sleepLimit) {
        cout << getName() << " 已經睡飽，吐舌頭。\n";
        return;
    }
    sleepCount++;
    trainCount = 0; // 睡覺後訓練次數歸零
    eatCount = 0; // 睡覺後吃飯次數歸零
    playCount = 0; // 睡覺後玩耍次數歸零
    happiness += 4;
    if (happiness > 100) happiness = 100;
    cout << getName() << " 安穩地睡覺做美夢。\n";
    increaseBond(5);
}
void Dog::reactToEnvironment() {
    if (getLocation() == nullptr) return;
    
    string weather = getLocation()->getEnvironment().getWeather();
    int temp = getLocation()->getEnvironment().getTemperature();
    
    if (weather == "晴天") {
        cout << getName() << " 喜歡晴天，開心地搖尾巴\n";
        happiness += 10;
    }
    else if (temp < 15) {
        cout << getName() << " 覺得冷，縮成一團發抖\n";
        happiness -= 8;
    }
}