#include "Cat.h"
#include <iostream>
Cat::Cat(const string& name, const string& breed, const string& color) : Pet(name, breed, color),
    eatCount(0), playCount(0), trainCount(0), sleepCount(0) {}

void Cat::eat() {
    if (eatCount >= eatLimit) {
        cout << getName() << " 看著你：『你以為我還會吃嗎？我才不胖呢。』\n";
        return;
    }
    if(sleepCount>= sleepLimit) {
        sleepCount = 0; // 如果達睡覺次數上限 則按下eat會重製sleepcount
    }
    hunger -= 8;
    if (hunger < 0) hunger = 0;
    eatCount++;
    cout << getName() << " 吃了鮪魚罐頭真爽，飢餓值下降。\n";
    increaseBond(4);
    if (eatCount == eatLimit)
        cout << getName() << " 吃太多了想吐了，打了個飽嗝：『喵～我超愛你 ??』\n";
}

void Cat::play() {
    if (playCount >= playLimit) {
        cout << getName() << " 對毛線球失去興趣，斜眼看你。\n";
        return;
    }
    if(sleepCount>= sleepLimit) {
        sleepCount = 0; // 如果達睡覺次數上限 則按下play會重製sleepcount
    }
    happiness += 10;//快樂值
    hunger += 4;//飢餓值
    if (hunger > 100) hunger = 100;// 確保飢餓值不超過100
    if (happiness > 100) happiness = 100;// 確保快樂值不超過100
    playCount++;
    cout << getName() << " 跟你玩了毛線球，喵喵叫得很開心！\n";
    increaseBond(6);
}

void Cat::train() {
    if (trainCount >= trainLimit) {
        cout << getName() << " 睜大眼睛：『誰想學握手？我是貓欸！』\n";
        return;
    }
    if(sleepCount>= sleepLimit) {
        sleepCount = 0; // 如果達睡覺次數上限 則按下train會重製sleepcount
    }
    trainCount++;
    cout << getName() << " 才不想聽指令，但你硬是教牠握手...\n";
    happiness += 2;
    increaseBond(7);
}

void Cat::sleep() {
    if (sleepCount >= sleepLimit) {
        cout << getName() << " 在窗邊曬太陽，不想再睡了。\n";
        return;
    }
    sleepCount++;
    trainCount = 0; // 睡覺後訓練次數歸零
    eatCount = 0; // 睡覺後吃飯次數歸零
    playCount = 0; // 睡覺後玩耍次數歸零
    happiness += 5;
    if (happiness > 100) happiness = 100;
    cout << getName() << " 蜷縮成一團毛球熟睡，好舒服。\n";
    increaseBond(5);
}
void Cat::reactToEnvironment() {
    if (getLocation() == nullptr) return;
    
    string weather = getLocation()->getEnvironment().getWeather();
    int temp = getLocation()->getEnvironment().getTemperature();
    
    if (weather == "雨天") {
        cout << getName() << " 討厭雨天，躲到沙發底下了\n";
        happiness -= 10;
    }
    else if (temp > 30) {
        cout << getName() << " 找陰涼處躺下，太熱了不想動\n";
        happiness -= 5;
    }
}