#include <Adafruit_NeoPixel.h>
#include <arduinoFFT.h>

// Pin setup
#define MIC_PIN 15
#define LED_PIN 26


void checkSound() {
  int micValue = analogRead(MIC_PIN);
  Serial.println(micValue);

  if (micValue > 4) digitalWrite(LED_PIN, HIGH);

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  analogReadResolution(2);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);

}

void loop() {
  checkSound();
}
