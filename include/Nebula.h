#pragma once
#include "CelestialObject.h"
#include <iostream>
using namespace std;

class Nebula : public CelestialObject
{
private:
    string nebulaType;
    double size;

public:
    Nebula(
        string name = "Unknown Nebula",
        double mass = 0.0,
        double age = 0.0,
        string desc = "N/A",
        string nebulaType = "Unknown",
        double size = 0.0);

    // Getters
    string getName() const { return name; }
    string getNebulaType() const { return nebulaType; }
    double getSize() const { return size; }

    // Override
    void displayInfo() const override;
    json toJSON() const override;
};
