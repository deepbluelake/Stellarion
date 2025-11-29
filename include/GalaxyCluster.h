#pragma once
#include "CelestialObject.h"
#include <string>

class GalaxyCluster : public CelestialObject
{
private:
    int galaxyCount; // number of galaxies in the cluster
    double diameter; // in million light-years

public:
    GalaxyCluster(
        const std::string &name,
        double mass,
        double age,
        const std::string &desc,
        int galaxyCount,
        double diameter);

    void displayInfo() const override;
    json toJSON() const override;
};
