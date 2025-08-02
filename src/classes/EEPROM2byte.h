#ifndef EEPROM2byte_h
#define EEPROM2byte_h

#include <Arduino.h>
#include <EEPROM.h>

class EEPROM2byte {
  public:
    //EEPROM2byte();
    void writeEEPROM(int address, unsigned int value);
    unsigned int readEEPROM(int address);
};


#endif
