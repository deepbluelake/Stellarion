#pragma once
#include "CelestialObject.h"
#include <string>

class BlackHole : public CelestialObject
{
private:
    double eventHorizonRadius; // km
    double spin;               // dimensionless 0–1

public:
    BlackHole(
        std::string name = "Unknown Black Hole",
        double mass = 0.0,
        double age = 0.0,
        std::string desc = "N/A",
        double eventHorizonRadius = 0.0,
        double spin = 0.0);

    // Getters
    std::string getName() const { return name; }
    double getEventHorizonRadius() const { return eventHorizonRadius; }
    double getSpin() const { return spin; }

    void displayInfo() const override;
    json toJSON() const override;
};
