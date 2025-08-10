#include <Arduino.h>
#include <utils/cyd.h>
#include <utils/networkUtils.h>
#include <HTTPClient.h>
#include "dateUtils.h"
#include "api/todoistClient.h"
CYD cyd; 
NetworkUtils networkUtils;
DateUtils dateUtils;
TodoIstClient todoistClient;


void setup() {
  networkUtils.initWifi();
  dateUtils.initTime();
  cyd.displayMessage("Welcome To Pico-Life \n\n\nGetting Ready \n\n\nto help you with your Life!");
  delay(2000);
}

void loop() {
  const String todayDate = dateUtils.getTodayDate();
  const String todayTasks = todoistClient.getTodayTasks(todayDate);
  cyd.displayMessage(todayTasks);
  delay(5000);
}
