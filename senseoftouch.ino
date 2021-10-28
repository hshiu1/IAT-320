#include <Adafruit_CircuitPlayground.h>

int capThreshold = 200;
uint8_t pads[] = {3, 2, 0, 6, 9, 10};
uint8_t numberOfPads = sizeof(pads)/sizeof(uint8_t);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(CircuitPlayground.readCap(A1));
  if(CircuitPlayground.readCap(A1) > capThreshold){
    CircuitPlayground.playTone(523, 500, false);
  }
  if(CircuitPlayground.readCap(A2) > capThreshold){
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
  }
  if(CircuitPlayground.readCap(A3) > capThreshold){
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
  }
  if(CircuitPlayground.readCap(A4) > capThreshold){
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
    
  }
  if(CircuitPlayground.readCap(A5) > capThreshold){
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
  }
  if(CircuitPlayground.readCap(A6) > capThreshold){
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
    delay(150);
    CircuitPlayground.playTone(523, 500, false);
  }
 
}
