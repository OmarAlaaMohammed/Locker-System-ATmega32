/*
 * CFile1.c
 *
 * Created: 8/29/2023 4:32:31 PM
 *  Author: BeZla
 */ 

#include "Locker_system.h"


void LEDTog3s(){
	SETBIT(PORTB,PB0);
	_delay_ms(3000);
	CLRBIT(PORTB,PB0);
}


void LEDTog100(){
	SETBIT(PORTB,PB0);
	_delay_ms(100);
	CLRBIT(PORTB,PB0);
}

void systemInit(){
	LCD_init();
	Keypad_init();
	LCD_write_command(FIRST_LINE(0));
	SETBIT(DDRB,PB0);	//Setting PORTB, PIN4 as an output (buzzer)
	SETBIT(DDRB,PB1);
}

void checkMemory(){
	
	/*Read memory locations that hold the password*/
	uint8_t data[4];
	data[0] = EEPROM_read(48);
	data[1] = EEPROM_read(49);
	data[2] = EEPROM_read(50);
	data[3] = EEPROM_read(51);
	
	
	/*First time to use the EEPROM the initial values are 255. Make initial password 0000*/
	
	if((data[0] == 255) && (data[1] == 255) && (data[2] == 255) && (data[3] == 255)){
		EEPROM_write(48,0);
		EEPROM_write(49,0);
		EEPROM_write(50,0);
		EEPROM_write(51,0);
	}
}

uint8_t enterPassword(){
	uint8_t passwordEntered[4], passwordSaved[4];
	/* Get the 4 chars of the password from keypad */
	LCD_write_command(SECOND_LINE(0));
	
	for(uint8_t s = 0; s < 4; s++){
			do{
				
			}while(Keypad_read() == 200);
			LCD_write_char('*');
			passwordEntered[s] = (Keypad_read() - 48);
			LEDTog100();
			while(Keypad_read() != 200){}
			_delay_ms(150);
		}	

	
	passwordSaved[0] = EEPROM_read(48);
	passwordSaved[1] = EEPROM_read(49);
	passwordSaved[2] = EEPROM_read(50);
	passwordSaved[3] = EEPROM_read(51);

	
	
	if ((passwordSaved [0] == passwordEntered [0]) && (passwordSaved [1] == passwordEntered [1]) &&
	(passwordSaved [2] == passwordEntered [2]) && (passwordSaved [3] == passwordEntered [3]))
	{
		
		return 0;
	}
	
	LCD_write_command(CLEAR_DISPLAY);
	LCD_write_command(SECOND_LINE(7));
	LCD_write_string("TRY_AGAIN");
	LEDTog3s();
	LCD_write_command(CLEAR_DISPLAY);
	LCD_write_command(FIRST_LINE(0));
	LCD_write_string("CLOSED");
	return 1;
	}
	
	
void changePassword(){
	uint8_t newPassword[4];
	/* Get the new 4 chars of the password from keypad */
	for(uint8_t t = 0; t < 4; t++){
		do{
			
		}while(Keypad_read() == 200); 
		LCD_write_char('*');
		newPassword[t] = (Keypad_read() - 48);
		LEDTog100();
		while(Keypad_read() != 200){}
		_delay_ms(100);
	}
	
	/*Write new password to memory locations holding password*/
	while(Keypad_read() != '/'){
		
	}
	
	LCD_write_command(CLEAR_DISPLAY);
	
	EEPROM_write(48,newPassword[0]);
	EEPROM_write(49,newPassword[1]);
	EEPROM_write(50,newPassword[2]);
	EEPROM_write(51,newPassword[3]);
	
	_delay_ms(300);

	}
	
uint8_t takeOpenLockerActions(){
	
	do{
		
	}while(Keypad_read() == 200);

	if(Keypad_read() == '/'){
		LCD_write_command(SECOND_LINE(8));
		LCD_write_string("NEWPASS");
		LCD_write_command(SECOND_LINE(0));
		_delay_ms(100);
		LEDTog3s();
		changePassword();
	}
	
	if(Keypad_read() == '*'){
		LCD_write_command(CLEAR_DISPLAY);
		while(Keypad_read() == '*'){}
		return 1;
	}

	else{
		LEDTog100();
		return 0;
	}
	
	}