//lib dependencies//
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <AudioStream.h>
//local source dependencies
#include <menu.h>
#include <Audio.h>
#include <sawtooth.h>
#include <FaustTest.h>

//#include "menus.cpp"

// put function declarations here:

Adafruit_SSD1306 display(128, 64, &Wire, -1, 1000000);  // 1MHz I2C clock

// button pin defs

const int buttonPin1 = 7; 
const int buttonPin2 = 8; 
const int buttonPin3 = 9; 
const int ledPin = 13;    // built-in LED pin



void setup() {

  // display setup begin

  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); // define display i2c address  // even though 0x3d is supposed to be 128 x 64 only 0x3c works, chinese parts i guess
  delay(100); //wait 100 ms
  display.clearDisplay(); // clear display in init section
  display.display();    //begin display function



// end of display setup

// button digital pin setup

  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
// end of button setup

 


//serial connection start at 9600 baudrate
  Serial.begin(9600);




//Faust and audio setup shit
setupFaust();


}

void loop() 
  {
  
  display.clearDisplay(); // clearing display at start of loop//

  displayControlSetup();

  displayControlLoop();

  buttonControl();

  displayMenuPageStart();

  loopFaust();

 // display.display();


 
  
 //displayMenuPage1();

  

 // displayMenuPage2();

  

 //  displayMenuPage3();

  

  
  }