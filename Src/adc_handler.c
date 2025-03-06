#include "adc_handler.h"

ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;
uint32_t adcBuffer[ADC_BUFFER_SIZE];
QueueHandle_t adcQueue;
SemaphoreHandle_t adcSemaphore;

void ADC_Init(void) {
    __HAL_RCC_ADC1_CLK_ENABLE();
    __HAL_RCC_DMA2_CLK_ENABLE();

    hadc1.Instance = ADC1;
    hadc1.Init.Resolution = ADC_RESOLUTION_12B;
    hadc1.Init.ContinuousConvMode = DISABLE;
    hadc1.Init.ExternalTrigConv = ADC_EXTERNALTRIG_T3_TRGO;
    hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
    hadc1.Init.ScanConvMode = ENABLE;
    hadc1.Init.NbrOfConversion = ADC_CHANNEL_COUNT;

    HAL_ADC_Init(&hadc1);

    adcQueue = xQueueCreate(10, sizeof(adcBuffer));
    adcSemaphore = xSemaphoreCreateBinary();

    HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
}

void ADC_Task(void *argument) {
    uint32_t adcData[ADC_CHANNEL_COUNT];
    for (;;) {
        if (xSemaphoreTake(adcSemaphore, portMAX_DELAY) == pdTRUE) {
            memcpy(adcData, adcBuffer, sizeof(adcBuffer));
            xQueueSend(adcQueue, adcData, portMAX_DELAY);
        }
    }
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)    //DMA started in Tim3 Ineterrupt
{
    if (hadc->Instance == ADC1) {
        xSemaphoreGiveFromISR(adcSemaphore, NULL);
    }
}
