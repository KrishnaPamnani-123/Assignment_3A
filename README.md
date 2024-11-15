# Indian Railways Library

## Overview
The **Indian Railways Library** is a C++ project designed to simulate the scheduling and management of railway stations, lines, and platforms. It provides an object-oriented approach to managing train scheduling, resolving conflicts, and displaying platform schedules. The library is reusable and designed to handle real-world constraints like scheduling conflicts.

---

## Features

1. **Station Management**:
   - Template-based `Station` class to support station IDs of multiple data types (`int`, `string`).
   - Tracks the lines connected to a station.

2. **Platform Scheduling**:
   - Manages train schedules for both stoppage and through trains.
   - Ensures no overlapping time slots for stoppage trains.
   - Displays the complete schedule for a platform.

3. **Train Line Management**:
   - Supports adding platforms to a line.
   - Allows scheduling trains on a specific platform.

4. **Utilities**:
   - `time To Minutes`: Converts time in `HH:MM` format to minutes since midnight, enabling efficient time computations.

---

## File Structure

### Source Files

- **`IndianRailwaysLibrary.h`**: Contains the declarations of `Station`, `Platform`, and `Line` classes along with utility functions.
- **`IndianRailwaysLibrary.cpp`**: Implements non-template class methods and utility functions.
- **`main.cpp`**: Driver program demonstrating the library's usage.

### Makefile

Automates the build process with targets for static libraries, debugging, and optimization.

---

## Compilation and Execution

### Prerequisites
- **C++ Compiler**: GCC or any compiler with C++11 or later support.
- **Make Utility**: To use the provided Makefile.

## Program Usage

### Interaction
The program prompts the user to:
1. Enter the station ID.
2. Add train lines.
3. Schedule trains by specifying:
   - Train type (stoppage or through).
   - Scheduled time in `HH:MM` format.

### Example

#### Input
```
Enter Station ID (int): 123
Enter the number of lines: 1
Scheduling trains for Line 1:
Enter number of trains to schedule for this line: 2
Enter Train 1 ID: 101
Is the train a through train? (1 for yes, 0 for no): 0
Enter the scheduled time for the train (HH:MM): 08:30
Enter Train 2 ID: 102
Is the train a through train? (1 for yes, 0 for no): 1
Enter the scheduled time for the train (HH:MM): 09:15
```

#### Output
```
Train 101 scheduled successfully on line Line 1 at 08:30.
Train 102 scheduled successfully on line Line 1 at 09:15.
All scheduling completed successfully.
```

---

## Error Handling

- **Invalid Input**: Input like `25:00` or malformed time strings results in error messages.
- **Schedule Conflicts**: Attempts to book overlapping stoppage slots throw an exception.
- **Platform Not Found**: Requests for invalid platforms raise runtime exceptions.

---

## Makefile Targets

- **`all`**: Builds the static library and all executables.
- **`static_lib`**: Compiles `IndianRailwaysLibrary.a`.
- **`debug`**: Builds the main program with debugging symbols.
- **`optimize`**: Builds the main program with optimization flags.

---



