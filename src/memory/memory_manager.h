#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <vector>
#include <unordered_map>

struct PageTableEntry {
    int pageNumber;
    int frameNumber;
    bool valid;
};

class MemoryManager {
public:
    MemoryManager(int numFrames);
    int allocatePage(int pageNumber);
    void deallocatePage(int pageNumber);
    void displayMemoryStatus();
    void pageReplacementFIFO(int pageNumber);
    void pageReplacementLRU(int pageNumber);
    
private:
    std::vector<int> memoryFrames;
    std::vector<PageTableEntry> pageTable;
    std::unordered_map<int, int> pageFrameMap;  // Maps page number to frame index
    std::vector<int> pageAccessOrder; // For LRU
    int maxFrames;
};

#endif // MEMORY_MANAGER_H