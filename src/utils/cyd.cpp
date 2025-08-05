#include <cyd.h>

CYD::CYD() {
    // Constructor implementation
    tft.begin();
    tft.setRotation(0);
    tft.fillScreen(TFT_BLACK);
}

void CYD::displayMessage(const String& message) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(0.7);
    tft.setCursor(0, 0);
    tft.println(message);
}