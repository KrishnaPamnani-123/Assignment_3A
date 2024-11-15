#include "IndianRailwaysLibrary.h"
#include <cassert>
#include <limits>

// Helper function for input validation
bool isInteger(const std::string& str) {
    return !str.empty() && str.find_first_not_of("0123456789") == std::string::npos;
}

// Main function
void scheduleTrains(Line& line) {
    int numTrains;
    std::cout << "Enter number of trains to schedule for this line: ";
    std::cin >> numTrains;

    assert(numTrains > 0 && "Number of trains must be positive.");

    for (int i = 0; i < numTrains; ++i) {
        int trainID, isThroughTrain;
        std::string scheduledTimeStr;

        std::cout << "Enter Train " << i + 1 << " ID: ";
        std::cin >> trainID;

        std::cout << "Is the train a through train? (1 for yes, 0 for no): ";
        std::cin >> isThroughTrain;

        bool scheduled = false;
        while (!scheduled) {
            std::cout << "Enter the scheduled time for the train (HH:MM): ";
            std::cin >> scheduledTimeStr;

            try {
                int scheduledTime = timeToMinutes(scheduledTimeStr);
                Platform& platform = line.getPlatform(1); // Assuming one platform per line
                platform.bookSlot(scheduledTime, isThroughTrain);
                std::cout << "Train " << trainID << " scheduled successfully on line " 
                          << line.getLineName() << " at " << scheduledTimeStr << ".\n";
                scheduled = true;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }
        }
    }
}

int main() {
    try {
        std::string stationIDInput;
        std::cout << "Enter Station ID (int or string): ";
        std::cin >> stationIDInput;

        if (isInteger(stationIDInput)) {
            // Station ID is integer
            int stationID = std::stoi(stationIDInput);
            Station<int> station(stationID);
            std::cout << "Station created with ID: " << stationID << "\n";
        } else {
            // Station ID is string
            Station<std::string> station(stationIDInput);
            std::cout << "Station created with ID: " << stationIDInput << "\n";
        }

        int numLines;
        std::cout << "Enter the number of lines: ";
        std::cin >> numLines;

        if (numLines <= 0) {
            throw std::invalid_argument("Number of lines must be positive.");
        }

        std::vector<Line> lines;
        for (int i = 0; i < numLines; ++i) {
            std::string lineName = "Line " + std::to_string(i + 1);
            Line line(lineName);

            line.addPlatform(1); // Adding a single platform per line

            std::cout << "Scheduling trains for " << lineName << ":\n";
            scheduleTrains(line);

            lines.push_back(line);
        }

        std::cout << "All scheduling completed successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Critical Error: " << e.what() << "\n";
    }

    return 0;
}
