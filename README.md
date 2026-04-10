# Multi-Task-Orchestrator-QNX
## Real-Time Sensor Fusion and Adaptive Display using QNX RTOS on Raspberry Pi 4

### 1. Abstarct

Modern embedded systems require efficient coordination of **multiple sensors** and processing units to achieve reliable real-time performance. However, managing multiple dependent tasks while maintaining synchronization and timing constraints remains a critical challenge.<br>

In response to this, our project presents a multi-task orchestrator implemented on QNX RTOS, designed to coordinate sensor acquisition, data processing, analytics, and display tasks on a Raspberry Pi 4 platform. The system integrates environmental sensors such as Sense HAT and optional DHT22 to collect real-time data and generate responsive outputs through LED-based displays.<br>

The proposed system ensures **deterministic execution, low latency, and data consistency** by leveraging priority-based scheduling, inter-task communication, and dependency-aware execution pipelines, thereby demonstrating behavior similar to industrial real-time embedded systems.<br>

### 2. Problem Statement

There exists a significant challenge in embedded systems when dealing with multiple sensors and dependent processing stages. Most systems lack proper coordination mechanisms, leading to inefficiencies and unreliable outputs.<br>

Key issues include:<br>

1.Inability to handle multiple sensor inputs simultaneously<br>
2.Lack of real-time execution guarantees<br>
3.Data inconsistency between processing stages<br>
4.Occurrence of race conditions and timing delays<br>
<br>
Most existing implementations process tasks independently, which results in:<br>

1.Data mismatch across system modules<br>
2.Unpredictable execution timing<br>
3.Poor synchronization between tasks<br>
4.Reduced overall system performance<br>

### 3. Objective

The objective of this project is to design and implement a centralized orchestration system that:<br>

Coordinates sensor, processing, analytics, and display tasks<br>
Maintains strict real-time deadlines using RTOS scheduling<br>
Ensures correct execution order based on task dependencies<br>
Optimizes CPU utilization and system responsiveness<br>

### 4. System Architecture<br>
**Hardware**<br>
Raspberry Pi 4<br>
BMP280 (temperature, humidity, pressure)<br>
TTL to USB Converter<br>

**Software**<br>
QNX Neutrino RTOS<br>
POSIX Threads (pthreads)<br>
Inter-Process Communication (IPC)<br>

### 5. Task Orchestration Model<br>

The system follows a structured dependency-based execution flow:<br>

**Sensor Task → Processing Task → Analytics Task → Display Task**

Each task operates as follows:<br>

1.Execution starts only after required input is available<br>
2.Communication is achieved using message queues or shared memory<br>
3.Scheduling is controlled by RTOS priority mechanisms<br>

### 6. Task Breakdown
**Sensor Task**<br>
~Periodically reads environmental data<br>
~Operates at fixed intervals (e.g., 1 second)<br>
**Processing Task**<br>
~Filters noise from raw sensor data<br>
~Converts raw data into meaningful values<br>
**Analytics Task**<br>
~Performs condition monitoring<br>
~Detects anomalies such as threshold violations<br>
**Display Task**<br>
~Updates LED matrix or external LED strip<br>
~Provides real-time visual feedback<br>

### 7. Key Features<br>
**Dependency-Aware Scheduling**<br>

Tasks are executed only when the output of the previous task is available, ensuring proper sequencing and data integrity.<br>

**Real-Time Performance**<br>

The system uses priority-based scheduling to ensure deterministic execution with bounded latency.<br>

**Synchronization Mechanisms**<br>
Mutexes<br>
Semaphores<br>
Message queues<br>

These mechanisms ensure safe and efficient communication between tasks.<br>

**Fault Isolation**<br>

The system is designed such that failure of one task does not disrupt the entire system, improving reliability.<br>

### 8. Workflow

[Sensor Acquisition]<br>
         ↓<br>
[Data Processing]<br>
         ↓<br>
[Analytics Engine]<br>
         ↓<br>
[Display Output]<br>

### 9. Results
Real-time sensor monitoring<br>
Consistent and synchronized data processing<br>
Smooth and responsive display output<br>
Deterministic system behavior<br>

### 10. Applications
Environmental monitoring systems<br>
Industrial automation<br>
Autonomous embedded systems<br>
IoT-based real-time dashboards<br>

### 11. Conclusion & Acknowledgement

This project demonstrates an efficient and scalable approach to managing multiple dependent tasks in a real-time embedded system using QNX RTOS. The implementation highlights the importance of task orchestration, synchronization, and deterministic scheduling in achieving reliable system performance.<br>

The project serves as a foundation for further enhancements such as intelligent analytics, cloud integration, and distributed real-time systems.<br>
