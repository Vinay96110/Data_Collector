#include "mqtt_handler.h"
#include "stdio.h"
#include "string.h"

QueueHandle_t mqttQueue;

void MQTT_Init(void) {
    mqttQueue = xQueueCreate(5, sizeof(uint32_t) * ADC_CHANNEL_COUNT);
}

void MQTT_Task(void *argument) {
    uint32_t sensorData[ADC_CHANNEL_COUNT];
    char mqttMessage[256];

    for (;;) {
        if (xQueueReceive(mqttQueue, sensorData, pdMS_TO_TICKS(5)) == pdTRUE) {
            snprintf(mqttMessage, sizeof(mqttMessage),
                     "{ \"ADC\": [%lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu] }",
                     sensorData[0], sensorData[1], sensorData[2], sensorData[3],
                     sensorData[4], sensorData[5], sensorData[6], sensorData[7],
                     sensorData[8], sensorData[9], sensorData[10], sensorData[11],
                     sensorData[12], sensorData[13], sensorData[14], sensorData[15]);

            printf("MQTT Sending: %s\n", mqttMessage);
        } else {
            printf("MQTT No new ADC data, sending timestamp\n");
        }
    }
}
