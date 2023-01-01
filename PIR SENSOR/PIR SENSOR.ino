#define BLYNK_TEMPLATE_ID "TMPLU1iV10UAX"
#define BLYNK_DEVICE_NAME "VIRTUAL"

#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"

#define ledPin D3
#define PIRPin D5

int PIRSensor;
WidgetLED led(V9);

void sendSensor()
{
  PIRSensor = digitalRead(PIRPin);
  
  if (PIRSensor == HIGH )
  {
    digitalWrite(ledPin, HIGH);
    Blynk.logEvent("motion");
    Blynk.virtualWrite(V10, 1);
    Serial.println("MOTION DEDUCTED");
    led.on();
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Blynk.virtualWrite(V10, 0);
    Serial.println("NO MOTION");
    led.off();
  }   
}

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(PIRPin, INPUT);
  BlynkEdgent.begin();
  timer.setInterval(100L, sendSensor); 
}

void loop() 
{
  BlynkEdgent.run();
  timer.run();        // Initiates SimpleTimer
}
