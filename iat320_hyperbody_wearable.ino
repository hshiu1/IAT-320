#include <Adafruit_CircuitPlayground.h>

float inputVol; //sound pressure level

int ledPin = A1; //external neopixel pin
int numPix = 3; //number of external neopixels

//declare pixel strip object to be used with the CP
Adafruit_CPlay_NeoPixel pixel(numPix, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  CircuitPlayground.begin();
  pixel.begin();
}

void loop() {
  inputVol = CircuitPlayground.mic.soundPressureLevel(100) - 15;
  volumeWheel();
  moodLED();
}

//control the LEDs on the bottom of the wrist - color changes depending on volume
void moodLED() {
  //for every neopixel in the strip...
  for (int i = 0; i < pixel.numPixels(); i++) {
    pixel.setBrightness(50);
    pixel.show();
    if (inputVol > 0 && inputVol < 40) pixel.setPixelColor(i, 0, 0, 255); //quiet = blue
    else if (inputVol > 40 && inputVol < 60) pixel.setPixelColor(i, 0, 255, 0); //normal = green
    else if (inputVol > 60 && inputVol < 70) pixel.setPixelColor(i, 255, 255, 0); //rising = yellow
    else if (inputVol > 70) pixel.setPixelColor(i, 255, 0, 0); //loud/max = red
  }
}

//CP onboard neopixels will light up depending on volume level. Colour also depends on volume level.
void volumeWheel() {

  if (inputVol > 0) CircuitPlayground.setPixelColor(0, 51, 255, 255);
  else CircuitPlayground.setPixelColor(0, 0, 0, 0);

  if (inputVol > 40) CircuitPlayground.setPixelColor(1, 0, 153, 153);
  else CircuitPlayground.setPixelColor(1, 0, 0, 0);

  if (inputVol > 45) CircuitPlayground.setPixelColor(2, 51, 255, 51);
  else CircuitPlayground.setPixelColor(2, 0, 0, 0);

  if (inputVol > 50) CircuitPlayground.setPixelColor(3, 204, 255, 153);
  else CircuitPlayground.setPixelColor(3, 0, 0, 0);

  if (inputVol > 55) CircuitPlayground.setPixelColor(4, 255, 255, 153);
  else CircuitPlayground.setPixelColor(4, 0, 0, 0);

  if (inputVol > 60) CircuitPlayground.setPixelColor(5, 255, 255, 0);
  else CircuitPlayground.setPixelColor(5, 0, 0, 0);

  if (inputVol > 65) CircuitPlayground.setPixelColor(6, 255, 178, 102);
  else CircuitPlayground.setPixelColor(6, 0, 0, 0);

  if (inputVol > 70) CircuitPlayground.setPixelColor(7, 255, 128, 0);
  else CircuitPlayground.setPixelColor(7, 0, 0, 0);

  if (inputVol > 75) CircuitPlayground.setPixelColor(8, 255, 69, 0);
  else CircuitPlayground.setPixelColor(8, 0, 0, 0);

  if (inputVol > 85) CircuitPlayground.setPixelColor(9, 255, 0, 0);
  else CircuitPlayground.setPixelColor(9, 0, 0, 0);
}
