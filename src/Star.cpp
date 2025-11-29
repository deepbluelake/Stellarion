#include "Star.h"
#include <iostream>
#include <nlohmann/json.hpp>

Star::Star(
    const std::string &name,
    double mass,
    double age,
    const std::string &desc,
    double temperature,
    double luminosity,
    const std::string &spectralType)
    : CelestialObject(name, mass, age, desc),
      temperature(temperature),
      luminosity(luminosity),
      spectralType(spectralType)
{
}

void Star::displayInfo() const
{
    std::cout << "\n--- STAR ---\n";
    CelestialObject::displayInfo();
    std::cout << "Temperature: " << temperature << " K\n";
    std::cout << "Luminosity: " << luminosity << " L☉\n";
    std::cout << "Spectral Type: " << spectralType << "\n";
    std::cout << "----------------------------------------\n";
}

json Star::toJSON() const
{
    json j;
    j["type"] = "Star";
    j["name"] = name;
    j["mass"] = mass;
    j["age"] = age;
    j["desc"] = description;
    j["temperature"] = temperature;
    j["luminosity"] = luminosity;
    j["spectralType"] = spectralType;
    return j;
}
