#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Replace with your Wi-Fi credentials
char ssid[] = "YourSSID";
char pass[] = "YourPassword";
char auth[] = "YourBlynkAuthToken";

// Pin Definitions
#define PIR_PIN 2
#define LDR_PIN 34
#define RELAY_PIN 12

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(PIR_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW); // Turn off light initially
}

void loop() {
  Blynk.run();

  int motion = digitalRead(PIR_PIN);
  int lightLevel = analogRead(LDR_PIN);

  Serial.println("Motion: " + String(motion) + " Light: " + String(lightLevel));

  if (motion == HIGH && lightLevel < 500) {
    digitalWrite(RELAY_PIN, HIGH); // Turn on light
  } else {
    digitalWrite(RELAY_PIN, LOW); // Turn off light
  }
}
