#include "Meteor.h"
#include <iostream>

Meteor::Meteor(
    const std::string& name,
    double mass,
    double age,
    const std::string& desc,
    double velocity,
    const std::string& material,
    bool burning
) : CelestialObject(name, mass, age, desc),
    velocity(velocity),
    material(material),
    burning(burning) {}

void Meteor::displayInfo() const {
    std::cout << "\n--- METEOR ---\n";
    CelestialObject::displayInfo();
    std::cout << "Material: " << material << "\n";
    std::cout << "Velocity: " << velocity << " km/s\n";
    std::cout << "Burning: " << (burning ? "Yes" : "No") << "\n";
    std::cout << "----------------------------------------\n";
}
