// menu.cpp
#include "menu.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Encoder.h>

extern Adafruit_SSD1306 display;


//rotary encoder setup stuff

const int encoderPinA = 6; // Connect one encoder pin to Teensy pin 5
const int encoderPinB = 5; // Connect the other encoder pin to Teensy pin 6

Encoder myEnc(encoderPinA, encoderPinB);
long oldPosition = 0;
int counter = 0; // main encoder counter for absolute position
int barCounter = 0; // limited encoder counter to feed the bar width variable to


 

void displayControlLoopSetup(){



  
  
  
 // at the moment this is an unused function, may delete in the future if proves to not be needed

}


void displayControlLoop(){
 

  //this is a local implementation for bar values as the counter cannot go above 50, I was trying to create one globabl counter loop for the encoder
  // but couldnt figure out a way to make it work without a large delay between decreasing the bar width from its max value if the user had taken the encoder to say a value of 80
  // the counter wouldnt change the bar width until it went below 50, hence the local specific approach below

  // this may prove to be stupid and inefficient, but that is a problem for future me

 long newPosition = myEnc.read();

  if (newPosition > oldPosition) {
    // Encoder rotated clockwise
    // Increment the counter
    counter++;
    if (counter > 50){
      counter = 50;
    }
    Serial.println("Counter: " + String(counter));
  } else if (newPosition < oldPosition) {
    // Encoder rotated counterclockwise
    // Decrement the counter
    counter--;
    Serial.println("Counter: " + String(counter));
  }

  oldPosition = newPosition;

  barCounter = counter; // maps barCounter to the counter var

  if (barCounter> 50){ // limits the maximum value of barCounter
    barCounter = 50;
  }


  //this encoder implementation seems to work reasonably well, however it makes me question the quality of the..
  //encoder detent system, as going from one detent to the next sometimes triggers more than four signal outputs
  // it may be a problem with the code however I doubt it. this works much better than the previous implementation
  // TO DO: test with higher quality encoders to see if the problem persists


// go from top left to bottom right using rotary encoder and as the counter changes it should update the UI 
//elements to be highlighted when scrolled to 

// will need to add new UI elements in this loop or menu page start loop? not sure which yet

//^^^^^^^^ new UI highlighting display elements should probably be written into the control loop, as it will be easier to read.

}


