#include "Environment.h"
#include <iostream>
Environment::Environment(const string& w, int temp) : weather(w), temperature(temp) {}

void Environment::setWeather(const string& w) {
    weather = w;
}
void Environment::setTemperature(int temp) {
    temperature = temp;
}
string Environment::getWeather() const {
    return weather;
}
int Environment::getTemperature() const {
    return temperature;
}
void Environment::display() const {
    cout << "天氣: " << weather 
              << " | 溫度: " << temperature << "°C" << endl;
}