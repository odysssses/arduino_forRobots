#include "EEPROM2byte.h"

//EEPROM2byte::EEPROM2byte() {}

void EEPROM2byte::writeEEPROM(int address, unsigned int value) {
  EEPROM.write(address, (value >> 8) & 0xFF);
  EEPROM.write(address + 1, value & 0xFF);
}

unsigned int EEPROM2byte::readEEPROM(int address) {
  return ((unsigned int)EEPROM.read(address) << 8) | EEPROM.read(address + 1);
}
