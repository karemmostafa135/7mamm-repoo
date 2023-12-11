#include "Bit_utils.h"
#include "STD_types.h"
#include "DIO.h"




DIO_enumErrors_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState){
	DIO_enumErrors_t RET_enumErrorStatus=DIO_enumNok;
	if((Copy_enumPortNum>DIO_enumPortD)||(Copy_enumPortNum<DIO_enumPortA)){
		return RET_enumErrorStatus=DIO_enumWrongPort;
	}
	else if ((Copy_enumLogicState<DIO_enumLogicHigh)||(Copy_enumLogicState>DIO_enumLogicLow)){
		return RET_enumErrorStatus=DIO_enumWrongConfig;
	}
	else {
		RET_enumErrorStatus=DIO_enumOk;
		switch(Copy_enumLogicState){
			case DIO_enumLogicHigh:
			switch(Copy_enumPortNum){
				case (DIO_enumPortA): SET_REG(PORTA); break;
				case (DIO_enumPortB): SET_REG(PORTB); break;
				case (DIO_enumPortC): SET_REG(PORTC); break;
				case (DIO_enumPortD): SET_REG(PORTD); break;
			}
			break;
			case DIO_enumLogicLow:
			switch(Copy_enumPortNum){
				case (DIO_enumPortA): CLR_REG(PORTA);  break;
				case (DIO_enumPortB): CLR_REG(PORTB);  break;
				case (DIO_enumPortC): CLR_REG(PORTC);  break;
				case (DIO_enumPortD): CLR_REG(PORTD);  break;
			}
			break;
		}
	}
	return RET_enumErrorStatus;
	
}

DIO_enumErrors_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPinNum_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState){
	DIO_enumErrors_t RET_enumErrorState=DIO_enumNok;
	if((Copy_enumPortNum>DIO_enumPortD)||(Copy_enumPortNum<DIO_enumPortA)){
		return RET_enumErrorState=DIO_enumWrongPort;
	}
	else if ((Copy_enumPinNum>DIO_enumPin7)||(Copy_enumPinNum<DIO_enumPin0)){
		return RET_enumErrorState=DIO_enumWrongPin;
	}
	else if ((Copy_enumLogicState>DIO_enumLogicHigh)||(Copy_enumLogicState<DIO_enumLogicLow)){
		return RET_enumErrorState=DIO_enumWrongConfig;
	}
	else{
		switch(Copy_enumLogicState){
			case DIO_enumLogicHigh:
			switch(Copy_enumPortNum){
				case (DIO_enumPortA):	SET_BIT(PORTA,Copy_enumPinNum); break;
				case (DIO_enumPortB):	SET_BIT(PORTB,Copy_enumPinNum); break;
				case (DIO_enumPortC):	SET_BIT(PORTC,Copy_enumPinNum); break;
				case (DIO_enumPortD):	SET_BIT(PORTD,Copy_enumPinNum); break;
			}
			break;
			case DIO_enumLogicLow:
			switch(Copy_enumPortNum){
				case (DIO_enumPortA):	CLR_BIT(PORTA,Copy_enumPinNum); break;
				case (DIO_enumPortB):	CLR_BIT(PORTB,Copy_enumPinNum); break;
				case (DIO_enumPortC):	CLR_BIT(PORTC,Copy_enumPinNum); break;
				case (DIO_enumPortD):	CLR_BIT(PORTD,Copy_enumPinNum); break;
			}
			break;
		}

	}
	return RET_enumErrorState;
}

DIO_enumErrors_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPinNum_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue){
	DIO_enumErrors_t RET_enumErrorState=DIO_enumNok;
	if((Copy_enumPortNum>DIO_enumPortD)||(Copy_enumPortNum<DIO_enumPortA)){
		return RET_enumErrorState=DIO_enumWrongPort;
	}
	else if ((Copy_enumPinNum>DIO_enumPin7)||(Copy_enumPinNum<DIO_enumPin0)){
		return RET_enumErrorState=DIO_enumWrongPin;
	}
	else if(Add_Pu8PinValue==NULL) {
		return RET_enumErrorState=DIO_enumNullPointer;
	}
	else{
		RET_enumErrorState=DIO_enumOk;
		switch(Copy_enumPortNum){
			case (DIO_enumPortA):	*Add_Pu8PinValue=GET_BIT(PINA,Copy_enumPinNum); break;
			case (DIO_enumPortB):	*Add_Pu8PinValue=GET_BIT(PINB,Copy_enumPinNum); break;
			case (DIO_enumPortC):	*Add_Pu8PinValue=GET_BIT(PINC,Copy_enumPinNum); break;
			case (DIO_enumPortD):	*Add_Pu8PinValue=GET_BIT(PIND,Copy_enumPinNum); break;
		}
	}
	return RET_enumErrorState;
}
