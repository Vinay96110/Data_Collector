#include "wdt_handler.h"
#include "stm32f7xx_hal.h"

IWDG_HandleTypeDef hiwdg;

void WDT_Init(void) {
    hiwdg.Instance = IWDG;
    hiwdg.Init.Prescaler = IWDG_PRESCALER_32;
    hiwdg.Init.Reload = 4095;
    HAL_IWDG_Init(&hiwdg);
}

void WDT_Task(void *argument) {
    for (;;) {
        HAL_IWDG_Refresh(&hiwdg);
        osDelay(1000);
    }
}
