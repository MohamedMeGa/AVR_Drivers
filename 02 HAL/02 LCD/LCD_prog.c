/**************************************************/
/*   AUTHOR      : Mohamed	MeGa	              */
/*   Description : LCD DRIVER                     */
/*   DATE        : 1 OCT 2021                     */
/*   VERSION     : V01                            */
/**************************************************/

/*		library Directives						  */
#include	"STD_Types.h"
#include	"Bit_Math.h"

/**			DIO Directives						 */
#include	"DIO_int.h"
#include <util/delay.h>

/**			DIO Directives						 */
#include	"LCD_int.h"
#include	"LCD_config.h"
#include	"LCD_priv.h"



void	LCD_VoidLCDInit(void)
{
	/**
		1-WAIT 30mS
		2-send HOME Command & wait 15 ms
		3-send FUNCTION SET Command & Wait 15 ms
		4-send DISPLAY ON/OFF CONTROL Command & Wait 15 ms
		5-send ENTYRY MODE SET Command & Wait 15 ms 
	*/

	_delay_ms(35);

	LCD_VoidSendCommand(lcd_Home);
	_delay_ms(1);
	
	LCD_VoidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(1);
	
	LCD_VoidSendCommand(lcd_DisplayOn);
	_delay_ms(2);
	
	LCD_VoidSendCommand(lcd_Clear);
	_delay_ms(2);
	
	LCD_VoidSendCommand(lcd_EntryMode);
	_delay_ms(2);
	
	DIO_voidSetPinValue(LCD_U8_EN, DIO_u8_LOW);
}



void	LCD_VoidSendCommand(u8	copy_U8CMD)

{
	/*1-SET RS PIN TO LOW & EN PIN TO HIGH
	  2-SEND COMMAND
	  3-SET EN PIN TO LOW & WAIT 5ms
	  4-SET EN PIN TO high & WAIT 5ms
	*/

	DIO_voidSetPinValue(LCD_U8_RS, DIO_u8_LOW);
	

	
	LCD_voidPutOnBus(copy_U8CMD);
	
	
}

void	LCD_VoidWriteCharacter(u8	copy_U8Char)
{
	/*1-SET RS PIN TO HIGH & EN PIN TO HIGH
	  2-SEND DATE
	  3-SET EN PIN TO LOW & WAIT 5ms
	  4-SET EN PIN TO high & WAIT 5ms	
	*/

	DIO_voidSetPinValue(LCD_U8_RS, DIO_u8_HIGH);
	
	LCD_voidPutOnBus(copy_U8Char);
	
	
}

static void LCD_voidPutOnBus(u8 copy_U8Char)
{
	u8 Loc_u8Loop = 0;
	DIO_voidSetPinValue(LCD_U8_D0, GET_BIT(copy_U8Char, Loc_u8Loop++));
	DIO_voidSetPinValue(LCD_U8_D1, GET_BIT(copy_U8Char, Loc_u8Loop++));
	DIO_voidSetPinValue(LCD_U8_D2, GET_BIT(copy_U8Char, Loc_u8Loop++));
	DIO_voidSetPinValue(LCD_U8_D3, GET_BIT(copy_U8Char, Loc_u8Loop++));
	DIO_voidSetPinValue(LCD_U8_D4, GET_BIT(copy_U8Char, Loc_u8Loop++));
	DIO_voidSetPinValue(LCD_U8_D5, GET_BIT(copy_U8Char, Loc_u8Loop++));
	DIO_voidSetPinValue(LCD_U8_D6, GET_BIT(copy_U8Char, Loc_u8Loop++));
	DIO_voidSetPinValue(LCD_U8_D7, GET_BIT(copy_U8Char, Loc_u8Loop++));
	
	DIO_voidSetPinValue(LCD_U8_EN, DIO_u8_HIGH);
	_delay_ms(2);  
	
	DIO_voidSetPinValue(LCD_U8_EN, DIO_u8_LOW);
	_delay_ms(2);
}

void	LCD_VoidWriteString(u8*	copy_U8string)
{
	u8	LOC_U8Iteration = 0;
	
	//for(LOC_U8Iteration = 0; LOC_U8Iteration <= copy_U8index, copy_U8index++)
	while(copy_U8string[LOC_U8Iteration] != '\0')
	{
		LCD_VoidWriteCharacter(copy_U8string[LOC_U8Iteration]);
		_delay_ms(2);
		LOC_U8Iteration++;
	}
}




void Gotoxy (u8 Y,u8 X)
{
	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 1:
		    	LCD_vidSendCommand(X+127);
				break;
				
		    case 2:
		    	LCD_vidSendCommand(X+191);
				break;
				
		    default:
				break;
	    }
	}
}