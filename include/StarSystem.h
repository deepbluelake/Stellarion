#pragma once
#include "CelestialObject.h"
#include "Star.h"
#include "Planet.h"
#include <vector>
#include <string>

class StarSystem : public CelestialObject {
private:
    const Star* centralStar;               // pointer, not owned
    std::vector<const Planet*> planets;    // list of planets (not owned)

public:
    StarSystem(
        const std::string& name,
        double mass,
        double age,
        const std::string& desc,
        const Star* centralStar
    );

    void addPlanet(const Planet* planet);
    void displayInfo() const override;
};
