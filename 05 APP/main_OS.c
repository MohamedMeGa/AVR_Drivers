/************************************************************/
/** 		AUTHOR      : Mohamed MeGa	                   	*/
/**		 	DISCRIPTION : OS DRIVER      				  	*/
/** 		DATE        : 23 DEC 2021                       */
/** 		VERSION     : V01                               */
/************************************************************/


/************************************************************/
/*			library Directives						  		*/
/************************************************************/
#include	"STD_TYPES.h"
#include	"Bit_Math.h"

/************************************************************/
/**			OS Directives						 			*/
/************************************************************/
#include	"RCC_interface.h"
#include	"GPIO_interface.h"
#include	"STK_interface.h"
#include	"OS_interface.h"


void Led1(void);
void Led2(void);
void Led3(void);


int main(void)
{
	RCC_VoidInitSystemClock();
	
	STK_voidInit();
	RCC_VoidEnableClock(RCC_ABP2, 2);
	
	GPIO_VoidSetPinDirection(GPIOA, PIN9, OUTPUT_10MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA, PIN10, OUTPUT_10MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA, PIN11, OUTPUT_10MHZ_PP);
	
	OS_VoidCreateTask(0, 1000, Led1());
	OS_VoidCreateTask(1, 2000, Led2());
	OS_VoidCreateTask(2, 3000, Led3());
	
	OS_VoidStart();
	
	
	while(1);
	return 0;
}


void Led1(void)
{
	static	u8 Local_u8Pin = 0;
	TOGGLE_BIT(Local_u8Pin, 0);
	GPIO_VoidSetPinValue(GPIOA, PIN9, Local_u8Pin);
}
void Led2(void)
{
	static	u8 Local_u8Pin = 0;
	TOGGLE_BIT(Local_u8Pin, 0);
	GPIO_VoidSetPinValue(GPIOA, PIN9, Local_u8Pin);
}
void Led3(void)
{
	static	u8 Local_u8Pin = 0;
	TOGGLE_BIT(Local_u8Pin, 0);
	GPIO_VoidSetPinValue(GPIOA, PIN9, Local_u8Pin);
}