#include "stm32f7xx_hal.h"
#include "cmsis_os.h"
#include "task_dispatcher.h"
#include "adc_handler.h"
#include "mqtt_handler.h"
#include "timer3_handler.h"

int main(void) {
    HAL_Init();
    SystemClock_Config();
    
    ADC_Init();
    MQTT_Init();
    Timer3_Init();

    osKernelInitialize();
    TaskDispatcher_Init();
    osKernelStart();

    while (1) {}
}
