#ifndef INDIAN_RAILWAYS_LIBRARY_H
#define INDIAN_RAILWAYS_LIBRARY_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// Helper function to convert HH:MM to minutes
int timeToMinutes(const std::string& time);

// Template class for Station ID (can be int or string)
template <typename T>
class Station {
private:
    T stationID;
    std::vector<std::string> lines;

public:
    explicit Station(T id);
    void addLine(const std::string& line);
    T getStationID() const;
    const std::vector<std::string>& getLines() const;
    void displayStationInfo() const;
};

// Platform class
class Platform {
private:
    int platformID;
    std::vector<int> stoppageTrains; // Minutes since midnight for stoppage trains
    std::vector<int> throughTrains;  // Minutes since midnight for through trains

    bool isValidStoppageSlot(int time) const;

public:
    explicit Platform(int id);
    int getPlatformID() const;
    void bookSlot(int time, bool isThroughTrain);
    void displayPlatformSchedule() const;
};

// Line class
class Line {
private:
    std::string lineName;
    std::vector<Platform> platforms;

public:
    explicit Line(const std::string& name);
    void addPlatform(int id);
    Platform& getPlatform(int id);
    std::string getLineName() const;
    void displayLineInfo() const;
};

#endif // INDIAN_RAILWAYS_LIBRARY_H
