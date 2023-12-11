#ifndef PORT_H_
#define PORT_H_

#define PIN_INPUT	0
#define PIN_OUTPUT	1
#define PIN_LOW		0
#define PIN_HIGH	1

/**
*@brief   : listing the available options for pins
*/
typedef enum{
	DIO_enumPin0,
	DIO_enumPin1,
	DIO_enumPin2,
	DIO_enumPin3,
	DIO_enumPin4,
	DIO_enumPin5,
	DIO_enumPin6,
	DIO_enumPin7
}DIO_enumPinNum_t;
/**
*@brief the ports options at atmega32
 */
typedef enum{
	DIO_enumPortA,
	DIO_enumPortB,
	DIO_enumPortC,
	DIO_enumPortD
	}DIO_enumPorts_t;
	
/* listing the type of errors */
typedef enum{
	/**
	 *@brief  : defult value as things goes wrong if nothing modified it
	 */
	DIO_enumNok,
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	DIO_enumOk,
	/**
	 *@brief : NULL Pointer is passed.
	 */
	DIO_enumNullPointer,
	/**
	 *@brief : Select Port Not exist ! .
	 */
	DIO_enumWrongPort,
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	DIO_enumWrongPin,
	/**
	 *@brief : Select Configuration type Not Found .
	 */
	DIO_enumWrongConfig
	}DIO_enumErrors_t;

typedef enum{
	/**
	 *@brief : Select Pin Configuration to be Output and low .
	 */
DIO_enumOutPut_Low,
	/**
	 *@brief : Select Pin Configuration to be Output and high .
	 */
	
	DIO_enumOutPut_High,
	/**
	 *@brief : Select Pin Configuration to be Input Internal PullUp .
	 */
DIO_enumInPut_PullUp,
	/**
	 *@brief : Select Pin Configuration to be Input External PullDown
	 */
DIO_enumInPut_PullDown
}DIO_enumPinConfig_t;

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)		CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0

#define  SFIOR	*((volatile u8 *)(0x50))

#define DDRA	*((volatile u8 *)(0x3A))
#define PORTA	*((volatile u8 *)(0x3B))
#define PINA	*((volatile u8 *)(0x39))

#define DDRB	*((volatile u8 *)(0x37))
#define PORTB	*((volatile u8 *)(0x38))
#define PINB	*((volatile u8 *)(0x36))

#define DDRC	*((volatile u8 *)(0x34))
#define PORTC	*((volatile u8 *)(0x35))
#define PINC	*((volatile u8 *)(0x33))

#define DDRD	*((volatile u8 *)(0x31))
#define PORTD	*((volatile u8 *)(0x32))
#define PIND	*((volatile u8 *)(0x30))

/**
 *@brief  : Function to Configure Specific pin to be INPUT or OUTPUT port.
 *@param  : Port Number,Pin Number ,Configuration type(Input/Output).
 *@return : Error State
 */
DIO_enumErrors_t PORT_enumSetPinsConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPinNum_t Copy_enumPinNum,DIO_enumPinConfig_t Copy_enumConfig);
#define Preprocessor_Config		0
#define PostCompile_Config		1

#define TWO_PORTS		2
#define THREE_PORTS		3
#define FOUR_PORTS		4

#define NUMBER_OF_PINS		32


#endif /* PORT_H_ */