//
// Created by Giuseppe Abrignani on 10/08/2025.
//

#ifndef DATE_H
#define DATE_H

#include <Arduino.h>

class DateUtils {
public:
    /**
     * Constructor
     */
    DateUtils();
    
    /**
     * Initialize NTP time synchronization
     * Must be called after WiFi is connected
     */
    void initTime();
    
    /**
     * Get today's date in YYYY-MM-DD format
     * @return Today's date string, or error message if time not available
     */
    String getTodayDate();
    
    /**
     * Get current time in HH:MM format
     * @return Current time string, or error message if time not available
     */
    String getCurrentTime();
    
    /**
     * Get full datetime string
     * @return Formatted datetime string
     */
    String getCurrentDateTime();
    
    /**
     * Check if time has been synchronized
     * @return true if time is available
     */
    bool isTimeAvailable();

private:
    const char* ntpServer;
    long gmtOffset_sec;
    int daylightOffset_sec;
};


#endif //DATE_H
