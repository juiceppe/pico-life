#include <networkUtils.h>
#include <cyd.h>

#include "../secrets.h"


NetworkUtils::NetworkUtils() {

}
extern CYD cyd;
void NetworkUtils::initWifi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while(WiFi.status() != WL_CONNECTED){
        cyd.displayMessage("Connecting...");
        delay(1000);
    }
    cyd.displayMessage("Connected!!");
}