void displayMenuPageStart() {
    // Implementation for menu page 1
    // ...


  display.clearDisplay(); // clearing display at start of loop//

// bar total width = 50 set bars to half full on start
  int BarWidth1 = barCounter;  // setting the barwidth variable to use the encoder counter is its value, might work?



  int BarWidth2 = 25;
  int BarWidth3 = 25;
  int BarWidth4 = 25;

//begin drawing screen outline//
  display.drawFastVLine(0, 0, 64, WHITE);                               

  display.drawFastVLine(127, 0, 64, WHITE);

  display.drawFastHLine(0, 0, 127, WHITE);

  display.drawFastHLine(0, 63, 127, WHITE);
// finish drawing screen outline

// entering pixel data for lightning bolt icon
  static const unsigned char PROGMEM image_Voltage_bits[] =

  {0x00,0x00,0x00,0x00,0x00,0x40,0x00,0xc0,0x01,0x80,
   0x03,0x80,0x07,0x00,0x0f,0xe0,0x01,0xc0,0x03,0x80,
   0x03,0x00,0x06,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
//end of data entry

//Top of screen size 2 Text Yellow
  display.setTextColor(1);
  display.setTextSize(2);
  display.setCursor(0, 2);
  display.setTextWrap(false);
  display.print("  Effects");

// Main Effects Text Size 1
  display.setTextColor(1);
  display.setTextSize(1);
  display.setCursor(3, 20);
  display.setTextWrap(false);
  display.print("Reverb: ");

  display.setTextColor(1);
  display.setTextSize(1);
  display.setCursor(3, 31);
  display.setTextWrap(false);
  display.print("BitCrush: ");

  display.setTextColor(1);
  display.setTextSize(1);
  display.setCursor(3, 42);
  display.setTextWrap(false);
  display.print("Effect 3:");

  display.setTextColor(1);
  display.setTextSize(1);
  display.setCursor(3, 53);
  display.setTextWrap(false);
  display.print("Effect 3:");

//End of main Text

// Draw Bar outlines
  display.drawRect(72, 20, 50, 8, 1); //Bar 1 (counting from top down)

  display.drawRect(72, 31, 50, 8, 1); //Bar 2 

  display.drawRect(72, 42, 50, 8, 1); //Bar 3

  display.drawRect(72, 53, 50, 8, 1); //Bar 4

//Fill Bars, CHANGE IN FUTURE TO USE BAR WIDTH INT!!!!!!!!!!!!!!!
  display.fillRect(72, 20, BarWidth1, 8, 1);

  display.fillRect(72, 31, BarWidth2, 8, 1);

  display.fillRect(72, 42, BarWidth3, 8, 1);

  display.fillRect(72, 53, BarWidth4, 8, 1);


  display.drawCircle(64, 24, 3,  1);

  display.drawCircle(64, 35, 3,  1);

  display.drawCircle(64, 46, 3,  1);

  display.drawCircle(64, 57, 3,  1);


  display.drawBitmap(2, 2, image_Voltage_bits, 16, 16, 1);

  display.display(); // push data to display

  delay(1); // wait 1 ms before returning to start


}

void displayMenuPage1() {
    // Implementation for menu page 1
    // ...


    display.clearDisplay(); // clearing display at start of loop//



//begin drawing screen outline//
  display.drawFastVLine(0, 0, 64, WHITE);                               

  display.drawFastVLine(127, 0, 64, WHITE);

  display.drawFastHLine(0, 0, 127, WHITE);

  display.drawFastHLine(0, 63, 127, WHITE);
// finish drawing screen outline

// Begin text segment //
  static const char* text = "This is Menu Page 1!"; // set constant character
  float textSize = 1;


  display.setTextSize(textSize);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 16);
  display.print(text);
//end text segment//

// draw reactive bar //

  int width = map(analogRead(A1), 0, 1023, 0, 117); // scales value from analog read pin to display area, needs testing for bounds etc


  if (width < 0) {
    width = 0;  // Set width of bar to 0 if it goes below 0
  }


  display.drawRect(5, 5, width, 5, WHITE); // draws rectangle outline in format ( X coord, Y coord, width, colour)
  display.fillRect(5, 5, width, 5, WHITE); // fills the rectangle defined aboe my matching the paramters and using width variable

  display.display(); // push data to display

  delay(1); // wait 1 ms before returning to start


}

void displayMenuPage2() {
    // Implementation for menu page 2
    // ...

    // Implementation for menu page 1
    // ...


    display.clearDisplay(); // clearing display at start of loop//



//begin drawing screen outline//
  display.drawFastVLine(0, 0, 64, WHITE);                               

  display.drawFastVLine(127, 0, 64, WHITE);

  display.drawFastHLine(0, 0, 127, WHITE);

  display.drawFastHLine(0, 63, 127, WHITE);
// finish drawing screen outline

// Begin text segment //
  static const char* text = "This is Menu Page 2!"; // set constant character
  float textSize = 1;


  display.setTextSize(textSize);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 16);
  display.print(text);
//end text segment//

// draw reactive bar //

  int width = map(analogRead(A1), 0, 1023, 0, 117); // scales value from analog read pin to display area, needs testing for bounds etc


  if (width < 0) {
    width = 0;  // Set width of bar to 0 if it goes below 0
  }


  display.drawRect(5, 5, width, 5, WHITE); // draws rectangle outline in format ( X coord, Y coord, width, colour)
  display.fillRect(5, 5, width, 5, WHITE); // fills the rectangle defined aboe my matching the paramters and using width variable

  display.display(); // push data to display

  delay(1); // wait 1 ms before returning to start
}

void displayMenuPage3() {
    // Implementation for menu page 3
    // ...

    // Implementation for menu page 1
    // ...


    display.clearDisplay(); // clearing display at start of loop//



//begin drawing screen outline//
  display.drawFastVLine(0, 0, 64, WHITE);                               

  display.drawFastVLine(127, 0, 64, WHITE);

  display.drawFastHLine(0, 0, 127, WHITE);

  display.drawFastHLine(0, 63, 127, WHITE);
// finish drawing screen outline

// Begin text segment //
  static const char* text = "This is Menu Page 3!"; // set constant character
  float textSize = 1;


  display.setTextSize(textSize);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 16);
  display.print(text);
//end text segment//

