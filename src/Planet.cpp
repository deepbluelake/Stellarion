#include "Planet.h"
#include <iostream>
#include <nlohmann/json.hpp>

Planet::Planet(
    const std::string &name,
    double mass,
    double age,
    const std::string &desc,
    int moonCount,
    double orbitalDistance,
    bool hasLife)
    : CelestialObject(name, mass, age, desc),
      moonCount(moonCount),
      orbitalDistance(orbitalDistance),
      hasLife(hasLife)
{
}

void Planet::displayInfo() const
{
    std::cout << "\n--- PLANET ---\n";
    CelestialObject::displayInfo();
    std::cout << "Moons: " << moonCount << "\n";
    std::cout << "Orbital Distance: " << orbitalDistance << " million km\n";
    std::cout << "Supports Life: " << (hasLife ? "Yes" : "No") << "\n";
    std::cout << "----------------------------------------\n";
}

json Planet::toJSON() const
{
    json j;
    j["type"] = "Planet";
    j["name"] = name;
    j["mass"] = mass;
    j["age"] = age;
    j["desc"] = description;
    j["moonCount"] = moonCount;
    j["orbitalDistance"] = orbitalDistance;
    j["hasLife"] = hasLife;
    return j;
}
