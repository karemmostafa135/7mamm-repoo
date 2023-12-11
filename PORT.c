#include "STD_types.h"
#include "Bit_utils.h"
#include "PORT_Config.h"
#include "PORT.h"
extern DIO_enumPinConfig_t DIO_arrenuPins_Config[32];

#if Configuration_Options == Preprocessor_Config
 void PORT_Init(void){
	/******** initialize PortA***/
	DDRA=CONC(DIO_PortA_Pin7_Config,DIO_PortA_Pin6_Config,DIO_PortA_Pin5_Config,DIO_PortA_Pin4_Config,DIO_PortA_Pin3_Config,DIO_PortA_Pin2_Config,DIO_PortA_Pin1_Config,DIO_PortA_Pin0_Config);
	PORTA=CONC(DIO_PortA_Pin7_Value,DIO_PortA_Pin6_Value,DIO_PortA_Pin5_Value,DIO_PortA_Pin4_Value,DIO_PortA_Pin3_Value,DIO_PortA_Pin2_Value,DIO_PortA_Pin1_Value,DIO_PortA_Pin0_Value);

	/******** initialize PortB***/
	DDRB=CONC(DIO_PortB_Pin7_Config,DIO_PortB_Pin6_Config,DIO_PortB_Pin5_Config,DIO_PortB_Pin4_Config,DIO_PortB_Pin3_Config,DIO_PortB_Pin2_Config,DIO_PortB_Pin1_Config,DIO_PortB_Pin0_Config);
	PORTB=CONC(DIO_PortB_Pin7_Value,DIO_PortB_Pin6_Value,DIO_PortB_Pin5_Value,DIO_PortB_Pin4_Value,DIO_PortB_Pin3_Value,DIO_PortB_Pin2_Value,DIO_PortB_Pin1_Value,DIO_PortB_Pin0_Value);
	#if (NUMBER_OF_PORTS == THREE_PORTS) || (NUMBER_OF_PORTS == FOUR_PORTS)
	/******** initialize PortC***/
	DDRC=CONC(DIO_PortC_Pin7_Config,DIO_PortC_Pin6_Config,DIO_PortC_Pin5_Config,DIO_PortC_Pin4_Config,DIO_PortC_Pin3_Config,DIO_PortC_Pin2_Config,DIO_PortC_Pin1_Config,DIO_PortC_Pin0_Config);
	PORTC=CONC(DIO_PortC_Pin7_Value,DIO_PortC_Pin6_Value,DIO_PortC_Pin5_Value,DIO_PortC_Pin4_Value,DIO_PortC_Pin3_Value,DIO_PortC_Pin2_Value,DIO_PortC_Pin1_Value,DIO_PortC_Pin0_Value);
	#endif
	
	#if NUMBER_OF_PORTS == FOUR_PORTS
	/******** initialize PortD***/
	DDRD=CONC(DIO_PortD_Pin7_Config,DIO_PortD_Pin6_Config,DIO_PortD_Pin5_Config,DIO_PortD_Pin4_Config,DIO_PortD_Pin3_Config,DIO_PortD_Pin2_Config,DIO_PortD_Pin1_Config,DIO_PortD_Pin0_Config);
	PORTD=CONC(DIO_PortD_Pin7_Value,DIO_PortD_Pin6_Value,DIO_PortD_Pin5_Value,DIO_PortD_Pin4_Value,DIO_PortD_Pin3_Value,DIO_PortD_Pin2_Value,DIO_PortD_Pin1_Value,DIO_PortD_Pin0_Value);
	#endif
}


#elif Configuration_Options==PostCompile_Config
void PORT_Init(void){
	#if NUMBER_OF_PORTS == TWO_PORTS
	#define NUMBER_OF_PINS		16
	#elif NUMBER_OF_PORTS == THREE_PORTS
	#define NUMBER_OF_PINS		24
	#elif NUMBER_OF_PORTS == FOUR_PORTS
	#define NUMBER_OF_PINS		32
	#endif
	u8 loc_u8i=0;
	u8 loc_u8PORT ;
	u8 loc_u8PIN;
	for (loc_u8i=0;loc_u8i<NUMBER_OF_PINS;loc_u8i++){
		loc_u8PORT=loc_u8i/8;
		loc_u8PIN=loc_u8i%8;
		PORT_enumSetPinsConfig(loc_u8PORT,loc_u8PIN,DIO_arrenuPins_Config[loc_u8i]);
	}
}



