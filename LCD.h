/*
 * LCD.h
 *
 * Created: 8/18/2023 8:00:31 PM
 *  Author: BeZla
 */ 
#include "Generic_Macros_Header.h"

#ifndef LCD_H_
#define LCD_H_


	//Configure LCD port
	void LCD_init();
	
	//To send command to LCD
	void LCD_write_command(uint8_t);
	
	//To send data to LCD
	void LCD_write_char(uint8_t);
	
	//To write complex text
	void LCD_write_string(uint8_t*);
	
	//To write a number
	void LCD_write_num(int32_t);



#endif /* LCD_H_ */