#include "Adafruit_FONA.h"
#include <Adafruit_NeoPixel.h>

int sensorPin = 12;
int ledPin = 8;
int numPix = 1;

int lastState = LOW;      // the previous state from the input pin
int currentState;         // the current reading from the input pin

#define FONA_RST 6

// this is a large buffer for replies
char replybuffer[255];

#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
#include <SoftwareSerial.h>

#define FONA_RX 10
#define FONA_TX 9

SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);
SoftwareSerial *fonaSerial = &fonaSS;

#else
HardwareSerial *fonaSerial = &Serial1;

#endif

Adafruit_FONA fona = Adafruit_FONA(FONA_RST);

uint8_t readline(char *buff, uint8_t maxbuff, uint16_t timeout = 0);

uint8_t type;

Adafruit_NeoPixel pixel(numPix, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(sensorPin, INPUT);
  pixel.begin();
  pixel.setBrightness(50);

  fonaSerial->begin(4800);
  if (! fona.begin(*fonaSerial)) {
    pixel.setPixelColor(0, 255, 0, 0);
    pixel.show();
    while (1);
  }
  pixel.setPixelColor(0, 0, 255, 0);
  pixel.show();

  delay(1000);
}

void loop() {
  
  char sendto[21] = "16043601604";
  char message[100] = "IAT 320 Final Prototype presentation testing...";
  currentState = digitalRead(sensorPin);

  if (lastState == LOW && currentState == HIGH) {
    fona.sendSMS(sendto, message);
  }

  // save the the last state
  lastState = currentState;
  flushSerial();
  while (fona.available()) {
    Serial.write(fona.read());
  }
}

void flushSerial() {
  while (Serial.available())
    Serial.read();
}
