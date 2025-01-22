#include "processService.hpp"
#include "queueService.hpp"
#include <memory>
#include <iostream>
#include "cpuBoundProcessExecution.hpp"

double weightFunction(int priority) {
    return (priority + 1);
}

void executeCpuBoundProcess(Process* process, int timeSlice, QueueService q) {
    int executedInstructions = 0;
    const int maxInstructions = timeSlice * CPU_INSTRUCTIONS_IN_MS;

    while (executedInstructions < maxInstructions && process -> cpu_burst_time > 0) {
        executedInstructions++;
        process -> cpu_burst_time--; // Decrease burst time
    }
    process -> vruntime += executedInstructions * weightFunction(process -> priority);
    if (process -> cpu_burst_time > 0) {
        q.push_element(process);
    }
}
