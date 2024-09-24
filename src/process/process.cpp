#include "process.h"
#include <iostream>

ProcessControlBlock createProcess(int pid, std::string name, int priority, int arrivalTime, int burstTime) {
    ProcessControlBlock process(pid, name, priority, arrivalTime, burstTime);
    return process;
}

void terminateProcess(ProcessControlBlock& process) {
    process.state = TERMINATED;
    std::cout << "Process " << process.processName << " (PID: " << process.pid << ") has been terminated.\n";
}

void displayProcessInfo(const ProcessControlBlock& process) {
    std::cout << "Process ID: " << process.pid << "\n";
    std::cout << "Process Name: " << process.processName << "\n";
    std::cout << "Priority: " << process.priority << "\n";
    std::cout << "Arrival Time: " << process.arrivalTime << "\n";
    std::cout << "Burst Time: " << process.burstTime << "\n";
    std::cout << "Remaining Time: " << process.remainingTime << "\n";
    std::cout << "State: " << process.state << "\n";
}