#ifndef PROCESS_H
#define PROCESS_H

#include <string>

enum ProcessState {
    READY,
    RUNNING,
    TERMINATED,
    WAITING
};

struct ProcessControlBlock {
    int pid;
    std::string processName;
    int priority;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    ProcessState state;

    ProcessControlBlock(int p, std::string name, int pri, int at, int bt)
        : pid(p), processName(name), priority(pri), arrivalTime(at), burstTime(bt), remainingTime(bt), state(READY) {}
};

ProcessControlBlock createProcess(int pid, const std::string& name, int priority, int arrivalTime, int burstTime);
void displayProcessInfo(const ProcessControlBlock& pcb);
void terminateProcess(ProcessControlBlock& process);

#endif // PROCESS_H