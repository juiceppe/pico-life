#ifndef CYD_H
#define CYD_H

#include <TFT_eSPI.h>

class CYD {
public:
    CYD();
    void displayMessage(const String& message);

private:
    TFT_eSPI tft;
};

#endif // CYD_H