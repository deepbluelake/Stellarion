#include "Asteroid.h"
#include <iostream>
#include <nlohmann/json.hpp>

Asteroid::Asteroid(
    const std::string &name,
    double mass,
    double age,
    const std::string &desc,
    double orbitDist,
    const std::string &type) : CelestialObject(name, mass, age, desc),
                               orbitDistance(orbitDist),
                               type(type) {}

void Asteroid::displayInfo() const
{
    std::cout << "\n--- ASTEROID ---\n";
    CelestialObject::displayInfo();
    std::cout << "Orbit Distance: " << orbitDistance << " million km\n";
    std::cout << "Type: " << type << "\n";
    std::cout << "----------------------------------------\n";
}

json Asteroid::toJSON() const
{
    json j;
    j["type"] = "Asteroid";
    j["name"] = name;
    j["mass"] = mass;
    j["age"] = age;
    j["desc"] = description;
    j["orbitDistance"] = orbitDistance;
    j["asteroidType"] = type;
    return j;
}
