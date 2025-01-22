#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <queue>
#include <vector>
#include "processService.hpp"
#include <memory>
#include "queueService.hpp"

class Comparator {
    public:
        bool operator()(Process* p1, Process* p2) {
            return p1->vruntime > p2->vruntime; // Smaller vruntime = higher priority
        }
};

class QueueService {
    private:
        std::priority_queue<Process*, std::vector<Process*>, Comparator> q;

    public:
        QueueService();

        void push_element(Process* p);
        void pop_element();
        bool is_empty();
        Process* top_element();
};

#endif // QUEUE_HPP
