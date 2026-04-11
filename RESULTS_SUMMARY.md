## System setup
<img width="715" height="1600" alt="image" src="https://github.com/user-attachments/assets/a2580a85-8927-402e-b0aa-c59915ee5dff" />

## RESULTS
## ✅ Test Case Results

### 1. Orchestrator Failure

```c
signal(SIGINT, on_signal);
signal(SIGTERM, on_signal);

while (g_run) usleep(200000);

Justification:

Orchestrator controls all child processes.
If it fails → no parent to manage children → system stops.
Current design = fail-safe, not self-recovering.
2. Raspberry Pi Power OFF

Code:

FILE *fp = fopen("bmp280_log.csv", "a");
fprintf(fp, "%u,%ld,%.2f,...\n", ...);
fflush(fp);

Justification:

Data is continuously flushed to file.
On power loss → only latest cycle may be lost.
System recovers on reboot → fail-recover behavior.

3. Sensor Disconnection
Code:

if (smbus_read_byte_data(I2C_BUS, BMP280_ADDR, BMP280_REG_ID, &chip_id) != I2C_SUCCESS)
{
    fprintf(stderr, "ERROR: BMP280 not found\n");
    return EXIT_FAILURE;
}

Justification:

Detects missing sensor via I2C failure.
Prevents invalid data propagation.
System stops → fail-safe design.

4. Sensor False Data (Noise / Spikes)
Code:

a.alarm_active = (raw->temp >= ALARM_TEMP_HIGH || raw->pressure <= ALARM_PRESS_LOW);
a.trend_delta = raw->pressure - prev;

Justification:

Threshold + trend used to detect abnormal values.
Sudden spikes flagged as alarms.
Ensures data validation before action.

5. Sensor Stuck (Constant Value)
Code:

a.trend_delta = (prev > 0.0f) ? (raw->pressure - prev) : 0.0f;

Justification:

If trend = 0 continuously → sensor likely stuck.
Helps detect non-responsive sensors.

| Test Case                          | Expected Outcome                                   | Result  |
|----------------------------------|----------------------------------------------------|---------|
| Sensor Initialization            | BMP280 detected and initialized successfully       | PASS    |
| Temperature Acquisition          | Valid temperature values received periodically      | PASS    |
| Pressure Acquisition             | Valid pressure values received periodically         | PASS    |
| Analytics Processing             | Correct min/max/avg and altitude computed           | PASS    |
| Trend Detection                  | Rising/Falling/Stable trend identified correctly    | PASS    |
| Inter-Process Communication (IPC)| Data transferred via message queues without loss    | PASS    |
| Alarm Trigger                    | Alarm activated at threshold breach                | PASS    |
| Display Output                   | Real-time formatted data displayed correctly        | PASS    |
| Data Logging                     | CSV file updated with correct entries               | PASS    |
| Graceful Shutdown                | All processes terminated safely on interrupt        | PASS    |

## COMPARISION B/W LINUX AND QNX

| **Aspect** | **Linux (General-Purpose OS)** | **RTOS (Real-Time OS)** |
|------------|-------------------------------|--------------------------|
| **System Goal** | Throughput & fairness | Deterministic timing |
| **Scheduling Type** | CFS (fair scheduler), optional `SCHED_FIFO` | Strict priority-based preemptive |
| **Determinism** |  Not guaranteed |  Fully deterministic |
| **Timing Accuracy** | Variable (jitter present) | Precise and predictable |
| **Jitter (Timing Variation)** | High | Very low |
| **Interrupt Latency** | Variable | Bounded and predictable |
| **Multi-Sensor Coordination** | Difficult to guarantee sync | Easy and reliable |
| **Deadline Guarantee** |  No guarantee |  Guaranteed |
| **Task Preemption** | Limited control | Immediate based on priority |
| **Memory Handling** | Virtual memory (paging possible) | No paging (locked memory) |
| **CPU Usage Behavior** | May be affected by background processes | Fully controlled execution |
| **IPC (MQ, Shared Memory)** | Supported but non-deterministic | Deterministic IPC mechanisms |
| **Best Use Case** | IoT, monitoring, logging | Automotive, robotics, medical |
| **Failure Risk in Critical System** | Higher (missed deadlines) | Very low |
| **Example Systems** | Ubuntu, Raspberry Pi OS | QNX Neutrino, FreeRTOS |
