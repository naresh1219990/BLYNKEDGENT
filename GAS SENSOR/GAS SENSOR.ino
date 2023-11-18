#define BLYNK_TEMPLATE_ID "TMPLU1iV8UAX"
#define BLYNK_DEVICE_NAME "VIRTUAL"
#define BLYNK_TEMPLATE_NAME BLYNK_DEVICE_NAME

#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
//#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"

#define MQ2_SENSOR    A0 //A0
#define ledPin        14 //D5

int MQ2_SENSOR_Value = 0;
WidgetLED led(V14);

void sendSensor()
{
  MQ2_SENSOR_Value = map(analogRead(MQ2_SENSOR), 0, 1024, 0, 100);
  Blynk.virtualWrite(V15, MQ2_SENSOR_Value);
  if (MQ2_SENSOR_Value > 50 )
  {
    digitalWrite(ledPin, HIGH);
    Blynk.logEvent("gas");
    Serial.println("GAS LEAKAGE DEDUCTED");
    led.on();
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("SAFE");
    led.off();
  }   
}

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(MQ2_SENSOR, INPUT);
  BlynkEdgent.begin();
  timer.setInterval(1000L, sendSensor); 
}

void loop() 
{
  BlynkEdgent.run();
  timer.run();        // Initiates SimpleTimer
}
