/*
 * Generic_Macros_Header.h
 *
 * Created: 8/12/2023 6:20:20 PM
 *  Author: BeZla
 */ 


#ifndef GENERIC_MACROS_HEADER_H_
#define GENERIC_MACROS_HEADER_H_

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

#define SETBIT(REG,BIT)  REG |= (1 << BIT)
#define CLRBIT(REG,BIT)  REG &= ~(1 << BIT)
#define TOGBIT(REG,BIT)  REG ^= (1 << BIT)
#define READBIT(REG,BIT) ((REG >> BIT) & 1)



#endif /* GENERIC_MACROS_HEADER_H_ */