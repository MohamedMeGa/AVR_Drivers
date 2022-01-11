/**************************************************/
/*   AUTHOR      : MOHAMED	MEGA	              */
/*   Description : Stepper Motor DRIVER           */
/*   DATE        : 09 JAN 2021                    */
/*   VERSION     : V01                            */
/**************************************************/

/*		library Directives						  */
#include	"STD_Types.h"
#include	"Bit_Math.h"

/**			DIO Directives						 */
#include	"DIO_int.h"

#define F_CPU 12000000UL
#include "avr/delay.h"

/**			DIO Directives						 */
#include	"STMR_int.h"
#include	"STMR_config.h"
#include	"STMR_priv.h"



/***************************************************/
/** Description :  function to to run stepper motor*/
/**					in clock wise				   */
/***************************************************/

void	STMR_voidRotateCW(void)
{
	DIO_voidSetPinValue(STMR_1_U8, DIO_u8_HIGH);
	DIO_voidSetPinValue(STMR_2_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_3_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_4_U8, DIO_u8_LOW);
	_delay_ms(5);
	
	DIO_voidSetPinValue(STMR_1_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_2_U8, DIO_u8_HIGH);
	DIO_voidSetPinValue(STMR_3_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_4_U8, DIO_u8_LOW);
	_delay_ms(5);
	
	DIO_voidSetPinValue(STMR_1_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_2_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_3_U8, DIO_u8_HIGH);
	DIO_voidSetPinValue(STMR_4_U8, DIO_u8_LOW);
	_delay_ms(5);
	
	DIO_voidSetPinValue(STMR_1_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_2_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_3_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_4_U8, DIO_u8_HIGH);
	_delay_ms(5);
}


/***************************************************/
/** Description :  function to to run stepper motor*/
/**					in Anti clock wise			   */
/***************************************************/
void	STMR_voidRotateACW(void)
{
	DIO_voidSetPinValue(STMR_1_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_2_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_3_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_4_U8, DIO_u8_HIGH);
	_delay_ms(5);
	
	DIO_voidSetPinValue(STMR_1_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_2_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_3_U8, DIO_u8_HIGH);
	DIO_voidSetPinValue(STMR_4_U8, DIO_u8_LOW);
	_delay_ms(5);
	
	DIO_voidSetPinValue(STMR_1_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_2_U8, DIO_u8_HIGH);
	DIO_voidSetPinValue(STMR_3_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_4_U8, DIO_u8_LOW);
	_delay_ms(5);
	
	DIO_voidSetPinValue(STMR_1_U8, DIO_u8_HIGH);
	DIO_voidSetPinValue(STMR_2_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_3_U8, DIO_u8_LOW);
	DIO_voidSetPinValue(STMR_4_U8, DIO_u8_LOW);
	_delay_ms(5);
}