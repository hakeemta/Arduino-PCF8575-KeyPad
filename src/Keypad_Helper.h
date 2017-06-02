/***************************************************
  This is a helper library for Keypad
 ****************************************************/

#include <Keypad_I2C.h>
#include <Keypad.h>
#include <Pt2Debug.h>


class Keypad_Helper: public Keypad_I2C {
 public:
   Keypad_Helper(byte address, byte width = 1):
   Keypad_I2C(makeKeymap(keys), rowPins, colPins, ROWS, COLS, address, width) {
     ;
   }

   void start(void);
   char* getText(uint16_t timeout, Pt2Debug::Char _debug);
   char* getNumber(uint16_t timeout, Pt2Debug::Char _debug);
   char text[20];

 private:
   char findChar(char key);

   static const byte ROWS = 4; //four rows
   static const byte COLS = 4; //three columns
   char keys[ROWS][COLS] = {
     {'1', '2', '3', 'A'},
     {'4', '5', '6', 'B'},
     {'7', '8', '9', 'C'},
     {'*', '0', '#', 'D'}
   };

   // Digitran keypad, bit numbers of PCF8575 i/o port
   byte rowPins[ROWS] = {0, 1, 2, 3}; //connect to the row pinouts of the keypad
   byte colPins[COLS] = {4, 5, 6, 7}; //connect to the column pinouts of the keypad
   char key;
   int presses = 0;
   long timelapse = millis();
   int index = 0;
   int waittime = 500;
   char last_key = '\0';

   char chars[10][5] = {
     {' ', '\0', '\0', '\0', '\0'},
     {'.', ',', '@', '1', '\0'},
     {'a', 'b', 'c', '2', '\0'},
     {'d', 'e', 'f', '3', '\0'},
     {'g', 'h', 'i', '4', '\0'},
     {'j', 'k', 'l', '5', '\0'},
     {'m', 'n', 'o', '6', '\0'},
     {'p', 'q', 'r', 's', '7'},
     {'t', 'u', 'v', '8', '\0'},
     {'w', 'x', 'y', 'z', '9'}
   };
};
