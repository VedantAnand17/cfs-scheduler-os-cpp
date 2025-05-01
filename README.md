# CFS Scheduler Simulation

This project is a simulation of the **Completely Fair Scheduler (CFS)**, a process scheduling algorithm used in the Linux kernel. The simulation demonstrates how CFS manages CPU-bound and I/O-bound tasks by maintaining fairness and prioritizing tasks based on their `vruntime` and `weight`.

---

## Table of Contents
1. [Overview](#overview)
2. [Key Concepts](#key-concepts)
3. [Architecture](#architecture)
4. [Implementation Details](#implementation-details)
5. [Getting Started](#getting-started)
6. [Results](#results)
7. [References](#references)

## Overview

```mermaid
graph LR
    A[Task Input] --> B[CFS Scheduler]
    B --> C[CPU-bound Tasks]
    B --> D[I/O-bound Tasks]
    C --> E[Update vruntime]
    D --> F[I/O Wait + Penalty]
    E --> B
    F --> B
```

The **Completely Fair Scheduler (CFS)** provides fair CPU time distribution using virtual runtime (`vruntime`) metrics. Tasks with lower `vruntime` get priority, ensuring fair resource allocation.

## Key Concepts

### CFS Parameters
```mermaid
graph TD
    A[CFS Parameters] --> B[Weight]
    A --> C[vruntime]
    A --> D[Runqueue]
    B --> E["weight = NICE_0_LOAD / (priority + 1)"]
    C --> F["vruntime += (executed_time * NICE_0_LOAD) / weight"]
    D --> G[Priority Queue sorted by vruntime]
```

- **Weight**: Higher weight = Higher priority
  - `NICE_0_LOAD = 1024` (constant)
- **vruntime**: Virtual runtime metric
- **Runqueue**: Min-heap priority queue

## Architecture

```mermaid
flowchart TD
    A[Process Input] --> B[Scheduler]
    B --> C{Process Type}
    C -->|CPU-bound| D[Execute 1ms]
    C -->|I/O-bound| E[I/O Wait 10ms]
    D --> F[Update vruntime]
    E --> G[Apply Penalty]
    F --> H{cpu_burst_time > 0}
    G --> H
    H -->|Yes| B
    H -->|No| I[Terminate]
```

## Implementation Details

### CPU-Bound Task Flow
```mermaid
sequenceDiagram
    participant P as Process
    participant S as Scheduler
    participant Q as Runqueue
    
    P->>S: Request CPU time
    S->>P: Execute for 1ms
    P->>S: Update vruntime
    S->>Q: Requeue if not complete
```

### I/O-Bound Task Flow
```mermaid
sequenceDiagram
    participant P as Process
    participant S as Scheduler
    participant I as I/O Device
    participant Q as Runqueue
    
    P->>S: Request I/O
    S->>I: I/O Wait (10ms)
    I->>S: I/O Complete
    S->>P: Execute for 1ms
    P->>S: Update vruntime + penalty
    S->>Q: Requeue if not complete
```

## Getting Started

### Prerequisites
- C++ compiler (g++)
- Python 3.x with venv
- CMake
- Basic understanding of process scheduling

### Installation & Running
```bash
# Clone repository
git clone <repo-url>
cd cfs-scheduler-cpp

# Setup Python environment
python -m venv myvenv
source myvenv/bin/activate

# Build project
mkdir build && cd build
cmake ..
make

# Run simulation
./cfs-schedular
cd ..
python3 plot.py
```

## Results

### Process Scheduling Comparison

#### I/O-Bound Processes
- All processes have different vruntime and priorities
- I/O wait penalties affect scheduling frequency
- Higher priority tasks face larger penalties

![IO-Bound Process Schedule](https://github.com/user-attachments/assets/193d8a9d-fd70-4a32-8a82-d55c0cc1a287)

#### CPU-Bound Processes
- Process 1 (highest priority) completes fastest
- Lower vruntime + higher priority = more frequent scheduling
- No I/O wait penalties

![CPU-Bound Process Schedule](https://github.com/user-attachments/assets/d5f5367a-0a17-4ac6-9663-1b06e96e9677)

## References

1. [Linux CFS Documentation](https://www.kernel.org/doc/html/latest/scheduler/sched-design-CFS.html)
2. [Detailed Implementation Blog](https://singhdevhub.bearblog.dev/dissecting-linux-schedulers-implementing-our-toy-cfs_scheduler-simulation/)

---

For more details about the implementation, check out the source code in the repository.




