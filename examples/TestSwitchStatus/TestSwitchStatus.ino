/*

  Modbus-Arduino Example - Test Holding Register (Modbus IP ESP32)
  Read Switch Status on pin GPIO0
  Copyright by André Sarmento Barbosa
  http://github.com/andresarmento/modbus-arduino
*/

#include <Modbus.h>
#include <ModbusIP_ESP32.h>

//Modbus Registers Offsets (0-9999)
const int SWITCH_ISTS = 100;
//Used Pins
const int switchPin = 0; //GPIO0

//ModbusIP object
ModbusIP mb;

void setup() {
    //Config Modbus IP
    mb.config("your_ssid", "your_password");
    //Set ledPin mode
    pinMode(switchPin, INPUT);
    // Add SWITCH_ISTS register - Use addIsts() for digital inputs
    mb.addIsts(SWITCH_ISTS);
}

void loop() {
   //Call once inside loop() - all magic here
   mb.task();

   //Attach switchPin to SWITCH_ISTS register
   mb.Ists(SWITCH_ISTS, digitalRead(switchPin));
}
