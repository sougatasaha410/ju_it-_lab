#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Class to represent a 2D point
class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // Calculate distance between two points
    double distanceTo(const Point& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};

// Class to represent a wireless device
class WirelessDevice {
private:
    static int idCounter; // Static variable to generate unique IDs
    int id; // Unique ID for the device
    Point location; // Location of the device
    double transmissionRange; // Transmission range of the device

public:
    WirelessDevice(const Point& loc, double range) 
        : location(loc), transmissionRange(range) {
        id = ++idCounter; // Assign unique ID
    }

    // Getters for device properties
    int getId() const { return id; }
    const Point& getLocation() const { return location; }
    double getTransmissionRange() const { return transmissionRange; }

    // Find neighbors within the transmission range
    std::vector<WirelessDevice*> findNeighbors(const std::vector<WirelessDevice*>& devices) const {
        std::vector<WirelessDevice*> neighbors;
        for (const auto& device : devices) {
            if (device != this && location.distanceTo(device->getLocation()) <= transmissionRange) {
                neighbors.push_back(device);
            }
        }
        return neighbors;
    }

    // Move the device to a new location
    void moveTo(const Point& newLocation) {
        location = newLocation;
    }
};

// Initialize the static member
int WirelessDevice::idCounter = 0;

// Function to print device information
void printDeviceInfo(const WirelessDevice& device, const std::vector<WirelessDevice*>& neighbors) {
    std::cout << "Device ID: " << device.getId() << "\n";
    std::cout << "Location: (" << device.getLocation().x << ", " << device.getLocation().y << ")\n";
    std::cout << "Transmission Range: " << device.getTransmissionRange() << "\n";
    std::cout << "Neighbors:\n";
    for (const auto& neighbor : neighbors) {
        std::cout << "  - Device ID: " << neighbor->getId() << "\n";
    }
    std::cout << "\n";
}

int main() {
    std::srand(static_cast<unsigned>(std::time(0))); // Seed random number generator

    const int numDevices = 10;
    std::vector<WirelessDevice*> devices;

    // Create 10 devices with random locations and transmission ranges
    for (int i = 0; i < numDevices; ++i) {
        double x = std::rand() % 100;
        double y = std::rand() % 100;
        double range = 10 + std::rand() % 20; // Random range between 10 and 30
        devices.push_back(new WirelessDevice(Point(x, y), range));
    }

    // Find and print neighbors before moving
    std::cout << "Neighbors before moving:\n";
    for (const auto& device : devices) {
        auto neighbors = device->findNeighbors(devices);
        printDeviceInfo(*device, neighbors);
    }

    // Move devices to new random locations
    for (auto& device : devices) {
        double newX = std::rand() % 100;
        double newY = std::rand() % 100;
        device->moveTo(Point(newX, newY));
    }

    // Find and print neighbors after moving
    std::cout << "Neighbors after moving:\n";
    for (const auto& device : devices) {
        auto neighbors = device->findNeighbors(devices);
        printDeviceInfo(*device, neighbors);
    }

    // Clean up
    for (auto& device : devices) {
        delete device;
    }

    return 0;
}
