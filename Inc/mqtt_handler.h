#ifndef MQTT_HANDLER_H
#define MQTT_HANDLER_H

#include "cmsis_os.h"
#include "queue.h"

extern QueueHandle_t mqttQueue;

void MQTT_Init(void);
void MQTT_Task(void *argument);

#endif
