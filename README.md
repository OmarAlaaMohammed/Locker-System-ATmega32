# Description
 Software for hotel room lockers that allows guests to secure their belongings by generating a password, which can be subsequently modified but remains intact even in the event of a power failure in the microcontroller.

# Details

First time password saved is 0000.
Used should enter 0000 to open locker at first time.
To change password user should press on ‘/’ on the keypad, red LED will be on for 3 second then off after then user should enter 4 digit password then press on ‘/’ once again to confirm it.
Pressing on any button will make the buzzer on for 100msec.
To close the locker, you should press only on ‘C’.
To open the locker, enter 4 digit password.
If you enter wrong password, a buzzer will be on for 3 second then off re-enter password again.
To reset password and locker is closed (if user forget it): developer should flash software again.

# System Components
* HAL:
Keypad
LCD
Buzzer
LED's

* MCAL:
EEPROM

   


