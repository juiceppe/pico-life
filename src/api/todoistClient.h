//
// Created by Giuseppe Abrignani on 10/08/2025.
//

#ifndef TODOIST_H
#define TODOIST_H

#include <Arduino.h>

class TodoIstClient {
    public:

    explicit TodoIstClient();

    String getTodayTasks(const String& todayDate);

private:
    String apiToken;

};


#endif //TODOIST_H
