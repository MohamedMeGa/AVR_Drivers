/**************************************************/
/*   AUTHOR      : MOHAMED	MEGA	              */
/*   Description : LCD DRIVER       		      */
/*   DATE        : 1 OCT 2021                     */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	LCD_INT_H
#define	LCD_INT_H

/**		TYPE OF 7 SEG	RIGHT OR LEFT				*/
	


/***************************************************/
/* Description :  PROTOTYPE DECLARTION 		   	   */



/* Description :  function to initialize lcd conection	*/
				  
void	LCD_VoidLCDInit(void);

void	LCD_VoidSendCommand(u8	copy_U8CMD);

void	LCD_VoidWriteCharacter(u8	copy_U8Char);

void	LCD_VoidWriteString(u8	copy_U8string, u8 copy_U8index);

void Gotoxy (u8 Y,u8 X);

#endif