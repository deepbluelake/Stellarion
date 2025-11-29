#include "Comet.h"
#include <iostream>
#include <nlohmann/json.hpp>

Comet::Comet(
    const std::string& name,
    double mass,
    double age,
    const std::string& desc,
    double peri,
    double aph,
    const std::string& comp
) : CelestialObject(name, mass, age, desc),
    perihelion(peri),
    aphelion(aph),
    composition(comp) {}

void Comet::displayInfo() const {
    std::cout << "\n--- COMET ---\n";
    CelestialObject::displayInfo();
    std::cout << "Perihelion: " << perihelion << " million km\n";
    std::cout << "Aphelion: " << aphelion << " million km\n";
    std::cout << "Composition: " << composition << "\n";
    std::cout << "----------------------------------------\n";
}

json Comet::toJSON() const {
    json j;
    j["type"] = "Comet";
    j["name"] = name;
    j["mass"] = mass;
    j["age"] = age;
    j["desc"] = description;
    j["perihelion"] = perihelion;
    j["aphelion"] = aphelion;
    j["composition"] = composition;
    return j;
}
