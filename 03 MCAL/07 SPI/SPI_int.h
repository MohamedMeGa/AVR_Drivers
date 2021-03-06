/**************************************************/
/*   AUTHOR      : MOHAMED	MEGA	              */
/*   Description : SPI 	DRIVER					  */
/*   DATE        : 2 NOV 2021                     */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	SPI_INT_H
#define	SPI_INT_H

/***************************************************/
/**			MODE OF INTERRUPT Selections Options   */
/***************************************************/
#define		DISABLE				4					
#define		ENABLE				7



/***************************************************/
/**			MODE OF MASTER SLAVE Options	  	   */
/***************************************************/
#define		MASTER				0
#define		SLAVE				1






/***************************************************/
/**			DATE ORDER selection Options	   	   */
/***************************************************/
#define		LSB_FIRST			3
#define		MSB_FIRST			1




/***************************************************/
/**			CLOCK PHASE selection Options	   	   */
/***************************************************/
#define		ZERO				0
#define		ONE					2


/***************************************************/
/**			CLOCK POLARITY selection Options 	   */
/***************************************************/
#define		FALLING				0
#define		RISING				1





/***************************************************/
/* Description :  PROTOTYPE DECLARTION 		   	   */
/***************************************************/

/************************************************************/
/* Description :  function for initialization The SPI		*/
/*				  in Master Mode							*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/

void	SPI_VoidMASTERInitialization(void);




/************************************************************/
/* Description :  function for initialization The SPI		*/
/*				  in SLAVE Mode								*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/

void	SPI_VoidSLAVEInitialization(void);





/************************************************************/
/* Description :  function for Transfer date using SPI		*/
/*				  input	 :	u8								*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
u8		SPI_VoidSendTransfer(u8 Copy_u8Date);




/************************************************************/
/* Description :  function for Recieve date using SPI in 	*/
/*				   interrupt Mode							*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
u8	SPI_U8ReadDateISR(void);




/************************************************************/
/* Description :  function for Send date using SPI in 		*/
/*				   interrupt Mode							*/
/*				  input	 :	u8								*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
void	SPI_VoidSendDateISR(u8 Copy_u8Date);


/************************************************************/
/* Description :  function to set the callback function   	*/
/*				  using SPI in interrupt Mode				*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
void	SPI_VoidSetCallBack(void);
#endif