DIO_enumErrors_t PORT_enumSetPinsConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPinNum_t Copy_enumPinNum,DIO_enumPinConfig_t Copy_enumConfig){
	DIO_enumErrors_t RET_enumErrorState=DIO_enumNok;
	if((Copy_enumPortNum>DIO_enumPortD)||(Copy_enumPortNum<DIO_enumPortA)){
		return RET_enumErrorState=DIO_enumWrongPort;
	}
	else if ((Copy_enumPinNum>DIO_enumPin7)||(Copy_enumPinNum<DIO_enumPin0)){
		return RET_enumErrorState=DIO_enumWrongPin;
	}
	else if ((Copy_enumConfig<DIO_enumOutPut_Low)||(Copy_enumConfig>DIO_enumInPut_PullDown)){
		return RET_enumErrorState=DIO_enumWrongConfig;
	}
	else{
		switch(Copy_enumConfig){
			case DIO_enumOutPut_Low:
			switch(Copy_enumPortNum){
				case (DIO_enumPortA):	SET_BIT(DDRA,Copy_enumPinNum); CLR_BIT(PORTA,Copy_enumPinNum); break;
				case (DIO_enumPortB):	SET_BIT(DDRB,Copy_enumPinNum); CLR_BIT(PORTB,Copy_enumPinNum); break;
				case (DIO_enumPortC):	SET_BIT(DDRC,Copy_enumPinNum); CLR_BIT(PORTC,Copy_enumPinNum); break;
				case (DIO_enumPortD):	SET_BIT(DDRD,Copy_enumPinNum); CLR_BIT(PORTD,Copy_enumPinNum); break;
			}
			break;
			
			case DIO_enumOutPut_High:
			switch(Copy_enumPortNum){
				case (DIO_enumPortA):	SET_BIT(DDRA,Copy_enumPinNum); SET_BIT(PORTA,Copy_enumPinNum); break;
				case (DIO_enumPortB):	SET_BIT(DDRB,Copy_enumPinNum); SET_BIT(PORTB,Copy_enumPinNum); break;
				case (DIO_enumPortC):	SET_BIT(DDRC,Copy_enumPinNum); SET_BIT(PORTC,Copy_enumPinNum); break;
				case (DIO_enumPortD):	SET_BIT(DDRD,Copy_enumPinNum); SET_BIT(PORTD,Copy_enumPinNum); break;
			}
			break;
			case DIO_enumInPut_PullUp:
			switch(Copy_enumPortNum){
				case (DIO_enumPortA):	CLR_BIT(DDRA,Copy_enumPinNum); SET_BIT(PORTA,Copy_enumPinNum); break;
				case (DIO_enumPortB):	CLR_BIT(DDRB,Copy_enumPinNum); SET_BIT(PORTB,Copy_enumPinNum);  break;
				case (DIO_enumPortC):	CLR_BIT(DDRC,Copy_enumPinNum); SET_BIT(PORTC,Copy_enumPinNum);  break;
				case (DIO_enumPortD):	CLR_BIT(DDRD,Copy_enumPinNum); SET_BIT(PORTD,Copy_enumPinNum);  break;
			}
			break;
			case DIO_enumInPut_PullDown:
			switch(Copy_enumPortNum){
				case (DIO_enumPortA):	CLR_BIT(DDRA,Copy_enumPinNum); CLR_BIT(PORTA,Copy_enumPinNum); break;
				case (DIO_enumPortB):	CLR_BIT(DDRB,Copy_enumPinNum); CLR_BIT(PORTB,Copy_enumPinNum); break;
				case (DIO_enumPortC):	CLR_BIT(DDRC,Copy_enumPinNum); CLR_BIT(PORTC,Copy_enumPinNum); break;
				case (DIO_enumPortD):	CLR_BIT(DDRD,Copy_enumPinNum); CLR_BIT(PORTD,Copy_enumPinNum); break;
			}
			break;
		}

	}
	return RET_enumErrorState;
}
#endif
