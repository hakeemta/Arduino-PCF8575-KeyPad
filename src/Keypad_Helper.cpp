/***************************************************
  This is a helper library for Keypad
 ****************************************************/

#include "Keypad_Helper.h"

// Init
void Keypad_Helper::start(){
  begin(makeKeymap(keys));
}

// Get Text from keypad
char* Keypad_Helper::getText(uint16_t timeout, Pt2Debug::Char _debug = NULL){
  int start_at = millis();
  memset(text, 0, 10);
  index = 0;
  timelapse = millis();
  while(millis()-start_at < timeout){
    yield();
    key = getKey();

    if(key != NO_KEY){
      // Enter is pressed, break
      if(key == 'D'){
        // Do something
        break;
      }
      else if(key == 'C'){
        text[index - 1] = '\0';
        if(index > 0)
          index--;
      }
      else {
        // Check for the char
        findChar(key);
        timelapse = millis();
      }
      // Display char
      if(_debug != NULL && text != 0){
        // _debug(text);
        // _debug("\r\n");
        Serial.println(text);
      }

      // Allow time
      start_at = millis();
    }

    // Idle, reinitialize params
    if(millis()-timelapse > waittime){
      presses = 0;
      timelapse = millis();
    }
  }
  return text;
}

char Keypad_Helper::findChar(char key){
  char _char;
  // If not multiplexed number 0 - 9, return key
  if(key < '0' || key > '9'){
    return key;
  }
  // If not the same key, presses more than 4 or end reached
  if(key != last_key){
    presses = 0;
  }
  // Maintain position if pressed more than once
  if(presses > 0){
    index--;
  }
  if(presses%5 == 0 || chars[key-'0'][presses%5] == '\0'){
    presses = 5;
  }
  // Lookup the char matrix
  _char = chars[key-'0'][presses%5];
  text[index] = _char;
  presses++;
  Serial.println(presses);
  index++;

  last_key = key;
  return _char;
}
