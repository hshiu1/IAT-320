#include "Adafruit_FONA.h"
#include <Adafruit_NeoPixel.h>

int sensorPin = 12;
int ledPin = 8;
int numPix = 1;

#define FONA_RST 6

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
    pixel.setPixelColor(0, 255, 0, 0); //if FONA cannot find a cellular network, LED = RED
    pixel.show();
    while (1);
  } else {
    pixel.setPixelColor(0, 0, 255, 0); //if FONA connects to a cellular network, LED = GREEN
    pixel.show();
  }
  //turn the LED off after 5 seconds
  delay(5000);
  pixel.setPixelColor(0, 0, 0, 0);
  pixel.show();
}

void loop() {
  char sendto[21] = "16043601604"; //target phone number
  char message[100] = "** HELP ** I am in danger ** CALL 911 ** (this is a testing message for IAT 320 Final Project)"; //message to send
  unsigned long duration = pulseIn(sensorPin, HIGH, 10000000); //check pulseIn duration every 10s or until sensor has been touched

  //long touch of sensor to prevent accidental missuse
    //if pulse time is greater than 1million, send the message
  if (duration > 1000000) {
    fona.sendSMS(sendto, message);
  }

  flushSerial();
  while (fona.available()) {
    Serial.write(fona.read());
  }
}

void flushSerial() {
  while (Serial.available())
    Serial.read();
}
