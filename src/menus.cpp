// menu.cpp
#include "menu.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

extern Adafruit_SSD1306 display;

void displayMenuPageStart() {
    // Implementation for menu page 1
    // ...


  display.clearDisplay(); // clearing display at start of loop//

// bar total width = 50 set bars to half full on start
  int BarWidth1 = map((analogRead(A1)),0, 1023, 0, 50);  // this mostly works however there is a weird jump behaviour in the middle of the pot range, Maybe to do with map function ? measure voltage and then do serial debugging ?
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