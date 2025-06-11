#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <string>
#include <iostream>
using namespace std;
class Environment {
private:
    string weather;
    int temperature;
public:
    Environment(const string& w = "晴天", int temp = 25);
    
    void setWeather(const string& w);
    void setTemperature(int temp);
    string getWeather() const;
    int getTemperature() const;
    void display() const;
};
#endif
