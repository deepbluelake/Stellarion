#include "StarSystem.h"
#include <iostream>

StarSystem::StarSystem(
    const std::string& name,
    double mass,
    double age,
    const std::string& desc,
    const Star* centralStar
) : CelestialObject(name, mass, age, desc),
    centralStar(centralStar) {}

void StarSystem::addPlanet(const Planet* planet) {
    planets.push_back(planet);
}

void StarSystem::displayInfo() const {
    std::cout << "\n=== STAR SYSTEM ===\n";
    CelestialObject::displayInfo();

    std::cout << "\nCentral Star:\n";
    centralStar->displayInfo();

    std::cout << "\nPlanets (" << planets.size() << "):\n";
    for (const auto& p : planets) {
        p->displayInfo();
    }

    std::cout << "----------------------------------------\n";
}
