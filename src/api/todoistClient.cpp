//
// Created by Giuseppe Abrignani on 10/08/2025.
//

#include "todoistClient.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include "../secrets.h"
TodoIstClient::TodoIstClient(){
}

String TodoIstClient::getTodayTasks(const String& todayDate) {
    if (WiFi.status() != WL_CONNECTED) {
        return "{\"error\": \"WiFi not connected\"}";
    }

    HTTPClient http;

    http.begin("https://api.todoist.com/api/v1/sync");
    http.addHeader("Authorization", "Bearer " + String(TODOIST_API_TOKEN));
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    const String postData = "sync_token=*&resource_types=[\"items\"]";
    const int httpResponseCode = http.POST(postData);


    if (httpResponseCode > 0) {
        JsonDocument doc;
        const String response = http.getString();
        const DeserializationError error = deserializeJson(doc, response);


        if (error) {
            http.end();
            return "{\"error\": \"JSON parsing failed: " + String(error.c_str()) + "\"}";
        }


        String formattedTasks = "Daily Tasks:\n\n";
        JsonArray tasks = doc["items"].as<JsonArray>();

        if (tasks.size() == 0) {
            formattedTasks = "No tasks for today!";
        } else {
            for (JsonVariant task : tasks) {
                if (task["due"]["date"] && task["due"]["date"].as<String>() == todayDate)
                formattedTasks += "- " + task["content"].as<String>() + "\n";
            }
        }
        http.end();
        return formattedTasks;
    }
    String error = "{\"error\": \"HTTP request failed with code: " + String(httpResponseCode) + "\"}";
    http.end();
    return error;
}
