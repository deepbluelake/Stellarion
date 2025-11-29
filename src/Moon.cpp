#include "Moon.h"
#include <iostream>
#include <nlohmann/json.hpp>

Moon::Moon(
    const std::string& name,
    double mass,
    double age,
    const std::string& desc,
    double distance,
    const std::string& planet
) : CelestialObject(name, mass, age, desc),
    orbitalDistance(distance),
    parentPlanet(planet) {}

void Moon::displayInfo() const {
    std::cout << "\n--- MOON ---\n";
    CelestialObject::displayInfo();
    std::cout << "Parent Planet: " << parentPlanet << "\n";
    std::cout << "Orbital Distance: " << orbitalDistance << " km\n";
    std::cout << "----------------------------------------\n";
}

json Moon::toJSON() const {
    json j;
    j["type"] = "Moon";
    j["name"] = name;
    j["mass"] = mass;
    j["age"] = age;
    j["desc"] = description;
    j["orbitalDistance"] = orbitalDistance;
    j["parentPlanet"] = parentPlanet;
    return j;
}
