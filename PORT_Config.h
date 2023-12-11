#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_
/*
**@brief choose the configuration type you need
**@options 1/Preprocessor_Config  2/ PostCompile_Config
*/

#define Configuration_Options	PostCompile_Config
/*
**@brief choose 1/TWO_PORTS   2/THREE_PORTS		3/FOUR_PORTS
*/

#define NUMBER_OF_PORTS	 FOUR_PORTS


/**
*@brief for pin_config choose PIN_INPUT and (if you want it as input pull up please set its value to high) or PIN_OUTPUT
*@default the default of pin is INPUT 
 */

/********** PORTA CONFIG ********/
#define DIO_PortA_Pin0_Config		PIN_OUTPUT
#define DIO_PortA_Pin1_Config		PIN_OUTPUT
#define DIO_PortA_Pin2_Config		PIN_OUTPUT
#define DIO_PortA_Pin3_Config		PIN_OUTPUT
#define DIO_PortA_Pin4_Config		PIN_INPUT
#define DIO_PortA_Pin5_Config		PIN_INPUT
#define DIO_PortA_Pin6_Config		PIN_INPUT
#define DIO_PortA_Pin7_Config		PIN_INPUT

/********** PORTB CONFIG ********/

#define DIO_PortB_Pin0_Config		PIN_INPUT
#define DIO_PortB_Pin1_Config		PIN_INPUT
#define DIO_PortB_Pin2_Config		PIN_INPUT
#define DIO_PortB_Pin3_Config		PIN_INPUT
#define DIO_PortB_Pin4_Config		PIN_INPUT
#define DIO_PortB_Pin5_Config		PIN_INPUT
#define DIO_PortB_Pin6_Config		PIN_INPUT
#define DIO_PortB_Pin7_Config		PIN_OUTPUT

/********** PORTC CONFIG (INPUT OF OUTPUT) ********/

#define DIO_PortC_Pin0_Config		PIN_INPUT
#define DIO_PortC_Pin1_Config		PIN_INPUT
#define DIO_PortC_Pin2_Config		PIN_INPUT
#define DIO_PortC_Pin3_Config		PIN_INPUT
#define DIO_PortC_Pin4_Config		PIN_INPUT
#define DIO_PortC_Pin5_Config		PIN_INPUT
#define DIO_PortC_Pin6_Config		PIN_INPUT
#define DIO_PortC_Pin7_Config		PIN_INPUT

/********** PORTD CONFIG ********/

#define DIO_PortD_Pin0_Config		PIN_INPUT
#define DIO_PortD_Pin1_Config		PIN_INPUT
#define DIO_PortD_Pin2_Config		PIN_INPUT
#define DIO_PortD_Pin3_Config		PIN_INPUT
#define DIO_PortD_Pin4_Config		PIN_INPUT
#define DIO_PortD_Pin5_Config		PIN_INPUT
#define DIO_PortD_Pin6_Config		PIN_INPUT
#define DIO_PortD_Pin7_Config		PIN_INPUT

/**
*@brief for pin value choose between PIN_HIGH (for input pull up too if this pin is considered as input) or PIN_LOW
*@default the default of pin is LOW
*/

/**************** PORTA value (HIGH OR LOW) **********/

#define DIO_PortA_Pin0_Value	PIN_LOW
#define DIO_PortA_Pin1_Value	PIN_LOW
#define DIO_PortA_Pin2_Value	PIN_LOW
#define DIO_PortA_Pin3_Value	PIN_LOW
#define DIO_PortA_Pin4_Value	PIN_LOW
#define DIO_PortA_Pin5_Value	PIN_LOW
#define DIO_PortA_Pin6_Value	PIN_LOW
#define DIO_PortA_Pin7_Value	PIN_LOW

/**************** PORTB value (HIGH OR LOW) **********/

#define DIO_PortB_Pin0_Value	PIN_LOW
#define DIO_PortB_Pin1_Value	PIN_LOW
#define DIO_PortB_Pin2_Value	PIN_LOW
#define DIO_PortB_Pin3_Value	PIN_LOW
#define DIO_PortB_Pin4_Value	PIN_LOW
#define DIO_PortB_Pin5_Value	PIN_HIGH
#define DIO_PortB_Pin6_Value	PIN_LOW
#define DIO_PortB_Pin7_Value	PIN_HIGH

/**************** PORTC value (HIGH OR LOW) **********/

#define DIO_PortC_Pin0_Value	PIN_LOW
#define DIO_PortC_Pin1_Value	PIN_LOW
#define DIO_PortC_Pin2_Value	PIN_LOW
#define DIO_PortC_Pin3_Value	PIN_LOW
#define DIO_PortC_Pin4_Value	PIN_LOW
#define DIO_PortC_Pin5_Value	PIN_LOW
#define DIO_PortC_Pin6_Value	PIN_LOW
#define DIO_PortC_Pin7_Value	PIN_LOW


/**************** PORTD value (HIGH OR LOW) **********/

#define DIO_PortD_Pin0_Value	PIN_LOW
#define DIO_PortD_Pin1_Value	PIN_LOW
#define DIO_PortD_Pin2_Value	PIN_LOW
#define DIO_PortD_Pin3_Value	PIN_LOW
#define DIO_PortD_Pin4_Value	PIN_LOW
#define DIO_PortD_Pin5_Value	PIN_LOW
#define DIO_PortD_Pin6_Value	PIN_LOW
#define DIO_PortD_Pin7_Value	PIN_LOW

/** 
*@brief to initialize all ports to the user configurations 
*/
void PORT_Init(void);

#endif