#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
  
//----------- Enter you Wi-Fi Details---------//
char ssid[] = "Your wifi SSID"; //SSID
char pass[] = "Your wifi Password"; // Password
//-------------------------------------------//

const int trigger = 16;
const int echo = 5;
long T;                                                                                                                                                            
float distanceCM;
float a;
WiFiClient  client;

unsigned long myChannelField = Enter-channel ID; // Channel ID
const int ChannelField = 1; // Which channel to write data
const char * myWriteAPIKey = "Enter Write API Key"; // Your write API Key

void setup()
{
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  
}

void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
  digitalWrite(trigger, LOW);
  delay(1);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigger, LOW);
  T = pulseIn(echo, HIGH);
  distanceCM = T * 0.034;
  distanceCM = distanceCM / 2;
  Serial.print("Distance in cm: ");
  Serial.println(distanceCM);
  
  if(distanceCM<=4.0){
    a = 100;
    ThingSpeak.writeField(myChannelField, ChannelField, a, myWriteAPIKey);
  }
  else if(distanceCM>=4.1 && distanceCM<=5.9 ){
    a = 90;
    ThingSpeak.writeField(myChannelField, ChannelField, a, myWriteAPIKey);
  }

  else if(distanceCM>=6 && distanceCM<=8.9 ){
    a = 80;
    ThingSpeak.writeField(myChannelField, ChannelField, a, myWriteAPIKey);
  }
  else if(distanceCM>=9 && distanceCM<=10.9 ){
    a = 70;
    ThingSpeak.writeField(myChannelField, ChannelField, a, myWriteAPIKey);
  }
  else if(distanceCM>=11 && distanceCM<=13.9 ){
    a = 60;
    ThingSpeak.writeField(myChannelField, ChannelField, a, myWriteAPIKey);
  }
  else if(distanceCM>=14.0 && distanceCM<=17.9 ){
    a = 50;
    ThingSpeak.writeField(myChannelField, ChannelField, a, myWriteAPIKey);
  }
  else if(distanceCM>=18 && distanceCM<=20.9 ){
    a = 30;
    ThingSpeak.writeField(myChannelField, ChannelField, a, myWriteAPIKey);
  }
  else if(distanceCM>=21 && distanceCM<=24 ){
    a = 10;
    ThingSpeak.writeField(myChannelField, ChannelField, a, myWriteAPIKey);
  }
  delay(1000);
}
