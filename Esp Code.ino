#include <WiFi.h>  
#include <BlynkSimpleEsp32.h>  
#include <OneWire.h>  
#include <DallasTemperature.h>  

// Wi-Fi credentials  
const char* ssid = "YOUR_WIFI_SSID";  
const char* password = "YOUR_WIFI_PASSWORD";  
const char* authToken = "YOUR_BLYNK_AUTH_TOKEN";  

// Sensor pins  
#define pH_PIN A0  
#define TURBIDITY_PIN A1  
#define TEMP_PIN 4  
#define RELAY_PIN 12  

// Thresholds (adjust based on aquarium needs)  
const float pH_THRESHOLD = 6.5; // Example: ideal pH for freshwater aquariums <button class="citation-flag" data-index="6">  
const float TEMP_THRESHOLD = 28.0; // °C <button class="citation-flag" data-index="1">  
const int TURBIDITY_THRESHOLD = 150; // NTU <button class="citation-flag" data-index="7">  

OneWire oneWire(TEMP_PIN);  
DallasTemperature tempSensor(&oneWire);  

void setup() {  
  Serial.begin(115200);  
  Blynk.begin(authToken, ssid, password);  
  tempSensor.begin();  
  pinMode(RELAY_PIN, OUTPUT);  
  digitalWrite(RELAY_PIN, LOW);  
}  

void loop() {  
  Blynk.run();  

  // Read pH  
  float pHValue = analogRead(pH_PIN);  
  pHValue = map(pHValue, 0, 4095, 0, 14); // Convert to pH scale (calibrate with known solutions) <button class="citation-flag" data-index="4">  

  // Read temperature  
  tempSensor.requestTemperatures();  
  float temp = tempSensor.getTempCByIndex(0);  

  // Read turbidity  
  int turbidity = analogRead(TURBIDITY_PIN); // Raw ADC value <button class="citation-flag" data-index="2">  

  // Send data to Blynk  
  Blynk.virtualWrite(V1, pHValue);  
  Blynk.virtualWrite(V2, temp);  
  Blynk.virtualWrite(V3, turbidity);  

  // Automated control  
  if (pHValue < pH_THRESHOLD || temp > TEMP_THRESHOLD || turbidity > TURBIDITY_THRESHOLD) {  
    digitalWrite(RELAY_PIN, HIGH); // Activate pump or light <button class="citation-flag" data-index="8">  
    Blynk.notify("ALERT: Abnormal water parameters detected!"); // Send Telegram notification <button class="citation-flag" data-index="3">  
  } else {  
    digitalWrite(RELAY_PIN, LOW);  
  }  

  delay(5000);  
}  
