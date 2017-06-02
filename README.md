# Arduino-PCF8575-KeyPad
Arduino Helper Library for PCF857X Interfaced Keypad

It provides a higher abstraction layer for joeyoung/arduino_keypads
[https://github.com/joeyoung/arduino_keypads/blob/master/Keypad_I2C/Keypad_I2C.cpp]

NB: This library supports Arduino/ESP8266.

# Installation
1. Download and place in your Arduino project library

2. Include the header in your main program
    #include <Keypad_Helper.h>
    #include <Wire.h>

3. Create an instance
		<br/>
    // Keypad Instance
    Keypad_Helper &nbsp;kpd(0x20, PCF8575);
    
    <strong>NB:</strong>
		<br/>
    0x20 - PCF857x I2C Address
		<br/>
    PCF8575 - Use PCF8574 otherwise

4. Initialize
  <br/>
    // Keypad init
  <br/>
  Wire.begin();
  <br/>
  kpd.start();
    
    
# Use cases:
1. Text Input
  <br/>
  kpd.getText(10000, &FpDebug)
  <br/>
  
  <strong>NB:</strong>
  <br/>
  1000 - timeout in milliseconds
  <br/>
  FpDebug - a simple callback for debugging
		<br/><br/>
    // Debug Callback
		<br/>
    void FpDebug(const char* s){
		<br/>
    	&nbsp; Serial.print(s);
			<br/>
    }

# TODO:
1. Provide examples
2. Document more use cases
