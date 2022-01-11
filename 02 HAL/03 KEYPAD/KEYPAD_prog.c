/**************************************************/
/*   AUTHOR      : Mohamed	MeGa	              */
/*   Description : KEYPAD DRIVER                  */
/*   DATE        : 2 OCT 2021                     */
/*   VERSION     : V1.1                           */
/**************************************************/

/*		library Directives						  */
#include	"STD_Types.h"
#include	"Bit_Math.h"

/**			DIO Directives						 */
#include	"DIO_int.h"


/**			DIO Directives						 */
#include	"KEYPAD_int.h"
#include	"KEYPAD_config.h"
#include	"KEYPAD_priv.h"



void	KEYPAD_VoidInit(void)
{
	DIO_voidSetPinValue(KEYPAD_U8_COL1, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_COL2, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_COL3, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_COL4, DIO_u8_HIGH);
	
	DIO_voidSetPinValue(KEYPAD_U8_ROW1, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_ROW2, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_ROW3, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_ROW4, DIO_u8_HIGH);
}


/*u8	KEYPAD_U8GetPressedKey(void)
{
	u8	LOC_u8col;
	u8	LOC_u8row;
	u8	LOC_Return;
	
	for(LOC_u8col = 0 + KEYPAD_COL_INIT; LOC_u8col <= KEYPAD_COL_END; LOC_u8col++)
	{
		DIO_voidSetPinValue(LOC_u8col, DIO_u8_LOW);
		for(LOC_u8row = 0 + KEYPAD_ROW_INIT; LOC_u8row <= KEYPAD_ROW_END; LOC_u8row++)
		{
			if(! DIO_u8GetPinValue(LOC_u8row))
			{
				LOC_Return = KPD_au8SwitchVal[LOC_u8col - KEYPAD_COL_INIT][LOC_u8row - KEYPAD_ROW_INIT];
				while(! DIO_u8GetPinValue(LOC_u8row));
				_delay_ms(10);
			}
			
		}
		DIO_voidSetPinValue(LOC_u8col, DIO_u8_HIGH);
	}
	return LOC_Return;
}*/

u8	KEYPAD_U8GetPressedKey(void)
{
	u8 LOC_u8PressedKey = 0xFF;
	u8 LOC_u8ColValue;
	
	DIO_voidSetPinValue(KEYPAD_U8_ROW1, DIO_u8_LOW);
	DIO_voidSetPinValue(KEYPAD_U8_ROW2, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_ROW3, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_ROW4, DIO_u8_HIGH);
	
	LOC_u8ColValue  =  DIO_u8GetPinValue(KEYPAD_U8_COL1);
	LOC_u8ColValue |= (DIO_u8GetPinValue(KEYPAD_U8_COL2))<<1;
	LOC_u8ColValue |= (DIO_u8GetPinValue(KEYPAD_U8_COL2))<<2;
	LOC_u8ColValue |= (DIO_u8GetPinValue(KEYPAD_U8_COL1))<<3;
	
	switch(LOC_u8ColValue)
	{
		case 0b00001110:
			LOC_u8PressedKey = '1';
			break;
		case 0b00001101:
			LOC_u8PressedKey = '2';
			break;
		case 0b00001011:
			LOC_u8PressedKey = '3';
			break;
		case 0b00000111:
			LOC_u8PressedKey = '+';
			break;
		default:
			LOC_u8PressedKey = 0xFF;
			break;
	}
	
	if(LOC_u8ColValue == 0xFF)
	{
		DIO_voidSetPinValue(KEYPAD_U8_ROW1, DIO_u8_HIGH);
		DIO_voidSetPinValue(KEYPAD_U8_ROW2, DIO_u8_LOW);
		DIO_voidSetPinValue(KEYPAD_U8_ROW3, DIO_u8_HIGH);
		DIO_voidSetPinValue(KEYPAD_U8_ROW4, DIO_u8_HIGH);
		
		LOC_u8ColValue  =  DIO_u8GetPinValue(KEYPAD_U8_COL1);
		LOC_u8ColValue |= (DIO_u8GetPinValue(KEYPAD_U8_COL2))<<1;
		LOC_u8ColValue |= (DIO_u8GetPinValue(KEYPAD_U8_COL2))<<2;
		LOC_u8ColValue |= (DIO_u8GetPinValue(KEYPAD_U8_COL1))<<3;
		
		switch(LOC_u8ColValue)
		{
			case 0b00001110:
				LOC_u8PressedKey = '4';
				break;
			case 0b00001101:
				LOC_u8PressedKey = '5';
				break;
			case 0b00001011:
				LOC_u8PressedKey = '6';
				break;
			case 0b00000111:
				LOC_u8PressedKey = '-';
				break;
			default:
				LOC_u8PressedKey = 0xFF;
				break;
		}
	}
	
	if(LOC_u8PressedKey == 0xFF)
	{
		DIO_voidSetPinValue(KEYPAD_U8_ROW1, DIO_u8_HIGH);
		DIO_voidSetPinValue(KEYPAD_U8_ROW2, DIO_u8_HIGH);
		DIO_voidSetPinValue(KEYPAD_U8_ROW3, DIO_u8_LOW);
		DIO_voidSetPinValue(KEYPAD_U8_ROW4, DIO_u8_HIGH);
		
		LOC_u8ColValue  =  DIO_u8GetPinValue(KEYPAD_U8_COL1);
		LOC_u8ColValue |= (DIO_u8GetPinValue(KEYPAD_U8_COL2))<<1;
		LOC_u8ColValue |= (DIO_u8GetPinValue(KEYPAD_U8_COL2))<<2;
		LOC_u8ColValue |= (DIO_u8GetPinValue(KEYPAD_U8_COL1))<<3;
		
		switch(LOC_u8ColValue)
		{
			case 0b00001110:
				LOC_u8PressedKey = '7';
				break;
			case 0b00001101:
				LOC_u8PressedKey = '8';
				break;
			case 0b00001011:
				LOC_u8PressedKey = '9';
				break;
			case 0b00000111:
				LOC_u8PressedKey = '*';
				break;
			default:
				LOC_u8PressedKey = 0xFF;
				break;
		}
	}
	
	if(LOC_u8PressedKey == 0xFF)
	{
		DIO_voidSetPinValue(KEYPAD_U8_ROW1, DIO_u8_HIGH);
		DIO_voidSetPinValue(KEYPAD_U8_ROW2, DIO_u8_HIGH);
		DIO_voidSetPinValue(KEYPAD_U8_ROW3, DIO_u8_LOW);
		DIO_voidSetPinValue(KEYPAD_U8_ROW4, DIO_u8_HIGH);
		
		LOC_u8ColValue  =  DIO_u8GetPinValue(KEYPAD_U8_COL1);
		LOC_u8ColValue |= (DIO_u8GetPinValue(KEYPAD_U8_COL2))<<1;
		LOC_u8ColValue |= (DIO_u8GetPinValue(KEYPAD_U8_COL2))<<2;
		LOC_u8ColValue |= (DIO_u8GetPinValue(KEYPAD_U8_COL1))<<3;
		
		switch(LOC_u8ColValue)
		{
			case 0b00001110:
				LOC_u8PressedKey = '.';
				break;
			case 0b00001101:
				LOC_u8PressedKey = '0';
				break;
			case 0b00001011:
				LOC_u8PressedKey = '=';
				break;
			case 0b00000111:
				LOC_u8PressedKey = '/';
				break;
			default:
				LOC_u8PressedKey = 0xFF;
				break;
		}
	}
	
	
	return LOC_u8PressedKey;
}