/*
 * Locker_System.c
 *
 * Created: 8/29/2023 3:13:57 PM
 * Author : BeZla
 */ 

#include "Locker_system.h"

int main(void)
{	
	systemInit();									//System initialization
	uint8_t locker_status = 1;						//Variable holds the locker status whether its closed or open 1 => Closed, 0 => Open//
	LCD_write_string("Closed");						//Display 'closed' on LCD
	checkMemory();									//If its the first time the password will be set to '0000'
	uint8_t errorStatus = enterPassword();			//Variable to hold 1 if the password doesn't match and 0 if the password match	
	
	while(errorStatus){								//The locker will remain closed until the user enters the correct password
		errorStatus = enterPassword();				//The function "enterPassword" returns 0 ==> Correct password, and 1 ==> Wrong Password
	}
	
		locker_status = 0;							//Locker is now open
		
    while (1) 
    {
		if(!locker_status){
			LCD_write_command(CLEAR_DISPLAY);
			LCD_write_command(FIRST_LINE(0));
			LCD_write_string("Opened");
			SETBIT(PORTB,PB1);
			locker_status = takeOpenLockerActions();
		}
		
		else{
			LCD_write_command(CLEAR_DISPLAY);
			LCD_write_command(FIRST_LINE(0));
			LCD_write_string("Closed");
			CLRBIT(PORTB,PB1);
			_delay_ms(100);
			
			errorStatus = enterPassword();
	
			while(errorStatus){
				errorStatus = enterPassword();
			}
			

			locker_status = 0;
			
		}
	}
		}

