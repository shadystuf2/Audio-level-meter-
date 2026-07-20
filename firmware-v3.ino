#include <Adafruit_NeoPixel.h>
#include <arduinoFFT.h>

// Pin & pixel setup
#define MIC_PIN 15
#define RING_PIN 26
#define NUM_PIXELS 16
#define POT_PIN 25

//Initial values for potentiometer
double sensitivity = 1500.0;
double threshold = 200.0;
int baseline = 2048;
// Objects 
Adafruit_NeoPixel ring(NUM_PIXELS, RING_PIN, NEO_GRB + NEO_KHZ800);



void checkSound() {
  int micValue = analogRead(MIC_PIN);
  int deviation = abs(micValue - baseline);

  Serial.println(deviation);
  
  if (deviation > threshold) {
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

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  pinMode(POT_PIN, INPUT);

  ring.begin();
  ring.show();

  analogReadResolution(12);

}

void loop() {
  threshold = map(analogRead(POT_PIN), 0, 4095, 5, 200);
  checkSound();
}
