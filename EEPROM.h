/*
 * EEPROM.h
 *
 * Created: 8/19/2023 6:57:24 PM
 *  Author: BeZla
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "Generic_Macros_Header.h"

void EEPROM_write(uint16_t addr, uint8_t data);
uint8_t EEPROM_read(uint16_t);



#endif /* EEPROM_H_ */