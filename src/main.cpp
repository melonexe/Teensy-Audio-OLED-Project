#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <AudioStream.h>
#include "menu.h"
//#include "menus.cpp"

// put function declarations here:
Adafruit_SSD1306 display(128, 64, &Wire, -1, 1000000);  // 1MHz I2C clock

void setup() {

   display.begin(SSD1306_SWITCHCAPVCC, 0x3c); // define display i2c address  // even though 0x3d is supposed to be 128 x 64 only 0x3c works, chinese parts i guess
  delay(100); //wait 100 ms
  display.clearDisplay(); // clear display in init section
  display.display();    //begin display function

}

void loop() 
  {
  
  display.clearDisplay(); // clearing display at start of loop//


  displayMenuPage2();

  delay(1);
  }