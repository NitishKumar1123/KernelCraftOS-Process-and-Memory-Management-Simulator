#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "..\process\process.h"
#include <vector>

void fcfsScheduling(std::vector<ProcessControlBlock>& processes);
void sjfScheduling(std::vector<ProcessControlBlock>& processes);
void srtfScheduling(std::vector<ProcessControlBlock>& processes);
void roundRobinScheduling(std::vector<ProcessControlBlock>& processes, int timeQuantum);
void priorityScheduling(std::vector<ProcessControlBlock>& processes);

#endif // SCHEDULER_H