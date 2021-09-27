#include <Adafruit_NeoPixel.h>

int ledPIN = 6;
int numLEDs = 1;

Adafruit_NeoPixel pixel(numLEDs, ledPIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  pixel.begin();
  pixel.show();
  pixel.setBrightness(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  pixel.setPixelColor(0,255,0,0);
  pixel.show();

}
