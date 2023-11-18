#define BLYNK_TEMPLATE_ID "TMPLU1iV8UAX"
#define BLYNK_DEVICE_NAME "VIRTUAL"
#define BLYNK_TEMPLATE_NAME BLYNK_DEVICE_NAME

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

WidgetLCD lcd(V20);

BlynkTimer timer;

void sendSeconds() {
  Blynk.virtualWrite(V16, millis() / 1000);
}

void sendMillis() {
  Blynk.virtualWrite(V17, millis());
}
void sendLcdText() {
  lcd.print(0,0,"hi how r u i am here");
}  
void setup()
{
  Serial.begin(115200);
  delay(1000);
  lcd.clear(); //Use it to clear the LCD Widget
  
  timer.setInterval(1000L, sendLcdText);
  // Setup a function to be called every second
  timer.setInterval(1000L, sendSeconds);
  // Setup a function to be called every second
  timer.setInterval(1000L, sendMillis); 

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}

