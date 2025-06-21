// menu.cpp
#include "menu.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// No Encoder includes or variables

extern Adafruit_SSD1306 display;

static const unsigned char PROGMEM image_Layer_18_bits[] = {0x00,0x00,0x00,0x00,0x00,0x40,0x00,0xc0,0x01,0x80,0x03,0x80,0x07,0x00,0x0f,0xe0,0x01,0xc0,0x03,0x80,0x03,0x00,0x06,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

// Button pin assignments
const int BUTTON_UP    = A4; // was LEFT, now UP
const int BUTTON_DOWN  = A6; // was RIGHT, now DOWN
const int BUTTON_LEFT  = A5; // was UP, now LEFT
const int BUTTON_RIGHT = A7; // was DOWN, now RIGHT

const int BUTTON_SELECT = A8; // Select button, can be used to toggle In/Out state

// Track previous button state for debouncing/select edge detection
bool lastSelectState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

const int POT_PIN = A1;

const int numRows = 4;
const int numCols = 3;

// Backend 2D array to represent the UI grid (can store IDs, states, etc.)
int uiGrid[numRows][numCols] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {9, 10, 11}
};

struct Pair {
    int x; 
    int y;
};

Pair drawLoc[numRows][numCols] = {
    { {1, 18}, {3, 4}, {5, 6} },
    { {1, 29}, {9, 10}, {11, 12} },
    { {1, 40}, {9, 10}, {11, 12} },
    { {1, 51}, {9, 10}, {11, 12} },
    //change coords!!!!!!!!!!!!!!!
};

struct EffectUI {
    const char* name;   // Effect name
    bool enabled;       // In/Out state
    int value;          // Value for the bar (0-50, for example)
};

const int numEffects = 4;

EffectUI effects[numEffects] = {
    {"Reverb",   false, 25},
    {"BitCrush", false, 30},
    {"Effect 3", false, 20},
    {"Effect 4", false, 40}
};

// UI navigation state
int currentRow = 0; // 0-3 (effect row)
int currentCol = 0; // 0: name, 1: in/out, 2: value

void displayControlSetup(){
    pinMode(BUTTON_UP, INPUT_PULLUP);
    pinMode(BUTTON_LEFT, INPUT_PULLUP);
    pinMode(BUTTON_DOWN, INPUT_PULLUP);
    pinMode(BUTTON_RIGHT, INPUT_PULLUP);
    pinMode(BUTTON_SELECT, INPUT_PULLUP); // Select button for toggling In/Out state
}

void buttonControl() {
    // Navigation
    if (digitalRead(BUTTON_LEFT) == HIGH && currentCol > 0) {
        currentCol--;
    }
    if (digitalRead(BUTTON_RIGHT) == HIGH && currentCol < 2) {
        currentCol++;
    }
    if (digitalRead(BUTTON_UP) == HIGH && currentRow > 0) {
        currentRow--;
    }
    if (digitalRead(BUTTON_DOWN) == HIGH && currentRow < numEffects - 1) {
        currentRow++;
    }

     //Action: Toggle In/Out if on column 1
      if (currentCol == 1 && digitalRead(BUTTON_SELECT) == HIGH) {
       effects[currentRow].enabled = !effects[currentRow].enabled;
    }

    delay(200); // Debounce
}

// Example usage: get the current UI element ID
int getCurrentUIElement() {
    return uiGrid[currentRow][currentCol];
}

void displayControlLoop(){
    // Potentiometer controls effect value when value column is selected
    if (currentCol == 2) {
        int potValue = analogRead(POT_PIN); // 0-1023
        int mappedValue = map(potValue, 0, 1023, 0, 50); // Map to effect value range
        effects[currentRow].value = mappedValue;
    }
}

void displayMenuPageStart() {
    display.clearDisplay();

    display.setTextColor(1);
    display.setTextSize(2);
    display.setTextWrap(false);
    display.setCursor(0, 2);
    display.print("  Effects");

    display.drawBitmap(2, 2, image_Layer_18_bits, 16, 16, 1);

    for (int i = 0; i < numEffects; i++) {
        int y = 20 + i * 11; // Adjust as needed for spacing

        // Effect Name
        display.setCursor(3, y);
        display.setTextSize(1);
        display.print(effects[i].name);

        // In/Out Button
        display.drawCircle(64, y + 4, 3, 1);
        if (effects[i].enabled) {
            display.fillCircle(64, y + 4, 2, 1);
        }

        // Value Bar
        display.drawRect(72, y, 50, 8, 1);
        display.fillRect(72, y, effects[i].value, 8, 1);

        // Highlight current selection
        if (i == currentRow) {
            int highlightX = (currentCol == 0) ? 3 : (currentCol == 1) ? 59 : 72; // 61 -> 60
            int highlightW = (currentCol == 0) ? 55 : (currentCol == 1) ? 10 : 50;
            display.drawRect(highlightX, y + -1, highlightW, 10, 1);
        }
    }

    display.display();
}

void displayMenuPage1() {}
void displayMenuPage2() {}
void displayMenuPage3() {}
void displayMenuPage4() {}
void displayMenuPage5() {}
void displayMenuPage6() {}