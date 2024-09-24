#include "scheduler.h"
#include <iostream>
#include <algorithm>
#include <queue>

// Utility comparison functions
bool compareArrival(const ProcessControlBlock& p1, const ProcessControlBlock& p2) {
    return p1.arrivalTime < p2.arrivalTime;
}

bool compareBurst(const ProcessControlBlock& p1, const ProcessControlBlock& p2) {
    return p1.burstTime < p2.burstTime;
}

bool comparePriority(const ProcessControlBlock& p1, const ProcessControlBlock& p2) {
    return p1.priority < p2.priority;
}

// First Come First Serve (FCFS)
void fcfsScheduling(std::vector<ProcessControlBlock>& processes) {
    std::sort(processes.begin(), processes.end(), compareArrival);
    int currentTime = 0;

    for (auto& process : processes) {
        if (currentTime < process.arrivalTime)
            currentTime = process.arrivalTime;
        
        process.state = RUNNING;
        std::cout << "Process " << process.processName << " is running at time " << currentTime << "\n";
        currentTime += process.burstTime;
        process.state = TERMINATED;
        std::cout << "Process " << process.processName << " terminated at time " << currentTime << "\n";
    }
}

// Shortest Job First (SJF)
void sjfScheduling(std::vector<ProcessControlBlock>& processes) {
    std::sort(processes.begin(), processes.end(), compareBurst);
    int currentTime = 0;

    for (auto& process : processes) {
        if (currentTime < process.arrivalTime)
            currentTime = process.arrivalTime;

        process.state = RUNNING;
        std::cout << "Process " << process.processName << " is running at time " << currentTime << "\n";
        currentTime += process.burstTime;
        process.state = TERMINATED;
        std::cout << "Process " << process.processName << " terminated at time " << currentTime << "\n";
    }
}

// Shortest Remaining Time First (SRTF)
void srtfScheduling(std::vector<ProcessControlBlock>& processes) {
    std::priority_queue<ProcessControlBlock*, std::vector<ProcessControlBlock*>, decltype(&compareBurst)> pq(compareBurst);
    int currentTime = 0;

    while (!processes.empty() || !pq.empty()) {
        // Add processes to the queue that have arrived
        for (auto it = processes.begin(); it != processes.end();) {
            if (it->arrivalTime <= currentTime) {
                pq.push(&(*it));
                it = processes.erase(it);
            } else {
                ++it;
            }
        }

        // Process the current task
        if (!pq.empty()) {
            auto currentProcess = pq.top();
            pq.pop();

            currentProcess->state = RUNNING;
            std::cout << "Process " << currentProcess->processName << " is running at time " << currentTime << "\n";

            int execTime = std::min(currentProcess->remainingTime, pq.empty() ? currentProcess->remainingTime : processes[0].arrivalTime - currentTime);
            currentProcess->remainingTime -= execTime;
            currentTime += execTime;

            if (currentProcess->remainingTime > 0) {
                pq.push(currentProcess);
            } else {
                currentProcess->state = TERMINATED;
                std::cout << "Process " << currentProcess->processName << " terminated at time " << currentTime << "\n";
            }
        } else {
            currentTime++;
        }
    }
}

// Round Robin (RR)
void roundRobinScheduling(std::vector<ProcessControlBlock>& processes, int timeQuantum) {
    std::queue<ProcessControlBlock*> processQueue;
    int currentTime = 0;

    for (auto& process : processes) {
        if (process.arrivalTime <= currentTime) {
            processQueue.push(&process);
        }
    }

    while (!processQueue.empty()) {
        auto* process = processQueue.front();
        processQueue.pop();

        process->state = RUNNING;
        int execTime = std::min(timeQuantum, process->remainingTime);
        std::cout << "Process " << process->processName << " is running at time " << currentTime << " for " << execTime << " units\n";

        process->remainingTime -= execTime;
        currentTime += execTime;

        if (process->remainingTime > 0) {
            processQueue.push(process);
        } else {
            process->state = TERMINATED;
            std::cout << "Process " << process->processName << " terminated at time " << currentTime << "\n";
        }
    }
}

// Priority Scheduling
void priorityScheduling(std::vector<ProcessControlBlock>& processes) {
    std::sort(processes.begin(), processes.end(), comparePriority);
    int currentTime = 0;

    for (auto& process : processes) {
        if (currentTime < process.arrivalTime)
            currentTime = process.arrivalTime;

        process.state = RUNNING;
        std::cout << "Process " << process.processName << " is running at time " << currentTime << "\n";
        currentTime += process.burstTime;
        process.state = TERMINATED;
        std::cout << "Process " << process.processName << " terminated at time " << currentTime << "\n";
    }
}