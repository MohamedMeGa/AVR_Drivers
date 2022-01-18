/**************************************************/
/*   AUTHOR      : MOHAMED	MEGA	              */
/*   Description : USART 	DRIVER				  */
/*   DATE        : 29 OCT 2021                    */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	USART_INT_H
#define	USART_INT_H


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
#define		DATA_5BIT				0
#define		DATA_6BIT				1
#define		DATA_7BIT				2
#define		DATA_8BIT				3
#define		DATA_9BIT				4


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
/* Description :  function for Recieve date using USART		*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 USART Initializtion 					*/
/************************************************************/
u8	USART_U8Recieve(void);




#endif