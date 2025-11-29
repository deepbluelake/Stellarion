#pragma once
#include "CelestialObject.h"
#include <string>

class Planet : public CelestialObject
{
private:
    int moonCount;
    double orbitalDistance; // in million km
    bool hasLife;

public:
    Planet(
        const std::string &name,
        double mass,
        double age,
        const std::string &desc,
        int moonCount,
        double orbitalDistance,
        bool hasLife);

    void displayInfo() const override;
    json toJSON() const override;
};
