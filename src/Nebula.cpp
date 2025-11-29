#include "Nebula.h"
#include <iostream>
#include <nlohmann/json.hpp>
using namespace std;

Nebula::Nebula(
    string name,
    double mass,
    double age,
    string desc,
    string nebulaType,
    double size
) : CelestialObject(name, mass, age, desc),
    nebulaType(nebulaType),
    size(size) {}

void Nebula::displayInfo() const {
    CelestialObject::displayInfo();
    cout << "Nebula Type: " << nebulaType << "\n";
    cout << "Size: " << size << " light-years\n";
}

json Nebula::toJSON() const {
    json j;
    j["type"] = "Nebula";
    j["name"] = name;
    j["mass"] = mass;
    j["age"] = age;
    j["desc"] = description;
    j["nebulaType"] = nebulaType;
    j["size"] = size;
    return j;
}
