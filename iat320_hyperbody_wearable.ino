#include <Adafruit_CircuitPlayground.h>

float inputVol;

int ledPin = A1;
//#define LED_PIN    A1
int numPix = 2;

Adafruit_CPlay_NeoPixel pixel = Adafruit_CPlay_NeoPixel(numPix, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
 // Serial.begin(9600);
  CircuitPlayground.begin();
  pixel.begin();
}

void loop() {
  inputVol = CircuitPlayground.mic.soundPressureLevel(100) - 15;
  volumeWheel();
  //Serial.println(A1);
  moodLED();
}

void moodLED() {
    pixel.setBrightness(50);
    pixel.show();
  if (inputVol > 0 && inputVol < 40) {
    pixel.setPixelColor(0, 0, 0, 255);
  } else if (inputVol > 40 && inputVol < 60){
      pixel.setPixelColor(0, 0, 255, 0);
    } else if (inputVol > 60 && inputVol < 70){
        pixel.setPixelColor(0, 255, 255, 0);
      } else if (inputVol > 70) {
        pixel.setPixelColor(0, 255, 0, 0);
        }
}

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

  if (inputVol > 75) CircuitPlayground.setPixelColor(8, 255, 102, 102);
  else CircuitPlayground.setPixelColor(8, 0, 0, 0);

  if (inputVol > 85) CircuitPlayground.setPixelColor(9, 255, 0, 0);
  else CircuitPlayground.setPixelColor(9, 0, 0, 0);
}
