/*
Code Name: 4 channel Relay IoT home automation
Author: ammarece
Description: This program is used for 4 channel Relay IoT home automation
License: Remixing or Changing this Thing is allowed. Commercial use is not allowed.
*/
#define BLYNK_TEMPLATE_ID "TMPLVQ-drkVE"
#define BLYNK_TEMPLATE_NAME "My Hostel Room"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = ""; //put auth token here
char ssid[] = "iMaK";
char pass[] = "gate@2024";

int relay1Pin = D1;
int relay2Pin = D2;
int relay3Pin = D3;
int relay4Pin = D4;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);
  pinMode(relay4Pin, OUTPUT);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V1)
{
  int relay1State = param.asInt();
  digitalWrite(relay1Pin, relay1State);
}

BLYNK_WRITE(V2)
{
  int relay2State = param.asInt();
  digitalWrite(relay2Pin, relay2State);
}

BLYNK_WRITE(V3)
{
  int relay3State = param.asInt();
  digitalWrite(relay3Pin, relay3State);
}

BLYNK_WRITE(V4)
{
  int relay4State = param.asInt();
  digitalWrite(relay4Pin, relay4State);
}
