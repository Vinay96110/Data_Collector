Dependency Breakdown:
Timer3 triggers ADC DMA, meaning ADC execution is dependent on Timer3 running.
ADC DMA must complete before ADC Task can fetch data.
ADC Task needs valid data before MQTT Task can send it.
If ADC is not ready, MQTT Task sends only the timestamp instead of ADC data.
WDT Task ensures system health by preventing resets if any task stalls.
Heartbeat LED Task runs independently but depends on the system running correctly.
This ensures proper synchronization of ADC readings, MQTT transmissions, and system reliability.

+---------------------------+
|        System Init        |
+---------------------------+
            |
            v
+---------------------------+
|  Task Dispatcher Init     |  
|  - Creates ADC Task       |  
|  - Creates MQTT Task      |  
|  - Creates WDT Task       |  
|  - Creates Heartbeat Task |  
+---------------------------+
            |
            v
+---------------------------+
|       Timer3 Init         |  <---- (Dependency: Triggers ADC)
|  - Configures Timer3 (30ms)|
|  - Enables IRQ            |
+---------------------------+
            |
            v
+---------------------------+
|  Timer3 ISR Triggers      |  
|  ADC_Start_DMA()          |
+---------------------------+
            |
            v
+---------------------------+
|    ADC Conversion Start   |  <---- (Dependency: Triggered by Timer3)
|    - Uses DMA Transfer    |
+---------------------------+
            |
            v
+---------------------------+
| ADC DMA Completion ISR    |
| - Stores Data in Buffer   |
| - Signals ADC Task via Queue/Semaphore |
+---------------------------+
            |
            v
+---------------------------+
|  ADC Task Reads Data      |  <---- (Dependency: Queue must have Data)
|  - Reads from Queue       |
|  - Prepares Data for MQTT |
+---------------------------+
            |
            v
+---------------------------+
|  MQTT Task Execution      |  <---- (Dependency: Needs ADC Data)
|  - Waits for 30ms Timer   |
|  - Fetches ADC Data       |
|  - Sends Data to Cloud    |
|  - If No ADC Data, Sends Timestamp |
+---------------------------+
            |
            v
+---------------------------+
|    WDT Task Execution     |  <---- (Dependency: System must be alive)
|  - Refreshes Watchdog     |
|  - Prevents System Reset  |
+---------------------------+
            |
            v
+---------------------------+
|  Heartbeat LED Task       |  <---- (Dependency: System Running)
|  - Blinks Every Interval  |
+---------------------------+
