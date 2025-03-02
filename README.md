/UDC_Firmware
  ├── Core/
  │   ├── Inc/
  │   │   ├── main.h
  │   │   ├── task_dispatcher.h        # Central dispatcher for task initialization
  │   │   ├── adc_handler.h            # ADC task with DMA
  │   │   ├── mqtt_handler.h           # MQTT task for cloud communication
  │   │   ├── wdt_handler.h            # Watchdog Timer task
  │   │   ├── led_handler.h            # Heartbeat LED task
  │   │   ├── flash_logger.h           # Logs events when MQTT fails (SPI-based)
  │   │   ├── spi_manager.h            # SPI interface for ADC & Flash (with sync)
  │   │   ├── i2c_manager.h            # I2C interface for Thermocouple
  │   │   ├── usb_handler.h            # USB communication (ST Cube stack)
  │   ├── Src/
  │   │   ├── main.c
  │   │   ├── task_dispatcher.c
  │   │   ├── adc_handler.c
  │   │   ├── mqtt_handler.c
  │   │   ├── wdt_handler.c
  │   │   ├── led_handler.c
  │   │   ├── flash_logger.c
  │   │   ├── spi_manager.c
  │   │   ├── i2c_manager.c
  │   │   ├── usb_handler.c
  ├── Middlewares/                     # USB Middleware from ST
  │   ├── USB_Device/
  │   ├── USB_Host/
  ├── Drivers/                          # STM32 Peripheral Drivers
  ├── FreeRTOS/                         # RTOS Files
  ├── Utilities/                        # Helper functions

=====================================================================================

1️⃣ Task Dispatcher (task_dispatcher.c)
✔️ Creates & manages RTOS tasks dynamically.
✔️ Initializes critical subsystems (ADC, SPI, I2C, MQTT, USB).
✔️ Ensures modular task execution.

2️⃣ ADC Handling (adc_handler.c)
✔️ Uses DMA for 16-channel ADC readings.
✔️ Data is stored in a queue before MQTT transmission.
✔️ Uses mutex for SPI synchronization when logging to Flash.

3️⃣ SPI Manager (spi_manager.c)
✔️ Handles SPI communication for ADC & External Flash.
✔️ Mutex ensures exclusive access between ADC & Logging tasks.
✔️ Manages Chip Select (CS) pins dynamically.

4️⃣ I2C Manager (i2c_manager.c)
✔️ Manages I2C-based thermocouples for temperature readings.
✔️ Uses a semaphore to prevent race conditions between tasks.

5️⃣ MQTT Task (mqtt_handler.c)
✔️ Publishes ADC and thermocouple data to cloud via MQTT.
✔️ Monitors network connectivity, triggers Flash logging on failure.

6️⃣ Flash Logger (flash_logger.c)
✔️ Logs critical data/events when MQTT fails.
✔️ Uses bare minimum logs to optimize memory usage.
✔️ Retrieves & sends logs once MQTT reconnects.

7️⃣ WDT Task (wdt_handler.c)
✔️ Refreshes watchdog timer periodically.
✔️ Resets system if any task stalls.

8️⃣ LED Task (led_handler.c)
✔️ Blinks a heartbeat LED every 500ms to indicate the system is running.

9️⃣ USB Handler (usb_handler.c)
✔️ Handles USB Type-C communication using ST’s USB stack.
✔️ Supports data transfer & device detection.
✔️ Future extension: File system support for USB storage.

=====================================================================================
✅ Modular: Each functionality is encapsulated in its own .h and .c files.
✅ Thread-Safe: Mutex for SPI access, Queue for ADC buffering, Semaphore for I2C.
✅ Scalable: New features (e.g., new sensors, SD card) can be added without modifying   existing code/ main functions.
✅ Optimized Logging: Only logs critical events when MQTT fails, reducing Flash wear.