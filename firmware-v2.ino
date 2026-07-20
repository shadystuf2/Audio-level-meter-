#include <Adafruit_NeoPixel.h>
#include <arduinoFFT.h>

// Pin & pixel setup
#define MIC_PIN 15
#define RING_PIN 26
#define NUM_PIXELS 16

// Objects 
Adafruit_NeoPixel ring(NUM_PIXELS, RING_PIN, NEO_GRB + NEO_KHZ800);



void checkSound() {
  int micValue = analogRead(MIC_PIN);
  Serial.println(micValue);
  if (micValue < 2000) {
    for (int i = 0; i < NUM_PIXELS; i++) {
      ring.setPixelColor(i, ring.Color(0, 255, 0));
    }
    ring.show();
  } else {
    for (int i = 0; i < NUM_PIXELS; i++) {
      ring.setPixelColor(i, ring.Color(0, 0, 0));
    }
    ring.show();
  }
  //while (micValue < 2000) {
    
    //rainbowFlow();
  //}

}

void rainbowFlow() {
   Serial.println("Hello, ESP32!");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  ring.begin();
  ring.show();

  analogReadResolution(12);

}

void loop() {
  checkSound();
}
