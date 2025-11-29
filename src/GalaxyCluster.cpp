#include "GalaxyCluster.h"
#include <iostream>
#include <nlohmann/json.hpp>

GalaxyCluster::GalaxyCluster(
    const std::string& name,
    double mass,
    double age,
    const std::string& desc,
    int gCount,
    double diameter
) : CelestialObject(name, mass, age, desc),
    galaxyCount(gCount),
    diameter(diameter) {}

void GalaxyCluster::displayInfo() const {
    std::cout << "\n--- GALAXY CLUSTER ---\n";
    CelestialObject::displayInfo();
    std::cout << "Number of Galaxies: " << galaxyCount << "\n";
    std::cout << "Diameter: " << diameter << " million light-years\n";
    std::cout << "----------------------------------------\n";
}

json GalaxyCluster::toJSON() const {
    json j;
    j["type"] = "GalaxyCluster";
    j["name"] = name;
    j["mass"] = mass;
    j["age"] = age;
    j["desc"] = description;
    j["galaxyCount"] = galaxyCount;
    j["diameter"] = diameter;
    return j;
}
