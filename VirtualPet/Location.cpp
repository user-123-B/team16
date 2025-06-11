#include "Location.h"
#include <iostream>
Location::Location(const string& n, const Environment& e): name(n), env(e) {}
// n為地點名稱，e為環境物件
// 這個建構函數初始化地點名稱和環境物件
void Location::setEnvironment(const Environment& e) {
    env = e;
}
void Location::changeWeather(const string& w) {
    env.setWeather(w);
}
void Location::changeTemperature(int temp) {
    env.setTemperature(temp);
}
string Location::getName() const {
    return name;
}
Environment Location::getEnvironment() const {
    return env;
}
void Location::display() const {
    cout << "地點: " << name << " | ";
    env.display();
}