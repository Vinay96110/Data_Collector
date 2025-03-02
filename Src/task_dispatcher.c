#include "task_dispatcher.h"
#include "cmsis_os.h"
#include "adc_handler.h"
#include "mqtt_handler.h"
#include "wdt_handler.h"
#include "heartbeat_led.h"

void TaskDispatcher_Init(void) {
    xTaskCreate(ADC_Task, "ADC_Task", 512, NULL, osPriorityNormal, NULL);
    xTaskCreate(MQTT_Task, "MQTT_Task", 512, NULL, osPriorityNormal, NULL);
    xTaskCreate(WDT_Task, "WDT_Task", 128, NULL, osPriorityHigh, NULL);
    xTaskCreate(Heartbeat_Task, "Heartbeat", 128, NULL, osPriorityLow, NULL);
}
