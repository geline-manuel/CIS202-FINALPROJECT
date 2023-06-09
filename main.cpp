#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Mountain {
private:
    string name;
    string country;
    double elevation;

public:
    // Constructor
    Mountain(const string& name, const string& country, double elevation)
        : name(name), country(country), elevation(elevation) {}

    // Setters and getters
    void setName(const string& name) {
        this->name = name;
    }

    string getName() const {
        return name;
    }

    void setCountry(const string& country) {
        this->country = country;
    }

    string getCountry() const {
        return country;
    }

    void setElevation(double elevation) {
        this->elevation = elevation;
    }

    double getElevation() const {
        return elevation;
    }

    // Convert elevation from feet to meters
    double toMeters() const {
        return elevation / 3.2808;
    }
};

// Find the minimum elevation
double minElevation(const vector<Mountain>& mountains) {
    double min = mountains[0].getElevation();
    for (size_t i = 1; i < mountains.size(); ++i) {
        if (mountains[i].getElevation() < min) {
            min = mountains[i].getElevation();
        }
    }
    return min;
}

int main() {
    vector<Mountain> mountains;

    // Create instances of Mountain objects
    Mountain chimborazo("Chimborazo", "Ecuador", 20549);
    Mountain matterhorn("Matterhorn", "Switzerland", 14692);
    Mountain olympus("Olympus", "Greece (Macedonia)", 9573);
    Mountain everest("Everest", "Nepal", 29029);
    Mountain mountMarcy("Mount Marcy - Adirondacks", "United States", 5344);
    Mountain mountMitchell("Mount Mitchell - Blue Ridge", "United States", 6684);
    Mountain zugspitze("Zugspitze", "Switzerland", 9719);

    // Add Mountain objects to the vector
    mountains.push_back(chimborazo);
    mountains.push_back(matterhorn);
    mountains.push_back(olympus);
    mountains.push_back(everest);
    mountains.push_back(mountMarcy);
    mountains.push_back(mountMitchell);
    mountains.push_back(zugspitze);

    // Print out Mountain details
    for (size_t i = 0; i < mountains.size(); ++i) {
        const Mountain& mountain = mountains[i];
        cout << "Name: " << mountain.getName() << endl;
        cout << "Country: " << mountain.getCountry() << endl;
        cout << "Elevation (feet): " << mountain.getElevation() << endl;
        cout << "Elevation (meters): " << mountain.toMeters() << endl;
        cout << endl;
    }

    // Find and print the shortest mountain
    double minElev = minElevation(mountains);
    for (size_t i = 0; i < mountains.size(); ++i) {
        const Mountain& mountain = mountains[i];
        if (mountain.getElevation() == minElev) {
            cout << "Shortest mountain: " << mountain.getName() << endl;
            cout << "Elevation (feet): " << mountain.getElevation() << endl;
            cout << "Elevation (meters): " << mountain.toMeters() << endl;
            break;
        }
    }

  return 0;
}
