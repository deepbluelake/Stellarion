#pragma once
#include "CelestialObject.h"
#include <string>

class Comet : public CelestialObject
{
private:
    double perihelion;       // closest point to Sun (million km)
    double aphelion;         // farthest point (million km)
    std::string composition; // e.g., "ice & dust"

public:
    Comet(
        const std::string &name,
        double mass,
        double age,
        const std::string &desc,
        double perihelion,
        double aphelion,
        const std::string &composition);

    void displayInfo() const override;
    json toJSON() const override;
};
