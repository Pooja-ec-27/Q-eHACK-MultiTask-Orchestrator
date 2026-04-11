# Multi-Task-Orchestrator-QNX
## Real-Time Sensor Fusion and Adaptive Display using QNX RTOS on Raspberry Pi 4
## Team: Neutrino Knights / Pushpa M , Kavya G , Pooja K N

### 1. Abstarct

Modern embedded systems require efficient coordination of **multiple sensors** and processing units to achieve reliable real-time performance. However, managing multiple dependent tasks while maintaining synchronization and timing constraints remains a critical challenge.<br>

In response to this, our project presents a multi-task orchestrator implemented on QNX RTOS, designed to coordinate sensor acquisition, data processing, analytics, and display tasks on a Raspberry Pi 4 platform. The system integrates environmental sensors such as Sense Hat (BMP280) and helps in visualising the system analytics.

The proposed system ensures **deterministic execution, low latency, and reliability** by leveraging priority-based scheduling, inter-process communication, event based execution thereby demonstrating behavior similar to industrial real-time embedded systems.<br>

### 2. Problem Statement  (33: Multitasking Orchestrator for Sensor display) \
In mission-critical Smart Mining environments, the lack of task synchronization in embedded systems poses severe safety risks. Current decentralized architectures fail to handle high-frequency data fusion from heterogeneous sensors (Gas, Vibration, Thermal), leading to:

 <b>Temporal Inconsistency </b> : High-priority gas alerts are often delayed by low-priority logging tasks due to lack of preemption.

 <b>Data Stale-ness </b>: Asynchronous sensor rates cause processing stages to operate on "mismatched" data packets.

**Race Conditions**: Undeterministic execution timing leads to system deadlocks or missed deadlines during emergency triggers.

**Resource Inefficiency**: Suboptimal CPU scheduling causes high power consumption and reduced system responsiveness in volatile underground conditions.

### 3. Objective
3. Project Objectives
The core goal is to develop a Centralized Orchestration Layer for mining-specific embedded nodes to ensure deterministic performance and safety. <br>
<br>
###  System Design Objectives & Technical Strategy

| **Objective**           | **Technical Strategy**                                                                 |
|------------------------|----------------------------------------------------------------------------------------|
| **Task Coordination**  | Orchestrate concurrent sensor acquisition, edge analytics, and HMI display tasks.     |
| **Real-Time Determinism** | Implement RTOS preemptive scheduling to guarantee strict execution deadlines.        |
| **Data Integrity**     | Enforce dependency-based execution (Acquire → Analyze → Act) to eliminate logic errors.|
| **System Optimization**| Utilize event-driven semaphores and queues to maximize CPU utilization and minimize latency. |

### 4. System Architecture<br>
**Hardware**<br>
Raspberry Pi 4<br>
BMP280 (temperature, humidity, pressure)<br>
TTL to USB Converter<br>

**Software**<br>
QNX Neutrino RTOS<br>
PuTTY <br>
Quick Start Image for RasberryPi4 <br>

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

Deterministic Scheduling: Priority-based preemptive execution ensuring safety-critical tasks (Gas/Fire alerts) meet hard real-time deadlines ($<10ms$ latency). \
Logical Task Sequencing: Dependency-aware logic prevents "stale" data processing by ensuring Acquisition → Analytics integrity. \
ITC Synchronization: Robust Inter-Task Communication using Mutexes for resource locking and Message Queues for asynchronous telemetry.
Fault Isolation: Decoupled task architecture to ensure localized faults do not compromise the core system heartbeat. \\

### 8. Workflow

<img width="587" height="443" alt="image" src="https://github.com/user-attachments/assets/6738ade1-afb3-4368-9f55-ffafd79f449e" />
\\

### 9. Results
Deterministic Latency: Achieved hard real-time performance with sub-millisecond task switching and guaranteed execution windows.\
Data Coherency: Eliminated data mismatch across processing stages through synchronized dependency-aware scheduling.\
High Responsiveness: Maintained a smooth 60Hz HMI refresh rate even under peak CPU load during multi-sensor interrupts\
Resource Efficiency: Optimized CPU idle cycles and memory footprint through event-driven semaphore signaling.\

### 10. Applications
-> Smart Mining Safety: Real-time hazardous gas detection and structural health monitoring in underground environments. \
-> Industrial IIoT: Low-latency automation for synchronized motor control and environmental sensing. \
-> Autonomous Edge Nodes: Reliable, self-contained embedded systems requiring fault-tolerant task orchestration. \

### 11. Conclusion & Acknowledgement

This project successfully demonstrates the implementation of a centralized multitasking orchestrator, bridging the gap between raw sensor data and deterministic safety analytics. By leveraging RTOS primitives, we have ensured a robust, scalable architecture capable of operating in high-stakes industrial environments.

**We extend our sincere gratitude to**:\
**Pi Square Technologies:** For providing the technical framework and industry insights into QNX and real-time systems.\
**Academic Mentors:** Dr. Sharmila B.S. and Mr. Puneeth S. from The National Institute of Engineering (NIE), Mysuru, for their invaluable guidance and constant support throughout the development process.

