/**************************************************/
/*   AUTHOR      : MOHAMED	MEGA	              */
/*   Description : IIC 	DRIVER					  */
/*   DATE        : 2 NOV 2021                     */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	IIC_INT_H
#define	IIC_INT_H





/***************************************************/
/* Description :  PROTOTYPE DECLARTION 		   	   */
/***************************************************/

/************************************************************/
/* Description :  function for initialization The SPI		*/
/*				  in Master Mode							*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/

void	TWI_VoidInitialization(void);



/************************************************************/
/* Description :  function for initialization The SPI		*/
/*				  in SLAVE Mode								*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/

void	TWI_VoidSendByte(u8 data);





/************************************************************/
/* Description :  function for Transfer date using SPI		*/
/*				  input	 :	u8								*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
void	TWI_VoidSendStart(u8 Copy_u8Date);




/************************************************************/
/* Description :  function for Recieve date using SPI in 	*/
/*				   interrupt Mode							*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
void	TWI_VoidSendStop(void);




/************************************************************/
/* Description :  function for Send date using SPI in 		*/
/*				   interrupt Mode							*/
/*				  input	 :	u8								*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
void	TWI_VoidSendSlaveACK(u8 Copy_u8Date);


/************************************************************/
/* Description :  function to set the callback function   	*/
/*				  using SPI in interrupt Mode				*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
u8	TWI_VoidCheckStatus(void);



/************************************************************/
/* Description :  function to set the callback function   	*/
/*				  using SPI in interrupt Mode				*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
u8	TWI_VoidRecieveWithNACK(void);