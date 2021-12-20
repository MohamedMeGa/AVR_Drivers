/**************************************************/
/*   AUTHOR      : Mohamed	MeGa           		  */
/*   Description : USART DRIVER      			  */
/*   DATE        : 29 OCT 2021 					  */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	USART_PRIV_H
#define	USART_PRIV_H

/***************************************************/
/**			MODE OF OPERATION Selections Options */
/***************************************************/
#define		ASYNCRONOUS			4					
#define		SYNCRONOUS			7



/***************************************************/
/**			SPEED OPERATION selection Options	   */
/***************************************************/
#define		NORMAL_SPEED		0
#define		DOUBLE_SPEED		1



/***************************************************/
/**			DATE SIZE selections Options		   */
/***************************************************/
#define		5_BIT				0
#define		6_BIT				1
#define		7_BIT				2
#define		8_BIT				3
#define		9_BIT				4


/***************************************************/
/**			STOP BIT selection Options	   		   */
/***************************************************/
#define		ONE_BIT				0
#define		TWO_BIT				1




/***************************************************/
/**			PARITY MODE selection Options	   	   */
/***************************************************/
#define		DISABLE				0
#define		EVEN				1
#define		ODD					2


/***************************************************/
/**			CLOCK POLARITY selection Options 	   */
/***************************************************/
#define		FALLING				0
#define		RISING				1



/***************************************************/
/* Description :  MEMEROY MAPPING USART register  */
/***************************************************/

	#define	UDR		*((volatile	u8	*)	0X2C)
	#define	UCSRA	*((volatile	u8	*)	0X2B)
	#define	UCSRB	*((volatile	u8	*)	0X2A)
	#define	UCSRC	*((volatile	u8	*)	0X40)
	#define	UBRRL	*((volatile	u8	*)	0X29)
	#define	UBRRH	*((volatile	u8	*)	0X40)
	



	
#endif