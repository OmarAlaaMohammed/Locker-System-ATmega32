#include "KEYPAD.h"
#include "KEYPAD_CFG.h"


const uint8_t keypad_matrix[] = {
	'7' , '8' , '9' , '/',
	'4' , '5' , '6' , '*',
	'1' , '2' , '3' , '-',
	'C' , '0' , '=' , '+',
};

/*****************************************************************************
* Function Name: Keypad_init
* Purpose      : Initalizing the keypad
* Parameters   : void
* Return value : void
*****************************************************************************/

void Keypad_init(void)
{
	KEYPAD_PORT_INIT();
}

/*****************************************************************************
* Function Name: Keypad_read
* Purpose      : Read the pushed key on the keypad
* Parameters   : void
* Return value : Value of the key pressed (uint8_t)
*****************************************************************************/

uint8_t Keypad_read(void){
	uint8_t i = 0;
	
	 for(i = 0; i < 4; i++){
		 switch(i){
			 case 0:  KEYPAD_A(0);	 KEYPAD_B(1);	 KEYPAD_C(1);	 KEYPAD_D(1); break;
			 case 1:  KEYPAD_A(1);	 KEYPAD_B(0);	 KEYPAD_C(1);	 KEYPAD_D(1); break;
			 case 2:  KEYPAD_A(1);	 KEYPAD_B(1);	 KEYPAD_C(0);	 KEYPAD_D(1); break;
			 case 3:  KEYPAD_A(1);	 KEYPAD_B(1);	 KEYPAD_C(1);    KEYPAD_D(0); break;
		 }
		 
		if(KEYPAD_1 == 0){return keypad_matrix[4 * i + 0];}
		if(KEYPAD_2 == 0){return keypad_matrix[4 * i + 1];}
		if(KEYPAD_3 == 0){return keypad_matrix[4 * i + 2];}
		if(KEYPAD_4 == 0){return keypad_matrix[4 * i + 3];}
		_delay_ms(20);
	}

	return 200;
}
