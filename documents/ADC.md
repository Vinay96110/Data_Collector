✔ Description

Handles ADC initialization, configuration, and FreeRTOS task for ADC data acquisition.
Uses DMA for efficient data transfer and Timer 3 for accurate sampling timing.

✔ Key Parameters

ScanConvMode = ENABLE → Required for scanning multiple channels.
ContinuousConvMode = DISABLE → ADC conversions are externally triggered by Timer 3.
ExternalTrigConv = ADC_EXTERNALTRIG_T3_TRGO → Timer 3 triggers ADC conversions at precise intervals.
DataAlign = ADC_DATAALIGN_RIGHT → Ensures correct alignment of ADC readings in memory.
NbrOfConversion = 16 → Configured to read all 16 channels.
SamplingTime = ADC_SAMPLETIME_15CYCLES → Chosen for a balance of speed and accuracy.
DMA Mode = ENABLE → Allows non-blocking ADC data transfer, reducing CPU load.
QueueHandle_t adcQueue → Transfers ADC data to processing tasks in FreeRTOS.


✔ Reasoning

DMA offloads data transfer from the CPU, improving efficiency.
Timer 3 ensures stable and jitter-free ADC sampling.
FreeRTOS queue provides safe data transfer between tasks.