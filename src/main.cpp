#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>
#include <exception>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

#include "CelestialObject.h"
#include "Planet.h"
#include "Star.h"
#include "Moon.h"
#include "Asteroid.h"
#include "Comet.h"
#include "Galaxy.h"
#include "GalaxyCluster.h"
#include "Nebula.h"
#include "BlackHole.h"
#include "Exoplanet.h"
#include "StarSystem.h"

// Function prototypes
void showMenu();
void addObject(vector<CelestialObject *> &catalog);
void viewCatalog(const vector<CelestialObject *> &catalog);
void searchByName(const vector<CelestialObject *> &catalog);
void deleteByName(vector<CelestialObject *> &catalog);
void searchObject(const vector<CelestialObject *> &catalog);
void sortObjectsByName(vector<CelestialObject *> &catalog);
void sortByType(vector<CelestialObject *> &catalog);
void clearInputBuffer();
string toLower(const string &str);
bool confirmAction(const string &message);
string getCurrentTimestamp();
void logAction(const string &action, const string &objectName, const string &objectType);
void saveUniverse(const vector<CelestialObject *> &catalog, const string &filename);
void loadUniverse(vector<CelestialObject *> &catalog, const string &filename);

int main()
{
    vector<CelestialObject *> catalog;
    int choice;

    // Auto-load universe on startup
    loadUniverse(catalog, "../data/universe.json");

    while (true)
    {
        showMenu();
        cout << "\nEnter your choice: ";

        if (!(cin >> choice))
        {
            clearInputBuffer();
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            addObject(catalog);
            break;
        case 2:
            viewCatalog(catalog);
            break;
        case 3:
            searchByName(catalog);
            break;
        case 4:
            deleteByName(catalog);
            break;

        case 5:
            searchObject(catalog);
            break;
        case 6:
            sortObjectsByName(catalog);
            break;

        case 7:
            sortByType(catalog);
            break;

        case 8:
            saveUniverse(catalog, "../data/universe.json");
            break;

        case 9:
            loadUniverse(catalog, "../data/universe.json");
            break;

        case 0:
            cout << "Exiting...\n";
            // Cleanup memory before exit
            for (auto obj : catalog)
            {
                delete obj;
            }
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------

void showMenu()
{
    cout << "\n===== CELESTIAL CATALOG =====\n";
    cout << "1. Add Celestial Object\n";
    cout << "2. View Catalog\n";
    cout << "3. Search by Name\n";
    cout << "4. Delete by Name\n";
    cout << "5. Search Object by Name\n";
    cout << "6. Sort Objects by Name\n";
    cout << "7. Sort Objects by Type\n";
    cout << "8. Save Universe\n";
    cout << "9. Load Universe\n";
    cout << "0. Exit\n";
}

void addObject(vector<CelestialObject *> &catalog)
{
    cout << "\nChoose type:\n";
    cout << "1. Star\n";
    cout << "2. Planet\n";
    cout << "3. Asteroid\n";

    int type;
    if (!(cin >> type) || type < 1 || type > 3)
    {
        clearInputBuffer();
        cout << "Invalid type selection.\n";
        return;
    }

    string name, desc;
    double mass, age;

    cout << "Name: ";
    clearInputBuffer();
    getline(cin, name);
    if (name.empty())
    {
        cout << "Name cannot be empty.\n";
        return;
    }

    cout << "Mass (kg): ";
    if (!(cin >> mass) || mass < 0)
    {
        clearInputBuffer();
        cout << "Invalid mass. Must be a positive number.\n";
        return;
    }

    cout << "Age (billion years): ";
    if (!(cin >> age) || age < 0)
    {
        clearInputBuffer();
        cout << "Invalid age. Must be a positive number.\n";
        return;
    }

    cout << "Description: ";
    clearInputBuffer();
    getline(cin, desc);

    try
    {
        if (type == 1)
        {
            double temp, lum;
            string spectral;

            cout << "Temperature (Kelvin): ";
            if (!(cin >> temp) || temp < 0)
            {
                clearInputBuffer();
                cout << "Invalid temperature.\n";
                return;
            }

            cout << "Luminosity (relative to Sun): ";
            if (!(cin >> lum) || lum < 0)
            {
                clearInputBuffer();
                cout << "Invalid luminosity.\n";
                return;
            }

            cout << "Spectral Type: ";
            clearInputBuffer();
            getline(cin, spectral);

            catalog.push_back(new Star(name, mass, age, desc, temp, lum, spectral));
            cout << "Star added successfully!\n";
            logAction("added", name, "Star");
        }
        else if (type == 2)
        {
            int moonCount;
            double orbitalDistance;
            bool hasLife;

            cout << "Moon count: ";
            if (!(cin >> moonCount) || moonCount < 0)
            {
                clearInputBuffer();
                cout << "Invalid moon count.\n";
                return;
            }

            cout << "Orbital distance (million km): ";
            if (!(cin >> orbitalDistance) || orbitalDistance < 0)
            {
                clearInputBuffer();
                cout << "Invalid orbital distance.\n";
                return;
            }

            cout << "Supports life (1/0): ";
            if (!(cin >> hasLife))
            {
                clearInputBuffer();
                cout << "Invalid input for life support.\n";
                return;
            }

            catalog.push_back(new Planet(name, mass, age, desc, moonCount, orbitalDistance, hasLife));
            cout << "Planet added successfully!\n";
            logAction("added", name, "Planet");
        }
        else if (type == 3)
        {
            double orbitDist;
            string typeStr;

            cout << "Orbit distance (million km): ";
            if (!(cin >> orbitDist) || orbitDist < 0)
            {
                clearInputBuffer();
                cout << "Invalid orbit distance.\n";
                return;
            }

            cout << "Type (e.g., C-type, S-type): ";
            clearInputBuffer();
            getline(cin, typeStr);

            catalog.push_back(new Asteroid(name, mass, age, desc, orbitDist, typeStr));
            cout << "Asteroid added successfully!\n";
            logAction("added", name, "Asteroid");
        }
    }
    catch (const exception &e)
    {
        cout << "Error adding object: " << e.what() << "\n";
    }
}

void viewCatalog(const vector<CelestialObject *> &catalog)
{
    if (catalog.empty())
    {
        cout << "\nCatalog is empty.\n";
        return;
    }

    cout << "\n===== CATALOG (" << catalog.size() << " object(s)) =====\n";
    for (size_t i = 0; i < catalog.size(); ++i)
    {
        cout << "[" << (i + 1) << "] ";
        catalog[i]->displayInfo();
        cout << "\n";
    }
}

void searchByName(const vector<CelestialObject *> &catalog)
{
    if (catalog.empty())
    {
        cout << "\nCatalog is empty.\n";
        return;
    }

    string query;
    cout << "Enter name to search: ";
    clearInputBuffer();
    getline(cin, query);

    if (query.empty())
    {
        cout << "Search query cannot be empty.\n";
        return;
    }

    string queryLower = toLower(query);
    bool found = false;

    for (auto obj : catalog)
    {
        if (toLower(obj->getName()) == queryLower)
        {
            cout << "\nFound:\n";
            obj->displayInfo();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "No object found with that name.\n";
    }
}

void deleteByName(vector<CelestialObject *> &catalog)
{
    if (catalog.empty())
    {
        cout << "\nCatalog is empty.\n";
        return;
    }

    string target;
    cout << "Enter name to delete: ";
    clearInputBuffer();
    getline(cin, target);

    if (target.empty())
    {
        cout << "Name cannot be empty.\n";
        return;
    }

    string targetLower = toLower(target);
    CelestialObject *foundObj = nullptr;
    auto foundIt = catalog.end();

    // First, find the object
    for (auto it = catalog.begin(); it != catalog.end(); ++it)
    {
        if (toLower((*it)->getName()) == targetLower)
        {
            foundObj = *it;
            foundIt = it;
            break;
        }
    }

    if (foundObj == nullptr)
    {
        cout << "No object found with that name.\n";
        return;
    }

    // Display object info before asking for confirmation
    cout << "\nObject to delete:\n";
    foundObj->displayInfo();
    cout << "\n";

    // Ask for confirmation
    if (!confirmAction("Are you sure you want to delete this object? (y/n): "))
    {
        cout << "Deletion cancelled.\n";
        return;
    }

    // Determine object type for logging
    string objectType = "Unknown";
    if (dynamic_cast<Star *>(foundObj))
        objectType = "Star";
    else if (dynamic_cast<Planet *>(foundObj))
        objectType = "Planet";
    else if (dynamic_cast<Asteroid *>(foundObj))
        objectType = "Asteroid";

    // Delete the object
    delete foundObj;
    catalog.erase(foundIt);
    cout << "Deleted successfully.\n";

    // Log the deletion
    logAction("removed", target, objectType);
}

void searchObject(const vector<CelestialObject *> &catalog)
{
    cout << "\nEnter name to search: ";
    string keyword;
    cin.ignore();
    getline(cin, keyword);

    bool found = false;
    cout << "\n🔎 Search Results:\n";

    for (auto obj : catalog)
    {
        string nm = obj->getName();
        // case-insensitive partial match
        string nameLower, keyLower;
        for (char c : nm)
            nameLower += tolower(c);
        for (char c : keyword)
            keyLower += tolower(c);

        if (nameLower.find(keyLower) != string::npos)
        {
            obj->displayInfo();
            cout << "-------------------------------------\n";
            found = true;
        }
    }

    if (!found)
        cout << "❌ No objects found matching: " << keyword << "\n";
}

void sortObjectsByName(vector<CelestialObject *> &catalog)
{
    sort(catalog.begin(), catalog.end(),
         [](CelestialObject *a, CelestialObject *b)
         {
             return a->getName() < b->getName();
         });

    cout << "\n✨ Catalog sorted by name (A → Z).\n";
}

string getTypeName(CelestialObject *obj)
{
    return typeid(*obj).name(); // or manually define types
}

void sortByType(vector<CelestialObject *> &catalog)
{
    sort(catalog.begin(), catalog.end(),
         [](CelestialObject *a, CelestialObject *b)
         {
             return typeid(*a).name() < typeid(*b).name();
         });

    cout << "\n✨ Catalog sorted by Type.\n";
}

// Helper functions
void clearInputBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string toLower(const string &str)
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

bool confirmAction(const string &message)
{
    char response;
    cout << message;
    cin >> response;
    clearInputBuffer();
    return (response == 'y' || response == 'Y');
}

string getCurrentTimestamp()
{
    time_t now = time(0);
    tm *timeinfo = localtime(&now);

    stringstream ss;
    ss << put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void logAction(const string &action, const string &objectName, const string &objectType)
{
    string timestamp = getCurrentTimestamp();
    string logMessage;

    if (!objectType.empty())
    {
        logMessage = objectType + " \"" + objectName + "\" " + action + " on " + timestamp;
    }
    else
    {
        logMessage = "\"" + objectName + "\" " + action + " on " + timestamp;
    }

    // Log to console
    cout << "[LOG] " << logMessage << "\n";

    // Log to file
    ofstream logFile("catalog_log.txt", ios::app);
    if (logFile.is_open())
    {
        logFile << logMessage << "\n";
        logFile.close();
    }
}

void saveUniverse(const vector<CelestialObject *> &catalog, const string &filename)
{
    json j = json::array();

    for (const auto &obj : catalog)
    {
        if (obj != nullptr)
        {
            j.push_back(obj->toJSON());
        }
    }

    ofstream file(filename);
    if (file.is_open())
    {
        file << j.dump(4);
        file.close();
        cout << "\n✅ Universe saved to " << filename << " (" << catalog.size() << " objects)\n";
        logAction("saved universe", filename, "");
    }
    else
    {
        cout << "\n❌ Error: Could not open file " << filename << " for writing.\n";
    }
}

void loadUniverse(vector<CelestialObject *> &catalog, const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        // File doesn't exist - this is okay on first run
        cout << "\nℹ️  No universe file found at " << filename << ". Starting with empty catalog.\n";
        return;
    }

    try
    {
        json j;
        file >> j;
        file.close();

        // Clean up existing objects before loading new ones
        for (auto obj : catalog)
        {
            delete obj;
        }
        catalog.clear();

        int loaded = 0;
        int skipped = 0;
        json::array_t items;

        // Handle both formats: flat array or nested object with arrays
        if (j.is_array())
        {
            // New format: flat array
            items = j;
        }
        else if (j.is_object())
        {
            // Old format: nested object with "stars", "planets", "galaxies", etc.
            for (auto &[key, value] : j.items())
            {
                if (value.is_array())
                {
                    for (const auto &item : value)
                    {
                        items.push_back(item);
                    }
                }
            }
        }
        else
        {
            cout << "\n⚠️  Warning: Invalid JSON format in " << filename << ". Expected an array or object.\n";
            return;
        }

        for (const auto &item : items)
        {
            if (!item.is_object())
            {
                skipped++;
                continue;
            }

            CelestialObject *obj = CelestialObject::fromJSON(item);
            if (obj != nullptr)
            {
                catalog.push_back(obj);
                loaded++;
            }
            else
            {
                skipped++;
            }
        }

        cout << "\n✅ Universe loaded from " << filename << " (" << loaded << " objects loaded";
        if (skipped > 0)
        {
            cout << ", " << skipped << " skipped";
        }
        cout << ")\n";
        logAction("loaded universe", filename, "");
    }
    catch (const json::parse_error &e)
    {
        cout << "\n⚠️  Warning: JSON parse error in " << filename << ": " << e.what() << "\n";
    }
    catch (const exception &e)
    {
        cout << "\n⚠️  Warning: Error loading " << filename << ": " << e.what() << "\n";
    }
}
