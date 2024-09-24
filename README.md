## OS Simulator Project
Overview
The OS Simulator is a C++ project designed to simulate core functionalities of an Operating System. It includes features such as process management, CPU scheduling, memory management (paging and segmentation), and a basic file system. The simulator is a great educational tool for understanding how operating systems manage resources and processes.

## Table of Contents
Features
Installation
Usage
Directory Structure
Future Enhancements
License
Features
# 1. Process Management
Simulates process lifecycle (READY, RUNNING, WAITING, TERMINATED).
Supports operations like creating and terminating processes.
# 2. CPU Scheduling Algorithms
First Come, First Serve (FCFS)
Shortest Job First (SJF)
Shortest Remaining Time First (SRTF)
Round Robin (RR)
Priority Scheduling
# 3. Memory Management
Implements paging with FIFO/LRU page replacement.
Displays current memory allocation and page states.
# 4. Segmentation
Simulates segmentation where memory is divided into logical segments like Code, Data, etc.
# 5. File System
Supports basic file operations like creating, reading, writing, and deleting files.
Installation
Prerequisites
C++ Compiler (GCC/Clang/MinGW/MSVC)
Make (for building the project using the provided Makefile)
Steps
# Clone the repository:

git clone https://github.com/yourusername/os_simulator.git
cd os_simulator
Compile the project using the Makefile:

Run the executable:

bash
Copy code
./os_simulator
Usage
Running the Simulator
After building the project, run the os_simulator executable. The simulator will ask for various inputs based on the feature you are simulating (process scheduling, memory management, etc.).

# Example Simulation
To run an example simulation:

Process Scheduling: You can input multiple processes with different arrival times, burst times, and priorities. Then, choose from the available scheduling algorithms (FCFS, SJF, Round Robin, etc.) to simulate the process scheduling.

Memory Management: Allocate pages for different processes and see how paging is managed. Simulate memory being full and triggering page replacement using FIFO.

File System: Create files, write data to files, read from files, and delete files.

# Directory Structure

OS_Simulator/
├── src/
│   ├── main.cpp                # Main program file
│   ├── process/
│   │   ├── process.h           # Header for process management
│   │   ├── process.cpp         # Implementation of process management
│   ├── scheduler/
│   │   ├── scheduler.h         # Header for scheduling algorithms
│   │   ├── scheduler.cpp       # Implementation of scheduling algorithms
│   ├── memory/
│   │   ├── memory_manager.h    # Header for memory management
│   │   ├── memory_manager.cpp  # Implementation of memory management
│   ├── segmentation/
│   │   ├── segmentation.h      # Header for segmentation
│   │   ├── segmentation.cpp    # Implementation of segmentation
│   ├── file_system/
│   │   ├── file_system.h       # Header for file system operations
│   │   ├── file_system.cpp     # Implementation of file system
├── tests/                      # Unit tests for different components
├── include/                    # Shared headers
├── docs/                       # Documentation files
├── Makefile                    # Build script
└── README.md                   # This README file


# Future Enhancements
Here are some improvements and additional features planned for future versions:

Multi-threading Support: Add real multi-threading with synchronization mechanisms like semaphores and mutexes.
Memory Management Enhancements: Implement other page replacement algorithms (Optimal etc..) and simulate virtual memory.
Process Synchronization: Introduce inter-process communication (IPC) and synchronization using semaphores and condition variables.
I/O Operations: Simulate I/O-bound processes and device interaction.
Advanced File System: Implement directory structures and more complex file operations.
Graphical User Interface: Create a GUI for better user interaction and process visualization.
License
This project is licensed under the MIT License. See the LICENSE file for details.
