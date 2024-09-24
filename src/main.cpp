#include "process\process.h"
#include "scheduler\scheduler.h"
#include "memory\memory_manager.h"
#include "file_system\file_system.h"
#include "segmentation\segmentation.h"
#include <iostream>
#include <vector>

int main() {
    // Process Management Example
    std::vector<ProcessControlBlock> processes;

    // Creating processes
    processes.push_back(createProcess(1, "Process 1", 1, 0, 5));
    processes.push_back(createProcess(2, "Process 2", 2, 2, 3));
    processes.push_back(createProcess(3, "Process 3", 1, 4, 7));
    processes.push_back(createProcess(4, "Process 4", 3, 6, 2));
    processes.push_back(createProcess(5, "Process 5", 2, 3, 4));

    std::cout << "==================== Process Information ====================\n";
    for (const auto& process : processes) {
        displayProcessInfo(process);
    }

    // Scheduler Example: FCFS Scheduling
    std::cout << "\n==================== FCFS Scheduling ====================\n";
    fcfsScheduling(processes);

    // Reset process states for SJF scheduling
    for (auto& process : processes) {
        process.state = READY;
        process.remainingTime = process.burstTime; // Reset remaining time for each process
    }

    // Scheduler Example: SJF Scheduling
    std::cout << "\n==================== SJF Scheduling ====================\n";
    sjfScheduling(processes);

    // Reset process states for SRTF scheduling
    for (auto& process : processes) {
        process.state = READY;
        process.remainingTime = process.burstTime; // Reset remaining time for each process
    }

    // Scheduler Example: SRTF Scheduling
    std::cout << "\n==================== SRTF Scheduling ====================\n";
    srtfScheduling(processes);

    // Reset process states for Round Robin scheduling
    for (auto& process : processes) {
        process.state = READY;
        process.remainingTime = process.burstTime; // Reset remaining time for each process
    }

    // Scheduler Example: Round Robin Scheduling
    std::cout << "\n==================== Round Robin Scheduling ====================\n";
    roundRobinScheduling(processes, 2);  // Time Quantum = 2

    // Reset process states for Priority scheduling
    for (auto& process : processes) {
        process.state = READY;
        process.remainingTime = process.burstTime; // Reset remaining time for each process
    }

    // Scheduler Example: Priority Scheduling
    std::cout << "\n==================== Priority Scheduling ====================\n";
    priorityScheduling(processes);

    // Memory Management Example
    std::cout << "\n==================== Memory Management ====================\n";
    MemoryManager memoryManager(5);  // Create a memory manager with 5 frames
    
    memoryManager.allocatePage(1);  // Allocate page 1
    memoryManager.allocatePage(2);  // Allocate page 2
    memoryManager.displayMemoryStatus();  // Display memory status
    
    memoryManager.allocatePage(3);  // Allocate page 3
    memoryManager.allocatePage(4);  // Allocate page 4
    memoryManager.allocatePage(5);  // Allocate page 5
    memoryManager.allocatePage(6);  // This should trigger FIFO replacement
    memoryManager.displayMemoryStatus();  // Display updated memory status

    memoryManager.deallocatePage(3);  // Deallocate page 3
    memoryManager.displayMemoryStatus();  // Display memory status

    // Segmentation Example
    std::cout << "\n==================== Segmentation Management ====================\n";
    SegmentationManager segmentationManager(100);  // 100 units of memory

    segmentationManager.allocateSegment("Code", 30);
    segmentationManager.allocateSegment("Data", 20);
    segmentationManager.allocateSegment("Stack", 10);
    segmentationManager.displaySegments();

    segmentationManager.deallocateSegment("Data");
    segmentationManager.displaySegments();

    // File System Example
    std::cout << "\n==================== File System ====================\n";
    FileSystem fileSystem;
    fileSystem.createFile("test.txt");
    fileSystem.writeFile("test.txt", "This is some sample data.");
    std::cout << "File Contents: " << fileSystem.readFile("test.txt") << "\n";
    fileSystem.deleteFile("test.txt");
    fileSystem.displayFiles(); // Should show no files
    return 0;
}