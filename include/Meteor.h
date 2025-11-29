#pragma once
#include "CelestialObject.h"
#include <string>

class Meteor : public CelestialObject
{
private:
    double velocity;      // km/s
    std::string material; // iron, stony, etc.
    bool burning;         // currently glowing in atmosphere?

public:
    Meteor(
        const std::string &name,
        double mass,
        double age,
        const std::string &desc,
        double velocity,
        const std::string &material,
        bool burning);

    void displayInfo() const override;
};
