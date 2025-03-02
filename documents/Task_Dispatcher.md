Description

Creates and manages FreeRTOS tasks, ensuring modular task management.
✔ Key Parameters

xTaskCreate(ADC_Task, "ADC_Task", 512, NULL, osPriorityNormal, NULL) → Handles ADC data acquisition.
xTaskCreate(Heartbeat_Task, "Heartbeat", 128, NULL, osPriorityLow, NULL) → Monitors system health.
xTaskCreate(WDT_Task, "WDT", 128, NULL, osPriorityHigh, NULL) → Ensures system stability.
✔ Reasoning

TaskDispatcher centralizes task creation, keeping main.c clean.
Priorities ensure real-time execution (e.g., WDT has high priority).