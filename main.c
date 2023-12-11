/*
 * main.c
 *
 * Created: 11/27/2023 10:30:37 AM
 *  Author: karem
 */ 

#include <xc.h>
#include "STD_types.h"
#include "Bit_utils.h"
#include <util/delay.h>
#include "PORT_Config.h"
#include "PORT.h"
extern DIO_enumPinConfig_t DIO_arrenuPins_Config[32];

int main(void)
{
	DIO_arrenuPins_Config[1]=DIO_enumOutPut_High;
	DIO_arrenuPins_Config[22]=DIO_enumOutPut_Low;

	PORT_Init();
	int flag =1;

    while(1)
    {
		
	}
}

/*char flag=0,x=0,y=0;
DDRA=0b00001111;
PORTA=0b00010000;
while(1)
{		DIO_enumReadState(DIO_enumPortA,DIO_enumPin5,&flag);

	flag=((PINA>>4)&1);
	if(flag==0)
	{
		(PORTA)++;
		_delay_ms(200);
	}
}*/