// draw reactive bar //

  int width = map(analogRead(A1), 0, 1023, 0, 117); // scales value from analog read pin to display area, needs testing for bounds etc


  if (width < 0) {
    width = 0;  // Set width of bar to 0 if it goes below 0
  }


  display.drawRect(5, 5, width, 5, WHITE); // draws rectangle outline in format ( X coord, Y coord, width, colour)
  display.fillRect(5, 5, width, 5, WHITE); // fills the rectangle defined aboe my matching the paramters and using width variable

  display.display(); // push data to display

  delay(1); // wait 1 ms before returning to start
}

void displayMenuPage4() {
    // Implementation for menu page 1
    // ...


    display.clearDisplay(); // clearing display at start of loop//



//begin drawing screen outline//
  display.drawFastVLine(0, 0, 64, WHITE);                               

  display.drawFastVLine(127, 0, 64, WHITE);

  display.drawFastHLine(0, 0, 127, WHITE);

  display.drawFastHLine(0, 63, 127, WHITE);
// finish drawing screen outline

// Begin text segment //
  static const char* text = "This is Menu Page 1!"; // set constant character
  float textSize = 1;


  display.setTextSize(textSize);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 16);
  display.print(text);
//end text segment//

// draw reactive bar //

  int width = map(analogRead(A1), 0, 1023, 0, 117); // scales value from analog read pin to display area, needs testing for bounds etc


  if (width < 0) {
    width = 0;  // Set width of bar to 0 if it goes below 0
  }


  display.drawRect(5, 5, width, 5, WHITE); // draws rectangle outline in format ( X coord, Y coord, width, colour)
  display.fillRect(5, 5, width, 5, WHITE); // fills the rectangle defined aboe my matching the paramters and using width variable

  display.display(); // push data to display

  delay(1); // wait 1 ms before returning to start


}

void displayMenuPage5() {
    // Implementation for menu page 1
    // ...


    display.clearDisplay(); // clearing display at start of loop//



//begin drawing screen outline//
  display.drawFastVLine(0, 0, 64, WHITE);                               

  display.drawFastVLine(127, 0, 64, WHITE);

  display.drawFastHLine(0, 0, 127, WHITE);

  display.drawFastHLine(0, 63, 127, WHITE);
// finish drawing screen outline

// Begin text segment //
  static const char* text = "This is Menu Page 1!"; // set constant character
  float textSize = 1;


  display.setTextSize(textSize);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 16);
  display.print(text);
//end text segment//

// draw reactive bar //

  int width = map(analogRead(A1), 0, 1023, 0, 117); // scales value from analog read pin to display area, needs testing for bounds etc


  if (width < 0) {
    width = 0;  // Set width of bar to 0 if it goes below 0
  }


  display.drawRect(5, 5, width, 5, WHITE); // draws rectangle outline in format ( X coord, Y coord, width, colour)
  display.fillRect(5, 5, width, 5, WHITE); // fills the rectangle defined aboe my matching the paramters and using width variable

  display.display(); // push data to display

  delay(1); // wait 1 ms before returning to start


}

void displayMenuPage6() {
    // Implementation for menu page 1
    // ...


    display.clearDisplay(); // clearing display at start of loop//



//begin drawing screen outline//
  display.drawFastVLine(0, 0, 64, WHITE);                               

  display.drawFastVLine(127, 0, 64, WHITE);

  display.drawFastHLine(0, 0, 127, WHITE);

  display.drawFastHLine(0, 63, 127, WHITE);
// finish drawing screen outline

// Begin text segment //
  static const char* text = "This is Menu Page 1!"; // set constant character
  float textSize = 1;


  display.setTextSize(textSize);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 16);
  display.print(text);
//end text segment//

// draw reactive bar //

  int width = map(analogRead(A1), 0, 1023, 0, 117); // scales value from analog read pin to display area, needs testing for bounds etc


  if (width < 0) {
    width = 0;  // Set width of bar to 0 if it goes below 0
  }


  display.drawRect(5, 5, width, 5, WHITE); // draws rectangle outline in format ( X coord, Y coord, width, colour)
  display.fillRect(5, 5, width, 5, WHITE); // fills the rectangle defined aboe my matching the paramters and using width variable

  display.display(); // push data to display

  delay(1); // wait 1 ms before returning to start


}