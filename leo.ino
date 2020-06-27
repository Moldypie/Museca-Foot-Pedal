/* based on code by Knuckleslee
 * http://knuckleslee.blogspot.com/2018/06/RhythmCodes.html
 * 
 * This is to use with an arduino leonardo for your museca foot pedal. 
 * This works with one photo interrupter and three lights, RGB
 * Code was written to work with the official arcade pedal. 
 * Note a 12v power supply will be needed for the lights, but not the photosensor.
 * 
 * Arduino Joystick Library
 * https://github.com/MHeironimus/ArduinoJoystickLibrary/
 * mon's Arduino-HID-Lighting
 * https://github.com/mon/Arduino-HID-Lighting
 */
#include <Joystick.h>
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD, 1, 0,
 false, false, false, false, false, false, false, false, false, false, false);

boolean hidMode;
byte SinglePins[] = {9,10,11};//RGB
byte PedalPin = A0;

void setup() {
  Serial.begin(9600) ;
  Joystick.begin(false);
  // light mode detection
  hidMode = true;
} //end setup

void loop() {
  // read pedal
  if(analogRead(PedalPin) > 0){
    Joystick.setButton (0,1);
  }else{
    Joystick.setButton (0,0);
  }
  Joystick.sendState();
}//end loop
