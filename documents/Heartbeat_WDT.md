 Description

Implements system monitoring via heartbeat LED and watchdog timer.
✔ Key Parameters

HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0) → Toggles an LED every 500ms.
HAL_IWDG_Refresh(&hiwdg) → Refreshes watchdog timer every 1s to prevent system reset.
✔ Reasoning

Heartbeat LED provides a visual indicator that the system is running correctly.
Watchdog timer prevents system hangs by resetting the MCU if a fault occurs.