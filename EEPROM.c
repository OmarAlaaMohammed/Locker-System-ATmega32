/*
 * EEPROM.c
 *
 * Created: 8/19/2023 6:42:55 PM
 * Author : BeZla
 */ 

#include "EEPROM.h"

/*****************************************************************************
* Function Name: EEPROM_write
* Purpose      : Enable writing in the EEPROM
* Parameters   : uint16_t add, uint8_t data
* Return value : void
*****************************************************************************/

void EEPROM_write(uint16_t addr, uint8_t data){
	
	while(READBIT(EECR,EEWE) == 1);		//Making sure that the EEPROM is not in writing stage
	EEAR = addr;						//Address and data are correctly set up
	EEDR = data;
	SETBIT(EECR,EEMWE);					//EEPROM master write enable
	SETBIT(EECR,EEWE);					//EEPROM write enable
}

/*****************************************************************************
* Function Name: EEPROM_read
* Purpose      : Enable reading from the EEPROM
* Parameters   : Address to read from (uint16_t)
* Return value : Value that the address holds (uint8_t)
*****************************************************************************/

uint8_t EEPROM_read(uint16_t addr){
	while(READBIT(EECR,EEWE) == 1);		//Making sure that the EEPROM is not in writing stage//
	EEAR = addr;						//Address is correctly set up//
	SETBIT(EECR,EERE);					//EERE = EEPROM Read Enable//
	return EEDR;						//Return the data read in the address//
}

