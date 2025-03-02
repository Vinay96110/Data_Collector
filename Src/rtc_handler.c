#include "rtc_handler.h"
#include <stdio.h>

RTC_HandleTypeDef hrtc;

void RTC_Init(void) {
    hrtc.Instance = RTC;
    hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
    hrtc.Init.AsynchPrediv = 127;
    hrtc.Init.SynchPrediv = 255;
    HAL_RTC_Init(&hrtc);
}

void GetCurrentTime(char *buffer, size_t len) {
    RTC_TimeTypeDef sTime;
    RTC_DateTypeDef sDate;
    
    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

    snprintf(buffer, len, "%04d-%02d-%02d %02d:%02d:%02d", 
             2000 + sDate.Year, sDate.Month, sDate.Date, 
             sTime.Hours, sTime.Minutes, sTime.Seconds);
}
