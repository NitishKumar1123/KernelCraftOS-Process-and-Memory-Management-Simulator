#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <vector>
#include <string>
#include <iostream>

struct Segment {
    std::string name;
    int size;
    int base; // Starting address in memory
};

class SegmentationManager {
public:
    SegmentationManager(int totalMemory);
    void allocateSegment(const std::string& name, int size);
    void deallocateSegment(const std::string& name);
    void displaySegments();

private:
    std::vector<Segment> segments;
    int totalMemory;
    int usedMemory;
};

#endif // SEGMENTATION_H
