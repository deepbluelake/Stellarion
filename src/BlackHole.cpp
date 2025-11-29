#include "BlackHole.h"
#include <iostream>
#include <nlohmann/json.hpp>

BlackHole::BlackHole(
    std::string name,
    double mass,
    double age,
    std::string desc,
    double eventHorizonRadius,
    double spin
)
    : CelestialObject(name, mass, age, desc),
      eventHorizonRadius(eventHorizonRadius),
      spin(spin)
{}

void BlackHole::displayInfo() const {
    CelestialObject::displayInfo();
    std::cout << "Event Horizon Radius: " << eventHorizonRadius << " km\n";
    std::cout << "Spin: " << spin << "\n";
    std::cout << "----------------------------------------\n";
}

json BlackHole::toJSON() const {
    json j;
    j["type"] = "BlackHole";
    j["name"] = name;
    j["mass"] = mass;
    j["age"] = age;
    j["desc"] = description;
    j["eventHorizonRadius"] = eventHorizonRadius;
    j["spin"] = spin;
    return j;
}
