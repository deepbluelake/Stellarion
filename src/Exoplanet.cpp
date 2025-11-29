#include "Exoplanet.h"
#include <iostream>
#include <nlohmann/json.hpp>

Exoplanet::Exoplanet(
    std::string name,
    double mass,
    double age,
    std::string desc,
    double orbitalDistance,
    bool habitable
)
    : CelestialObject(name, mass, age, desc),
      orbitalDistance(orbitalDistance),
      habitable(habitable)
{}

void Exoplanet::displayInfo() const {
    CelestialObject::displayInfo();
    std::cout << "Orbital Distance: " << orbitalDistance << " AU\n";
    std::cout << "Habitable: " << (habitable ? "Yes" : "No") << "\n";
    std::cout << "----------------------------------------\n";
}

json Exoplanet::toJSON() const {
    json j;
    j["type"] = "Exoplanet";
    j["name"] = name;
    j["mass"] = mass;
    j["age"] = age;
    j["desc"] = description;
    j["orbitalDistance"] = orbitalDistance;
    j["habitable"] = habitable;
    return j;
}
