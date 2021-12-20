/**************************************************/
/*   AUTHOR      : Mohamed	MeGa	              */
/*   Description : KEYPAD DRIVER                     */
/*   DATE        : 2 OCT 2021                   */
/*   VERSION     : V01                            */
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


				  
u8	KEYPAD_U8GetPressedKey(void)
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
}



















void	LCD_VoidSendCommand(u8	copy_U8CMD);

void	LCD_VoidWriteCharacter(u8	copy_U8Char);

void	LCD_VoidWriteString(u8	copy_U8string, u8 copy_U8index);