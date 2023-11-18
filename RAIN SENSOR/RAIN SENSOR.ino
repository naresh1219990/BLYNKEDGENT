#define BLYNK_TEMPLATE_ID "TMPLU1iV8UAX"
#define BLYNK_DEVICE_NAME "VIRTUAL"
#define BLYNK_TEMPLATE_NAME BLYNK_DEVICE_NAME

#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"

#define ledPin D3
#define RainPin D5

int RainSensor;
WidgetLED led(V11);

void sendSensor()
{
  RainSensor = digitalRead(RainPin);
  
  if (RainSensor == LOW )
  {
    digitalWrite(ledPin, HIGH);
    Blynk.logEvent("rain");
    Blynk.virtualWrite(V12, 1);
    Serial.println("ITS RAINING");
    led.on();
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Blynk.virtualWrite(V12, 0);
    Serial.println("NO RAIN DEDUCTED");
    led.off();
  }   
}

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(RainPin, INPUT);
  BlynkEdgent.begin();
  timer.setInterval(1000L, sendSensor); 
}

void loop() 
{
  BlynkEdgent.run();
  timer.run();        // Initiates SimpleTimer
}
