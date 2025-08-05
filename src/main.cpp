
#include <Arduino.h>
#include <utils/cyd.h>
#include <utils/networkUtils.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "secrets.h"
CYD cyd; 
NetworkUtils networkUtils;

void setup() {
  networkUtils.initWifi();
  HTTPClient http;
  http.begin("https://api.todoist.com/api/v1/sync");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.addHeader("Authorization", String("Bearer ") + String(TODOIST_API_TOKEN));

  const String postData = "sync_token=*&resource_types=[\"projects\"]";
  
  const int httpCode = http.POST(postData);

  if (httpCode > 0) {
    JsonDocument doc;
    const String payload = http.getString();
    const DeserializationError error = deserializeJson(doc, payload);

    if (error) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
      return;
    }
    // std::vector<String> projectNames;
    // JsonArray projects = doc["projects"].as<JsonArray>();
    // for (JsonVariant project : projects) {
    //   projectNames.push_back(project["name"].as<String>());
    // }
    String allProjectNames = "Projects:\n\n";  // Start with header and add two newlines
    JsonArray projects = doc["projects"].as<JsonArray>();

    for (JsonVariant project : projects) {
      allProjectNames += "- " + project["name"].as<String>() + "\n";
    }

    Serial.println(payload);
    cyd.displayMessage(allProjectNames);
  } else {
    Serial.println("Error on HTTP request: " + String(httpCode));
  }
  
  http.end();
}

void loop() {
  // Need to do something here
}