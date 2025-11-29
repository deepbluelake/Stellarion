#include "Galaxy.h"
#include <iostream>
#include <nlohmann/json.hpp>

Galaxy::Galaxy(
    const std::string& name,
    double mass,
    double age,
    const std::string& desc,
    const std::string& type,
    int starCount
) : CelestialObject(name, mass, age, desc),
    galaxyType(type),
    starCount(starCount) {}

void Galaxy::displayInfo() const {
    std::cout << "\n--- GALAXY ---\n";
    CelestialObject::displayInfo();
    std::cout << "Type: " << galaxyType << "\n";
    std::cout << "Star Count: " << starCount << "\n";
    std::cout << "----------------------------------------\n";
}

json Galaxy::toJSON() const {
    json j;
    j["type"] = "Galaxy";
    j["name"] = name;
    j["mass"] = mass;
    j["age"] = age;
    j["desc"] = description;
    j["galaxyType"] = galaxyType;
    j["starCount"] = starCount;
    return j;
}
