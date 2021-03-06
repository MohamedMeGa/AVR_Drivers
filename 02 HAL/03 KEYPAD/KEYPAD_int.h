/**************************************************/
/*   AUTHOR      : MOHAMED	MEGA	              */
/*   Description : KEYPAD DRIVER       		      */
/*   DATE        : 2 OCT 2021                     */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	KEYPAD_INT_H
#define	KEYPAD_INT_H
	

/***************************************************/
/* Description :  PROTOTYPE DECLARTION 		   	   */
/***************************************************/


/***************************************************/
/* Description :  function to init THE KEYPAD	*/
/***************************************************/
void	KEYPAD_VoidInit(void);


/***************************************************/
/* Description :  function to GET THE VALUE FROM KEYPAD	*/
/***************************************************/

u8	KEYPAD_U8GetPressedKey(void);

#endif