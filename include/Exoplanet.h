#pragma once
#include "CelestialObject.h"
#include <string>

class Exoplanet : public CelestialObject
{
private:
    double orbitalDistance; // in AU
    bool habitable;         // true if potentially habitable

public:
    Exoplanet(
        std::string name = "Unknown Exoplanet",
        double mass = 0.0,
        double age = 0.0,
        std::string desc = "N/A",
        double orbitalDistance = 0.0,
        bool habitable = false);

    // Getters
    std::string getName() const { return name; }
    double getOrbitalDistance() const { return orbitalDistance; }
    bool isHabitable() const { return habitable; }

    void displayInfo() const override;
    json toJSON() const override;
};
