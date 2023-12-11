#include "STD_types.h"
#include "PORT_Config.h"
#include "Bit_utils.h"
#include "PORT.h"

/*
**@brief array to set four ports (A,B,C,D) from 0 to 7 on array PORTA ,8 to 15 PORTB , 16 to 23 PORTC?
24 to 31 PORTD
**@options for every pin 1/DIO_enumOutPut_lOw 2/ DIO_enumOutPut_High  3/DIO_enumInPut_PullDown
4/DIO_enumInPut_PullUp
**@default the defualt is DIO_enumInPut_PullUp
*/

DIO_enumPinConfig_t DIO_arrenuPins_Config[32]={
	/*** PORTA PINS***/
	DIO_enumOutPut_High,				
	DIO_enumInPut_PullUp,	
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,    
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	/*** PORTB PINS***/
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	/***** PORTC PINS **/
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	/**** PORTD PINS **/
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumOutPut_High,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	DIO_enumInPut_PullUp,
	};


