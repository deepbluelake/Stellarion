#include "CelestialObject.h"
#include "Planet.h"
#include "Star.h"
#include "Asteroid.h"
#include "Moon.h"
#include "Comet.h"
#include "Nebula.h"
#include "BlackHole.h"
#include "Exoplanet.h"
#include "Galaxy.h"
#include "GalaxyCluster.h"
#include <iostream>
#include <nlohmann/json.hpp>
using namespace std;

CelestialObject::CelestialObject(const std::string &n, double m, double a, const std::string &desc)
    : name(n), mass(m), age(a), description(desc) {}

void CelestialObject::displayInfo() const
{
    cout << "Name: " << name << endl;
    cout << "Mass: " << mass << " kg" << endl;
    cout << "Age: " << age << " billion years" << endl;
    cout << "Description: " << description << endl;
}

CelestialObject *CelestialObject::fromJSON(const json &j)
{
    if (!j.contains("type") || !j.contains("name"))
    {
        return nullptr;
    }

    string type = j["type"];
    // Normalize type name (handle both "Star" and "star", "Planet" and "planet", etc.)
    if (type == "star")
        type = "Star";
    else if (type == "planet")
        type = "Planet";
    else if (type == "galaxy")
        type = "Galaxy";
    else if (type == "asteroid")
        type = "Asteroid";
    else if (type == "moon")
        type = "Moon";
    else if (type == "comet")
        type = "Comet";
    else if (type == "nebula")
        type = "Nebula";
    else if (type == "blackhole")
        type = "BlackHole";
    else if (type == "exoplanet")
        type = "Exoplanet";
    else if (type == "galaxycluster")
        type = "GalaxyCluster";

    string name = j.value("name", "Unknown");
    // Handle mass - might be in different units or missing
    double mass = j.value("mass", 0.0);
    if (mass == 0.0 && j.contains("mass_kg"))
    {
        mass = j.value("mass_kg", 0.0);
    }
    // Handle age - might be missing for some objects
    double age = j.value("age", 0.0);
    if (age == 0.0 && j.contains("age_billion_years"))
    {
        age = j.value("age_billion_years", 0.0);
    }
    string desc = j.value("desc", j.value("description", "N/A"));

    if (type == "Planet")
    {
        int moonCount = j.value("moonCount", 0);
        double orbitalDistance = j.value("orbitalDistance", j.value("orbital_period", 0.0));
        bool hasLife = j.value("hasLife", j.value("has_life", false));
        return new Planet(name, mass, age, desc, moonCount, orbitalDistance, hasLife);
    }
    else if (type == "Star")
    {
        double temperature = j.value("temperature", 0.0);
        double luminosity = j.value("luminosity", 0.0);
        string spectralType = j.value("spectralType", j.value("spectral_class", ""));
        return new Star(name, mass, age, desc, temperature, luminosity, spectralType);
    }
    else if (type == "Asteroid")
    {
        double orbitDistance = j.value("orbitDistance", 0.0);
        string asteroidType = j.value("asteroidType", "");
        return new Asteroid(name, mass, age, desc, orbitDistance, asteroidType);
    }
    else if (type == "Moon")
    {
        double orbitalDistance = j.value("orbitalDistance", 0.0);
        string parentPlanet = j.value("parentPlanet", "");
        return new Moon(name, mass, age, desc, orbitalDistance, parentPlanet);
    }
    else if (type == "Comet")
    {
        double perihelion = j.value("perihelion", 0.0);
        double aphelion = j.value("aphelion", 0.0);
        string composition = j.value("composition", "");
        return new Comet(name, mass, age, desc, perihelion, aphelion, composition);
    }
    else if (type == "Nebula")
    {
        string nebulaType = j.value("nebulaType", "");
        double size = j.value("size", 0.0);
        return new Nebula(name, mass, age, desc, nebulaType, size);
    }
    else if (type == "BlackHole")
    {
        double eventHorizonRadius = j.value("eventHorizonRadius", 0.0);
        double spin = j.value("spin", 0.0);
        return new BlackHole(name, mass, age, desc, eventHorizonRadius, spin);
    }
    else if (type == "Exoplanet")
    {
        double orbitalDistance = j.value("orbitalDistance", 0.0);
        bool habitable = j.value("habitable", false);
        return new Exoplanet(name, mass, age, desc, orbitalDistance, habitable);
    }
    else if (type == "Galaxy")
    {
        string galaxyType = j.value("galaxyType", j.value("galaxy_type", ""));
        int starCount = j.value("starCount", j.value("star_count_billion", 0));
        return new Galaxy(name, mass, age, desc, galaxyType, starCount);
    }
    else if (type == "GalaxyCluster")
    {
        int galaxyCount = j.value("galaxyCount", 0);
        double diameter = j.value("diameter", 0.0);
        return new GalaxyCluster(name, mass, age, desc, galaxyCount, diameter);
    }

    return nullptr;
}
