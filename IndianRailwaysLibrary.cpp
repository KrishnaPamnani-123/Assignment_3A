#include "IndianRailwaysLibrary.h"

// Helper function to convert HH:MM to minutes
int timeToMinutes(const std::string& time) {
    size_t colonPos = time.find(':');
    if (colonPos == std::string::npos) {
        throw std::invalid_argument("Invalid time format");
    }
    int hours = std::stoi(time.substr(0, colonPos));
    int minutes = std::stoi(time.substr(colonPos + 1));
    return hours * 60 + minutes;
}

// Template class implementation
template <typename T>
Station<T>::Station(T id) : stationID(id) {}

template <typename T>
void Station<T>::addLine(const std::string& line) {
    lines.push_back(line);
}

template <typename T>
T Station<T>::getStationID() const {
    return stationID;
}

template <typename T>
const std::vector<std::string>& Station<T>::getLines() const {
    return lines;
}

template <typename T>
void Station<T>::displayStationInfo() const {
    std::cout << "Station ID: " << stationID << "\nLines: ";
    for (const auto& line : lines) {
        std::cout << line << " ";
    }
    std::cout << std::endl;
}

// Platform class implementation
Platform::Platform(int id) : platformID(id) {}

int Platform::getPlatformID() const {
    return platformID;
}

bool Platform::isValidStoppageSlot(int time) const {
    for (int stoppage : stoppageTrains) {
        if (abs(stoppage - time) < 5) {
            return false;
        }
    }
    return true;
}

void Platform::bookSlot(int time, bool isThroughTrain) {
    if (!isThroughTrain) {
        if (!isValidStoppageSlot(time)) {
            throw std::runtime_error("Time slot not available for stoppage");
        }
        stoppageTrains.push_back(time);
    } else {
        throughTrains.push_back(time);
    }
}

void Platform::displayPlatformSchedule() const {
    std::cout << "Platform ID: " << platformID << "\nStoppage Trains: ";
    for (int time : stoppageTrains) {
        std::cout << time << " ";
    }
    std::cout << "\nThrough Trains: ";
    for (int time : throughTrains) {
        std::cout << time << " ";
    }
    std::cout << std::endl;
}

// Line class implementation
Line::Line(const std::string& name) : lineName(name) {}

void Line::addPlatform(int id) {
    platforms.emplace_back(id);
}

Platform& Line::getPlatform(int id) {
    for (auto& platform : platforms) {
        if (platform.getPlatformID() == id) {
            return platform;
        }
    }
    throw std::runtime_error("Platform not found");
}

std::string Line::getLineName() const {
    return lineName;
}

void Line::displayLineInfo() const {
    std::cout << "Line Name: " << lineName << "\nPlatforms: ";
    for (const auto& platform : platforms) {
        std::cout << platform.getPlatformID() << " ";
    }
    std::cout << std::endl;
}

// Explicit instantiation for template class Station
template class Station<int>;
template class Station<std::string>;
