// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       test.ino
    Created:  2018-12-22 오전 7:00:32
    Author:     DESKTOP-PRKCMAP\ItsmyDESKTOP
*/

#include <ESP8266WiFi.h>
#include <Bridge.h>
#include <ESP8266HTTPClient.h>
#include "ArduinoJson-v5.13.4.h"

//WIFI SETTINGS
const char *ssid = "GDIP";
const char *pass = "";

WiFiClient client;
bool bConnent;

void setup()
{
  Serial.begin(115200);
  WiFi.onEvent(WiFiEvent);
  WiFi.begin(ssid, pass);

}

// Add the main program code into the continuous loop() function
void loop()
{
  StaticJsonBuffer<300> jsonBuffer;
  JsonObject &jsonObject = jsonBuffer.createObject();
  jsonObject["message"] = "ASDFFVS";
  
  char JSONmessageBuffer[300];
  jsonObject.prettyPrintTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
  Serial.println(JSONmessageBuffer);

  HTTPClient http; //Declare object of class HTTPClient
  http.begin("http://60.0.11.84:7000/test/"); //Specify request destination
  http.addHeader("Content-Type", "application/json"); //Specify content-type header
  int httpCode = http.POST(JSONmessageBuffer);   //Send the request
  String payload = http.getString();                                        //Get the response payload

  Serial.println("HTTP CODE : "+ String(httpCode));   //Print HTTP return code
  Serial.println("PAYLOAD : " +payload);    //Print request response payload

  http.end();  //Close connection

  delay(10000);
}

void WiFiEvent(WiFiEvent_t event) {
  switch (event) {
  case WIFI_EVENT_STAMODE_CONNECTED:
    Serial.println("WiFi Connented");
    bConnent = true;
    break;

  case WIFI_EVENT_STAMODE_DISCONNECTED:
    Serial.println("WiFi Disconnented");
    bConnent = false;
    break;
  }
}
