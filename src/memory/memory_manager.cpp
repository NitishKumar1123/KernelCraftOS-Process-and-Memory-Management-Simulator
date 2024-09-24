#include "memory_manager.h"
#include <iostream>
#include <algorithm>

MemoryManager::MemoryManager(int numFrames) : maxFrames(numFrames), memoryFrames(numFrames, -1) {}

int MemoryManager::allocatePage(int pageNumber) {
    if (pageFrameMap.find(pageNumber) != pageFrameMap.end()) {
        std::cout << "Page " << pageNumber << " is already in memory.\n";
        return pageFrameMap[pageNumber];
    }
    
    for (int i = 0; i < maxFrames; ++i) {
        if (memoryFrames[i] == -1) {
            memoryFrames[i] = pageNumber;
            PageTableEntry newEntry = { pageNumber, i, true };
            pageTable.push_back(newEntry);
            pageFrameMap[pageNumber] = i;
            pageAccessOrder.push_back(pageNumber);
            std::cout << "Page " << pageNumber << " allocated at frame " << i << "\n";
            return i;
        }
    }
    
    std::cerr << "No free frames available for page " << pageNumber << ". Trying FIFO replacement...\n";
    pageReplacementFIFO(pageNumber);
    return -1;
}

void MemoryManager::deallocatePage(int pageNumber) {
    auto it = pageFrameMap.find(pageNumber);
    if (it != pageFrameMap.end()) {
        int frameIndex = it->second;
        memoryFrames[frameIndex] = -1;
        pageFrameMap.erase(it);
        std::cout << "Page " << pageNumber << " deallocated from frame " << frameIndex << "\n";
    } else {
        std::cerr << "Page " << pageNumber << " not found in memory\n";
    }
}

void MemoryManager::displayMemoryStatus() {
    std::cout << "Memory Status:\n";
    for (int i = 0; i < memoryFrames.size(); ++i) {
        if (memoryFrames[i] != -1) {
            std::cout << "Frame " << i << ": Page " << memoryFrames[i] << "\n";
        } else {
            std::cout << "Frame " << i << ": Empty\n";
        }
    }
}

void MemoryManager::pageReplacementFIFO(int pageNumber) {
    int frameIndex = pageAccessOrder.front();
    deallocatePage(memoryFrames[frameIndex]); // Remove oldest page
    allocatePage(pageNumber);
}

void MemoryManager::pageReplacementLRU(int pageNumber) {
    // Remove least recently used page
    auto it = std::find_if(pageAccessOrder.begin(), pageAccessOrder.end(), 
                            [&](int page) { return pageFrameMap.find(page) != pageFrameMap.end(); });
    if (it != pageAccessOrder.end()) {
        deallocatePage(*it);
    }
    allocatePage(pageNumber);
}