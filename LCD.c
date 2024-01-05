#include "LCD.h"
#include "LCD_cfg.h"

/*****************************************************************************
* Function Name: LCD_init
* Purpose      : Init LCD in 4 bit mode, clear LCD and show cursor.
* Parameters   : void
* Return value : void
*****************************************************************************/

void LCD_init(){
	
	LCD_CFG_PINS();
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(ENABLE_4BIT_MODE);
	LCD_write_command(0x28);
	LCD_write_command(CURSOR_OFF);	 //Display on Cursor on//
	LCD_write_command(CLEAR_DISPLAY);  //Clear Display//
	LCD_write_command(ENTRY_MODE);  //Entry Mode//
	_delay_ms(20);
	
}

/*****************************************************************************
* Function Name: LCD_write_command
* Purpose      : Send a specific command to LCD
* Parameters   : (uint8_t cmd)
* Return value : void
*****************************************************************************/

void LCD_write_command(uint8_t cmd){
	
	RS(0);
	D7(READBIT(cmd,7));
	D6(READBIT(cmd,6));
	D5(READBIT(cmd,5));
	D4(READBIT(cmd,4));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);
	D7(READBIT(cmd,3));
	D6(READBIT(cmd,2));
	D5(READBIT(cmd,1));
	D4(READBIT(cmd,0));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);
	
}

/*****************************************************************************
* Function Name: LCD_write_char
* Purpose      : Display a char in the LCD
* Parameters   : (uint8_t letter)
* Return value : void
*****************************************************************************/

void LCD_write_char(uint8_t letter){
	
	RS(1);
	D7(READBIT(letter,7));
	D6(READBIT(letter,6));
	D5(READBIT(letter,5));
	D4(READBIT(letter,4));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);
	D7(READBIT(letter,3));
	D6(READBIT(letter,2));
	D5(READBIT(letter,1));
	D4(READBIT(letter,0));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);
	
}

/*****************************************************************************
* Function Name: LCD_write_string
* Purpose      : Display a string in the LCD
* Parameters   : (Pointer to array 'string')
* Return value : void
*****************************************************************************/

void LCD_write_string(uint8_t* string){
	uint8_t i = 0;
	while(string[i] != '\0'){
		LCD_write_char(string[i]);
		i++;
	}
}

/*****************************************************************************
* Function Name: LCD_write_num
* Purpose      : Display a whole number in the LCD
* Parameters   : uint16_t data
* Return value : void
*****************************************************************************/

void LCD_write_num(int32_t data){
	uint16_t Array_of_numbers[5];
	int8_t i;
	if(data == 0){
		LCD_write_char(data + 48);
		return;
	}
	for(i = 0; data != 0; i++){
		Array_of_numbers[i] = data % 10;
		data = data / 10;
	}
	
	for(i = i - 1; i > -1; i--){
		LCD_write_char(48 + Array_of_numbers[i]);
	}

}

