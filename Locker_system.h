/*
 * Locker_system.h
 *
 * Created: 8/29/2023 4:33:02 PM
 *  Author: BeZla
 */ 
#include "Generic_Macros_Header.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include "KEYPAD.h"
#include "EEPROM.h"

#ifndef LOCKER_SYSTEM_H_
#define LOCKER_SYSTEM_H_

void LEDTog100();
void LEDTog3s();
/*
 * Function: Initialize system modules
 * Parameter: no input
 * Output: no return
 */

void systemInit();

/*
 * Function: Set initial password to certain EEPROM addresses valid only if this is first time to use
 * Parameter: no input
 * Output: no return
 */

void checkMemory();

/*
 * Function: Change password of locker
 * Parameter: no input
 * Output: no return
 */

void changePassword();

/*
 * Function: Enter password to open the locker
 * Parameter: no input
 * Output: [uint8_t] password correct or not
 */

uint8_t enterPassword();

/*
 * Function: Take actions on locker when it's open like changing 
 *			 password & activate buzzer if pressing wrong keys.
 * Parameter: no input
 * Output: [uint8_t] locker status. 0: Open		1: Closed
 */
uint8_t takeOpenLockerActions();


#endif /* LOCKER_SYSTEM_H_ */