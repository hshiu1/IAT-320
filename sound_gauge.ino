#include <Adafruit_CircuitPlayground.h>

float inputVol = CircuitPlayground.mic.soundPressureLevel(10);

void setup() {
  CircuitPlayground.begin();
}

void loop() {
  int n = 3;
  int val = 255;
  int zero = 0;
  CircuitPlayground.setPixelColor(n, zero, val, zero);
  delay(1000);
}
