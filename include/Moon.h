#pragma once
#include "CelestialObject.h"
#include <string>

class Moon : public CelestialObject
{
private:
    double orbitalDistance;   // distance from parent planet in km
    std::string parentPlanet; // the planet it orbits

public:
    Moon(
        const std::string &name,
        double mass,
        double age,
        const std::string &desc,
        double orbitalDistance,
        const std::string &parentPlanet);

    void displayInfo() const override;
    json toJSON() const override;
};
