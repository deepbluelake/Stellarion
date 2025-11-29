#pragma once
#include "CelestialObject.h"
#include <string>

class Galaxy : public CelestialObject
{
private:
    std::string galaxyType; // e.g., Spiral, Elliptical, Irregular
    int starCount;          // estimated number of stars

public:
    Galaxy(
        const std::string &name,
        double mass,
        double age,
        const std::string &desc,
        const std::string &type,
        int starCount);

    void displayInfo() const override;
    json toJSON() const override;
};
