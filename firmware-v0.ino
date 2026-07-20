// libraries
#include <arduinoFFT.h>
#include <Adafruit_NeoPixel.h>

// Defining pins
#define RING_PIN 26
#define NUM_PIXELS 24 
Adafruit_NeoPixel ring(NUM_PIXELS, RING_PIN, NEO_GRB + NEO_KHZ800);

#define MIC_PIN 35

#define SAMPLES 64
#define SAMPLING_FREQUENCY 10000.0

// This is part of FFT math
float vReal[SAMPLES];
float vImag[SAMPLES];

//Created the FFT object
ArduinoFFT<float> FFT = ArduinoFFT<float>(vReal, vImag, SAMPLES, SAMPLING_FREQUENCY);
unsigned long microseconds;

//smoothing - uses average of 4 readings
#define AVERAGE_SAMPLE 4

// history of previous values
int magnitudeHistory[NUM_LEDS][AVERAGE_AVERGE] = {0}
int historyIndex[NUM_LEDS] = {0};

//sensitivity - where potentiometer connects
#define SENSITIVITY_PIN 34
double sensitvity = 









void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogReadResolution(12); //sets ADC (bit depth?)
  ring.begin();
  for (int i = 0; i < NUM_PIXELS; i++) {
    ring.setPixelColor(i, ring.Color(0, 0, 255)); // Green
  }
  ring.show();
}

void loop() {
  delay(10); 
}
