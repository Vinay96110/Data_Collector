#include "heartbeat_led.h"
#include "cmsis_os.h"
#include "stm32f7xx_hal.h"

#define HEARTBEAT_LED_PIN GPIO_PIN_13
#define HEARTBEAT_LED_PORT GPIOC

void Heartbeat_LED_Task(void *argument) {
    while (1) {
        HAL_GPIO_TogglePin(HEARTBEAT_LED_PORT, HEARTBEAT_LED_PIN);
        osDelay(1000);  // Blink LED every 1 second
    }
}


