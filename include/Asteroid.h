#pragma once
#include "CelestialObject.h"
#include <string>

class Asteroid : public CelestialObject
{
private:
    double orbitDistance; // in million km
    std::string type;     // e.g., "C-type", "S-type", etc.

public:
    Asteroid(
        const std::string &name,
        double mass,
        double age,
        const std::string &desc,
        double orbitDist,
        const std::string &type);

    void displayInfo() const override;
    json toJSON() const override;
};

// ### **🌌 Phase 4 — Visualization**

// **Goal:** Bring Stellarion to life.

// - [ ]  Add basic 2D visual display (SFML / Raylib)
// - [ ]  Show orbiting planets around a star
// - [ ]  Try simple 3D render (OpenGL) later

//     🎯 *Milestone:* See your catalog — not just read it.

// ---

// ### **✨ Phase 5 — Advanced / Optional**

// **Goal:** Make it feel like a full system.

// - [ ]  Random Universe Generator
// - [ ]  Search filters & statistics
// - [ ]  GUI or Web-based frontend
// - [ ]  Export catalog (PDF, HTML, or JSON API)

//     🎯 *Milestone:* A full-fledged “Cosmic Catalog Explorer.”