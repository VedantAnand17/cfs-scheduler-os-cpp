#include <iostream>
#include "src/processService.hpp"
#include <vector>
#include "src/processLog.hpp"
#include "src/cfs.hpp"
#include <fstream>

int main(int argv, char* argc[]){
    std::vector<Process*> processes = getProcessFromJson("resources/process.json");
    cfs scheduler; // Create an instance of cfs
    std::vector<ProcessLog*> logs = scheduler.schedule(processes);
    for(auto processLog: logs){
        std::cout<<processLog->pid<<" "<<processLog->startTime<<" "<<processLog->endTime<<std::endl;
    }
    return 0;
}