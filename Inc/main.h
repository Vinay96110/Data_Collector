#ifndef MAIN_H
#define MAIN_H

#include "stm32f7xx_hal.h"
#include "cmsis_os.h"
#include "task_dispatcher.h"
#include "timer_handler.h"

extern SemaphoreHandle_t spiMutex;

#endif // MAIN_H
