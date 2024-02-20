// menu.cpp
#include "menu.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

extern Adafruit_SSD1306 display;

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
