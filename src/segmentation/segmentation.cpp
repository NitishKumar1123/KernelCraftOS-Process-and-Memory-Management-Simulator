#include "segmentation.h"
#include "../../../../../../MinGW/lib/gcc/mingw32/6.3.0/include/c++/bits/algorithmfwd.h"

SegmentationManager::SegmentationManager(int totalMem) : totalMemory(totalMem), usedMemory(0) {}

void SegmentationManager::allocateSegment(const std::string& name, int size) {
    if (usedMemory + size > totalMemory) {
        std::cerr << "Not enough memory to allocate segment " << name << "\n";
        return;
    }
    segments.push_back({ name, size, usedMemory });
    usedMemory += size;
    std::cout << "Segment " << name << " allocated at base " << (usedMemory - size) << " of size " << size << "\n";
}

void SegmentationManager::deallocateSegment(const std::string& name) {
    auto it = std::find_if(segments.begin(), segments.end(), [&](const Segment& seg) { return seg.name == name; });
    if (it != segments.end()) {
        usedMemory -= it->size;
        segments.erase(it);
        std::cout << "Segment " << name << " deallocated.\n";
    } else {
        std::cerr << "Segment " << name << " not found.\n";
    }
}

void SegmentationManager::displaySegments() {
    std::cout << "Segments:\n";
    for (const auto& segment : segments) {
        std::cout << "Name: " << segment.name << ", Size: " << segment.size << ", Base: " << segment.base << "\n";
    }
}
