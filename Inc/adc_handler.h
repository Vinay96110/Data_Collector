#ifndef ADC_HANDLER_H
#define ADC_HANDLER_H

#include "stm32f7xx_hal.h"
#include "cmsis_os.h"
#include "queue.h"
#include "semphr.h"

#define ADC_CHANNEL_COUNT 16  
#define ADC_BUFFER_SIZE ADC_CHANNEL_COUNT  

extern QueueHandle_t adcQueue;
extern SemaphoreHandle_t adcSemaphore;

void ADC_Init(void);
void ADC_Task(void *argument);
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);

#endif
