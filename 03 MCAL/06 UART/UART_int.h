/**************************************************/
/*   AUTHOR      : MOHAMED	MEGA	              */
/*   Description : USART 	DRIVER				  */
/*   DATE        : 29 OCT 2021                    */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	USART_INT_H
#define	USART_INT_H





/***************************************************/
/* Description :  PROTOTYPE DECLARTION 		   	   */
/***************************************************/

/************************************************************/
/* Description :  function for initialization The USART		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/

void	USART_VoidInitialization(void);


/************************************************************/
/* Description :  function for Transmit date using USART	*/
/*				  input	 :	u8								*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 USART Initializtion 					*/
/************************************************************/
void	USART_VoidTransmit(u8 Copy_u8Date);




/************************************************************/
/* Description :  function for Recieve date using USART	*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 USART Initializtion 					*/
/************************************************************/
u8	USART_U8Recieve(void);




#endif