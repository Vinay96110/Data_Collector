#ifndef RTC_HANDLER_H
#define RTC_HANDLER_H

#include "stm32f7xx_hal.h"

void RTC_Init(void);
void GetCurrentTime(char *buffer, size_t len);

#endif // RTC_HANDLER_H
