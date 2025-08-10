#include "dateUtils.h"
#include "time.h"

DateUtils::DateUtils() 
    : ntpServer("pool.ntp.org"),
      gmtOffset_sec(0),
      daylightOffset_sec(3600) {
}

void DateUtils::initTime() {
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

String DateUtils::getTodayDate() {
    struct tm timeinfo{};
    if (!getLocalTime(&timeinfo)) {
        return "No date available";
    }

    char dateString[32];
    strftime(dateString, sizeof(dateString), "%Y-%m-%d", &timeinfo);
    return String(dateString);
}

String DateUtils::getCurrentTime() {
    struct tm timeinfo{};
    if (!getLocalTime(&timeinfo)) {
        return "No time available";
    }

    char timeString[16];
    strftime(timeString, sizeof(timeString), "%H:%M", &timeinfo);
    return String(timeString);
}

String DateUtils::getCurrentDateTime() {
    struct tm timeinfo{};
    if (!getLocalTime(&timeinfo)) {
        return "No datetime available";
    }

    char datetimeString[64];
    strftime(datetimeString, sizeof(datetimeString), "%Y-%m-%d %H:%M:%S", &timeinfo);
    return String(datetimeString);
}

bool DateUtils::isTimeAvailable() {
    struct tm timeinfo{};
    return getLocalTime(&timeinfo);
}