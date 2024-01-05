/*
 * LCD_cfg.h
 *
 * Created: 8/18/2023 8:44:40 PM
 *  Author: BeZla
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#define LCD_CFG_PINS() DDRA |= 0b11111100;

#define FIRST_LINE(x)	  (0x80 + x)
#define SECOND_LINE(x)	  (0xc0 + x)
#define ENABLE_4BIT_MODE   0x2
#define CLEAR_DISPLAY	   0x01
#define CURSOR_ON		   0x0E
#define CURSOR_OFF		   0x0C
#define SHIFT_RIGHT		   0x18
#define SHIFT_LEFT         0x1C
#define ENTRY_MODE		   0x16

#define RS(x) if(x == 0) CLRBIT(PORTA, PA2); else SETBIT(PORTA, PA2);
#define EN(x) if(x == 0) CLRBIT(PORTA, PA3); else SETBIT(PORTA, PA3);
#define D4(x) if(x == 0) CLRBIT(PORTA, PA4); else SETBIT(PORTA, PA4);
#define D5(x) if(x == 0) CLRBIT(PORTA, PA5); else SETBIT(PORTA, PA5);
#define D6(x) if(x == 0) CLRBIT(PORTA, PA6); else SETBIT(PORTA, PA6);
#define D7(x) if(x == 0) CLRBIT(PORTA, PA7); else SETBIT(PORTA, PA7);


#endif /* LCD_CFG_H_ */