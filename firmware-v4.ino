// Final firmware version!!!!
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
    rainbow(2);
  } else {
    for (int i = 0; i < NUM_PIXELS; i++) {
      ring.setPixelColor(i, ring.Color(0, 0, 0));
    }
    ring.show();
  }

}

void rainbow(uint32_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < ring.numPixels(); i++) {
      ring.setPixelColor(i, Wheel((i * 256 / ring.numPixels() + j) & 255));
    }
    ring.show();
    delay(wait);
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
  threshold = map(analogRead(POT_PIN), 0, 4095, 70, 300);
  checkSound();
}

// changing RGB for later
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return ring.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return ring.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return ring.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
