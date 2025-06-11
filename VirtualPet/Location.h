#ifndef LOCATION_H
#define LOCATION_H
#include "Environment.h"
#include <string>
#include <iostream>
using namespace std;
class Location {
private:
    string name;
    Environment env;
public:
    Location(const string& n, const Environment& e);
    
    void setEnvironment(const Environment& e);
    void changeWeather(const string& w);
    void changeTemperature(int temp);
    string getName() const;
    Environment getEnvironment() const;
    void display() const;
};
#endif