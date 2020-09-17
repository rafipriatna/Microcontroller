/*
 * Simple IoT
 * By @rafipriatna
 * 
 * Model: WeMos D1 R2 v2
 */

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>

const char* SSID = "SSID";
const char* PASS = "PASSWORD";

String serverName = "http://your_ip_url";
// Contoh: http://192.168.0.23:8080/api/buttons/

void setup() {
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  
  // Connect to network
  Serial.begin(115200);
  WiFi.begin(SSID, PASS);
  Serial.print("Connecting");
  
  while(WiFi.status() != WL_COaNNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    httpGetButtonRequest();
  }
  delay(500);
}

String httpGetButtonRequest() {
  WiFiClient client;
  HTTPClient http;
  for (int i = 1; i <= 3; i++) {
   String serverNameSum = serverName;
   serverNameSum += i;
       
   char * newServerName = &serverNameSum[0];
   http.begin(client, newServerName);

   Serial.println(newServerName);
   Serial.println(http.GET());

   Serial.println(http.getString());
   if (http.GET() > 0) {
      // Parse
      DynamicJsonDocument doc(2048);
      DeserializationError error = deserializeJson(doc, http.getString());
    
      if (error) {
        Serial.println("deserializeJson() failed: ");
        Serial.println(error.c_str());
      }
  
      uint8_t buttonPin;
      String buttonName = doc["name"];
      int buttonStatus = doc["status"];

      if (doc["pin"] == "D2") {
        buttonPin = 4;
      } else if (doc["pin"] == "D3") {
        buttonPin = 0;
      } else if (doc["pin"] == "D4") {
        buttonPin = 2;
      }
  
      // Control LED
      if (buttonStatus == 1) {
        digitalWrite(buttonPin, HIGH);
      } else {
        digitalWrite(buttonPin, LOW);
      }
      http.end();
   } else {
     http.end();
   }
  }
   
}
