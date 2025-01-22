#include "processService.hpp"
#include "ioBoundProcessExecution.hpp"
#include <iostream>
#include <thread>
#include <time.h>
#include "cpuBoundProcessExecution.hpp"

void handleIoBoundProcess(Process* process, int ioWaitTime, QueueService q) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ioWaitTime));

    process->vruntime += ioWaitTime * weightFunction(process->priority);

    q.push_element(process);
}