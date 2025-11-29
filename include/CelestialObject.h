#pragma once

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class CelestialObject
{
protected:
    std::string name;
    double mass;
    double age; // in billions of years
    std::string description;

public:
    // Constructor
    CelestialObject(
        const std::string &n = "Unknown",
        double m = 0.0,
        double a = 0.0,
        const std::string &desc = "N/A");

    // Virtual destructor (important for inheritance)
    virtual ~CelestialObject() = default;

    // Getters
    const std::string &getName() const { return name; }
    double getMass() const { return mass; }
    double getAge() const { return age; }
    const std::string &getDescription() const { return description; }

    // Display
    virtual void displayInfo() const;

    // JSON serialization
    virtual json toJSON() const = 0;

    // Factory method to create objects from JSON
    static CelestialObject *fromJSON(const json &j);
};
