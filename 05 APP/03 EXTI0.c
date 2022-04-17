/*
 * main.c
 *
 *  Created on: Jan 18, 2022
 *      Author: mabda
 */


/************************************************************/
/*			library Directives						  		*/
/************************************************************/
#include	"STD_Types.h"
#include	"Bit_Math.h"

/************************************************************/
/**			DIO Directives						 			*/
/************************************************************/
#include	"DIO_int.h"

/**			EXTI Directives						 */
#include	"EXTI0_int.h"

/**			EXTI Directives						 			*/
#include	"GIE_int.h"
void Led_on(void);
int main(void)
{

	DIO_VoidInitialization();
	DIO_voidSetPinValue(DIO_PIN26, DIO_HIGH);
	EXTI0_VoidInitialization();
	EXTI0_VoidEnableEXTI0();
	EXTI0_VoidSetCallBack(Led_on);
	GIE_VoidGIEEnable();

	while(1)
	{

	}
	return 0;
}

void Led_on(void)
{
	DIO_voidSetPinValue(DIO_PIN0, DIO_HIGH);
}
