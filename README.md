# Multi-Task-Orchestrator-QNX
## Real-Time Sensor Fusion and Adaptive Display using QNX RTOS on Raspberry Pi 4

### Table of Contents:
#### 1. Summary

Modern embedded systems require efficient coordination of **multiple sensors** and processing units to achieve reliable real-time performance. However, managing multiple dependent tasks while maintaining synchronization and timing constraints remains a critical challenge.

In response to this, our project presents a multi-task orchestrator implemented on QNX RTOS, designed to coordinate sensor acquisition, data processing, analytics, and display tasks on a Raspberry Pi 4 platform. The system integrates environmental sensors such as Sense HAT and optional DHT22 to collect real-time data and generate responsive outputs through LED-based displays.

The proposed system ensures **deterministic execution, low latency, and data consistency** by leveraging priority-based scheduling, inter-task communication, and dependency-aware execution pipelines, thereby demonstrating behavior similar to industrial real-time embedded systems.

#### 2. Problem Statement

There exists a significant challenge in embedded systems when dealing with multiple sensors and dependent processing stages. Most systems lack proper coordination mechanisms, leading to inefficiencies and unreliable outputs.

Key issues include:

*Inability to handle multiple sensor inputs simultaneously
*Lack of real-time execution guarantees
*Data inconsistency between processing stages
*Occurrence of race conditions and timing delays

Most existing implementations process tasks independently, which results in:

*Data mismatch across system modules
*Unpredictable execution timing
*Poor synchronization between tasks
*Reduced overall system performance

#### 3. Objective

The objective of this project is to design and implement a centralized orchestration system that:

Coordinates sensor, processing, analytics, and display tasks
Maintains strict real-time deadlines using RTOS scheduling
Ensures correct execution order based on task dependencies
Optimizes CPU utilization and system responsiveness

#### 4. System Architecture
**Hardware**
Raspberry Pi 4
BMP280 (temperature, humidity, pressure)
TTL to USB Converter

**Software**
QNX Neutrino RTOS
POSIX Threads (pthreads)
Inter-Process Communication (IPC)

#### 5. Task Orchestration Model

The system follows a structured dependency-based execution flow:

**Sensor Task → Processing Task → Analytics Task → Display Task**

Each task operates as follows:

1.Execution starts only after required input is available
2.Communication is achieved using message queues or shared memory
3.Scheduling is controlled by RTOS priority mechanisms

#### 6. Task Breakdown
**Sensor Task**
~Periodically reads environmental data
~Operates at fixed intervals (e.g., 1 second)
**Processing Task**
~Filters noise from raw sensor data
~Converts raw data into meaningful values
**Analytics Task**
~Performs condition monitoring
~Detects anomalies such as threshold violations
**Display Task**
~Updates LED matrix or external LED strip
~Provides real-time visual feedback

#### 7. Key Features
**Dependency-Aware Scheduling**

Tasks are executed only when the output of the previous task is available, ensuring proper sequencing and data integrity.

**Real-Time Performance**

The system uses priority-based scheduling to ensure deterministic execution with bounded latency.

**Synchronization Mechanisms**
Mutexes
Semaphores
Message queues

These mechanisms ensure safe and efficient communication between tasks.

**Fault Isolation**

The system is designed such that failure of one task does not disrupt the entire system, improving reliability.

#### 8. Workflow

[Sensor Acquisition]
↓
[Data Processing]
↓
[Analytics Engine]
↓
[Display Output]

#### 9. Results
Real-time sensor monitoring
Consistent and synchronized data processing
Smooth and responsive display output
Deterministic system behavior

#### 10. Applications
Environmental monitoring systems
Industrial automation
Autonomous embedded systems
IoT-based real-time dashboards

#### 11. Conclusion & Acknowledgement

This project demonstrates an efficient and scalable approach to managing multiple dependent tasks in a real-time embedded system using QNX RTOS. The implementation highlights the importance of task orchestration, synchronization, and deterministic scheduling in achieving reliable system performance.

The project serves as a foundation for further enhancements such as intelligent analytics, cloud integration, and distributed real-time systems.
