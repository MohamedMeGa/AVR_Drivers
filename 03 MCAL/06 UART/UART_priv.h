/**************************************************/
/*   AUTHOR      : Mohamed	MeGa           		  */
/*   Description : USART DRIVER      			  */
/*   DATE        : 29 OCT 2021 					  */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	USART_PRIV_H
#define	USART_PRIV_H


/***************************************************/
/* Description :  MEMEROY MAPPING USART register   */
/***************************************************/

	#define	UDR		*((volatile	u8	*)	0X2C)
	#define	UCSRA	*((volatile	u8	*)	0X2B)
	#define	UCSRB	*((volatile	u8	*)	0X2A)
	#define	UCSRC	*((volatile	u8	*)	0X40)
	#define	UBRRL	*((volatile	u8	*)	0X29)
	#define	UBRRH	*((volatile	u8	*)	0X40)
	



	
#endif