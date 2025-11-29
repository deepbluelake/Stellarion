#pragma once
#include "CelestialObject.h"
#include <string>

class Star : public CelestialObject
{
private:
    double temperature;       // Kelvin
    double luminosity;        // relative to Sun (1 L☉)
    std::string spectralType; // e.g., G2V, M1, B0

public:
    Star(
        const std::string &name,
        double mass,
        double age,
        const std::string &desc,
        double temperature,
        double luminosity,
        const std::string &spectralType);

    void displayInfo() const override;
    json toJSON() const override;
};
