/**************************************************/
/*   AUTHOR      : MOHAMED	MEGA	              */
/*   Description : KEYPAD DRIVER       		      */
/*   DATE        : 2 OCT 2021                     */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	KEYPAD_INT_H
#define	KEYPAD_INT_H
	
const u8 KPD_au8SwitchVal[4][4] =
{
  {
    0x04,
    0x08,
    0x0C,
    0x10 },
  {
    0x03,
    0x07,
    0x0B,
    0x0F },
  {
    0x02,
    0x06,
    0x0A,
    0x0E },
  {
    0x01,
    0x05,
    0x09,
    0x0D } 
};

/***************************************************/
/* Description :  PROTOTYPE DECLARTION 		   	   */



/* Description :  function to GET THE VALUE FROM KEYPAD	*/
				  
u8	KEYPAD_U8GetPressedKey(void);

#endif