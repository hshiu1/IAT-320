#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>
#include <Adafruit_NeoPixel.h>

int ledPIN = 8;
int numLEDs = 1;

Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);
Adafruit_NeoPixel pixel(numLEDs, ledPIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pixel.begin();
  pixel.show();
  pixel.setBrightness(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors_event_t event;
  tsl.getEvent(&event);

  if(event.light){
    Serial.print(event.light);
    Serial.println(" lux detected");  
  }
  delay(500);

  if(event.light < 25){
    blink();
  } else {
      pixel.setPixelColor(0,0,0,0);
      pixel.show();
  }
}

void blink() {
    pixel.setPixelColor(0,255,255,255);
    pixel.show();
    delay(50); 
    pixel.setPixelColor(0,0,0,0); 
    pixel.show();
    delay(50);
    pixel.setPixelColor(0,255,255,255);
    pixel.show();
    delay(50);
    pixel.setPixelColor(0,0,0,0); 
    pixel.show();
    delay(50);
}
