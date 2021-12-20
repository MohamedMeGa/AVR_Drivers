/**************************************************/
/*   AUTHOR      : Mohamed	MeGa	              */
/*   Description : LCD DRIVER                     */
/*   DATE        : 1 OCT 2021                   */
/*   VERSION     : V01                            */
/**************************************************/

/*		library Directives						  */
#include	"STD_Types.h"
#include	"Bit_Math.h"

/**			DIO Directives						 */
#include	"DIO_int.h"


/**			DIO Directives						 */
#include	"LCD_int.h"
#include	"LCD_config.h"
#include	"LCD_priv.h"


				  
void	LCD_VoidLCDInit(void)
{
	/*1-WAIT 30mS
	  2-send HOME Command & wait 15 ms
	  3-send FUNCTION SET Command & Wait 15 ms
	  4-send DISPLAY ON/OFF CONTROL Command & Wait 15 ms
	  5-3-send ENTYR MODE SET Command & Wait 15 ms */
	  
	  _delay_ms(30);
	  
	LCD_VoidSendCommand(lcd_Home);
	_delay_ms(15);
	
	LCD_VoidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(15);
	
	LCD_VoidSendCommand(lcd_DisplayOn);
	_delay_ms(15);
	
	LCD_VoidSendCommand(lcd_Clear);
	_delay_ms(15);
	
	LCD_VoidSendCommand(lcd_EntryMode);
	_delay_ms(15);
}



void	LCD_VoidSendCommand(u8	copy_U8CMD)

{
	/*1-SET RS PIN TO LOW & EN PIN TO HIGH
	  2-SEND COMMAND
	  3-SET EN PIN TO LOW & WAIT 5ms
	  4-SET EN PIN TO high & WAIT 5ms*/
	  
	DIO_voidSetPinValue(LCD_U8_RS, DIO_u8_LOW);
	
	DIO_voidSetPinValue(LCD_U8_EN, DIO_u8_HIGH);
	
	SET_BYTE(PORTA, copy_U8CMD);
	
	DIO_voidSetPinValue(LCD_U8_EN, DIO_u8_LOW);
	
	_delay_ms(5);
	
	DIO_voidSetPinValue(LCD_U8_EN, DIO_u8_HIGH);
	
	_delay_ms(5);
}

void	LCD_VoidWriteCharacter(u8	copy_U8Char)
{
	/*1-SET RS PIN TO HIGH & EN PIN TO HIGH
	  2-SEND DATE
	  3-SET EN PIN TO LOW & WAIT 5ms
	  4-SET EN PIN TO high & WAIT 5ms	*/
	  
	DIO_voidSetPinValue(LCD_U8_RS, DIO_u8_HIGH);
	
	DIO_voidSetPinValue(LCD_U8_EN, DIO_u8_HIGH);
	
	SET_BYTE(PORTA, copy_U8CHAR);
	
	DIO_voidSetPinValue(LCD_U8_EN, DIO_u8_LOW);
	
	_delay_ms(5);
	
	DIO_voidSetPinValue(LCD_U8_EN, DIO_u8_HIGH);
	
	_delay_ms(5);  
}

void	LCD_VoidWriteString(u8*	copy_U8string, u8 copy_U8index)
{
	u8	LOC_U8Iteration;
	for(LOC_U8Iteration = 0; LOC_U8Iteration <= copy_U8index)
	{
		LCD_VoidWriteCharacter(copy_U8string[copy_U8index]);
		_delay_ms(2);
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





























void	LCD_VoidSendCommand(u8	copy_U8CMD);

void	LCD_VoidWriteCharacter(u8	copy_U8Char);

void	LCD_VoidWriteString(u8	copy_U8string, u8 copy_U8index);