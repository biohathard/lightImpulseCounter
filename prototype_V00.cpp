// Include the library
#include <TM1637Display.h>
const int analogPin = A0;//пин датчика

// Define the connections pins for display module
#define CLK 3
#define DIO 4

// Create a display object of type TM1637Display
TM1637Display display = TM1637Display(CLK, DIO);

// Create an array that turns all segments ON
const uint8_t allON[] = {0xff, 0xff, 0xff, 0xff};

// Create an array that turns all segments OFF
const uint8_t allOFF[] = {0x00, 0x00, 0x00, 0x00};

int lastValue = 0;//последнее значимое изменение
int valueSdvig = 10;//значимое изменение
int counter = 0;//переменная которая выводится на экран

void setup() {
  //Set the brightness to 5 (0=dimmest 7=brightest)
  display.setBrightness(1);
  //Set all segments ON
  display.setSegments(allON);
  delay(1000);
  display.clear();
}

void loop() {
  int value = analogRead(analogPin);
/////
  unsigned long currentMillis1 = millis();
/////  
  
///// Update the display only if value will be significaly changed
  if (value <= (lastValue - valueSdvig)||value >= (lastValue + valueSdvig)){
    lastValue = value;
    display.clear();
    display.showNumberDec(lastValue);
  }
/////
}
