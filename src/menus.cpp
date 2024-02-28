// menu.cpp
#include "menu.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Encoder.h>

extern Adafruit_SSD1306 display;


//rotary encoder setup stuff

const int encoderPinA = 6; // Connect one encoder pin to Teensy pin 5
const int encoderPinB = 5; // Connect the other encoder pin to Teensy pin 6

const int button1 = 7; // replace with the actual pin number for button 1
const int button2 = 8; // replace with the actual pin number for button 2
const int button3 = 9; // replace with the actual pin number for button 3
const int button4 = 10; 

// encoder variables
Encoder myEnc(encoderPinA, encoderPinB);
long oldPosition = 0;
int counter = 0; // main encoder counter for absolute position
int barCounter = 0; // limited encoder counter to feed the bar width variable to

const int numRows = 4;
const int numCols = 3;

int currentCol = 0;  // Current X position
int currentRow = 0;  // Current Y position





struct Pair {
    int x; 
    int y;
};

Pair drawLoc[numRows][numCols] = {
    { {1, 18}, {3, 4}, {5, 6} },
    { {1, 29}, {9, 10}, {11, 12} },
    { {1, 40}, {9, 10}, {11, 12} },
    { {1, 51}, {9, 10}, {11, 12} },
    
};



int drawLocX = drawLoc[currentCol][currentRow].x ;
int drawLocY = drawLoc[currentCol][currentRow].y ;


void displayControlSetup(){

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

}


void buttonControl(){


  if (digitalRead(button1) == HIGH){
    currentCol--;

    Serial.println("left button pressed!");
  }

   if (digitalRead(button2) == HIGH){
    currentRow--;

    Serial.println("UP button pressed!");
  }

   if (digitalRead(button3) == HIGH){
    currentCol++;

    Serial.println("Right button pressed!");
  }

   if (digitalRead(button4) == HIGH){
    currentRow++;

    Serial.println("Down button pressed!");
  }






  if (digitalRead(button1) == HIGH){

    currentCol--;

    if (currentCol < 0){

      currentCol = 0;
    }

  }

  if (digitalRead(button2) == HIGH){

    currentRow--;

    if (currentRow < 0){

      currentRow = 0;
    }

  }


  if (digitalRead(button3) == HIGH){

    currentCol++;

    if (currentCol > 2){

      currentCol = 2;
    }

  }

  if (digitalRead(button4) == HIGH){

    currentRow++;

    if (currentRow > 3){

      currentRow = 3;
    }

  }


}

void displayControlLoop(){
 
  //this is a local implementation for bar values as the counter cannot go above 50, I was trying to create one globabl counter loop for the encoder
  // but couldnt figure out a way to make it work without a large delay between decreasing the bar width from its max value if the user had taken the encoder to say a value of 80
  // the counter wouldnt change the bar width until it went below 50, hence the local specific approach below




 //int yDispCoord =

  
// the plan is to have 1 more 2d array which holds all the display element draw pixel coords for
// their respective UI elements, this way there doesnt have to be any dumb shit going on in the display loop

// leaving this in a bad state rn but this has annoyed me too much so im done lol





                
                

                  display.drawRect(drawLocX,drawLocY, 44, 11, 1);


                


            













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

  //New approach, using buttons to navigate menu now, encoder approach was kinda stupid tbh


  
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
   

}

void displayMenuPage2() {
 
}

void displayMenuPage3() {
 
}

void displayMenuPage4() {
   

}

void displayMenuPage5() {
   

}

void displayMenuPage6() {
    


}