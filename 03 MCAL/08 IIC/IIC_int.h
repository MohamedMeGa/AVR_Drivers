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
/* Description :  function for initialization The TWI		*/
/*				  in Master Mode							*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/

void	TWI_VoidMasterInitialization(void);





/************************************************************/
/* Description :  function for initialization The TWI		*/
/*				  in Slave Mode								*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
void	TWI_VoidSlaveInitialization(u8 copy_u8SlaveAddress);




/************************************************************/
/* Description :  function to listen on Data Bus		  	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TWI Slave Initializtion 				*/
/************************************************************/
void	TWI_VoidSlaveListen(void);




/************************************************************/
/* Description :  function to Send start Condtion of  		*/
/*					TWI Master								*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
void	TWI_VoidMasterSendByte(void);



/************************************************************/
/* Description :  function to Send Data of  TWI Slave 		*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TWI Slave initialize			 		*/
/************************************************************/
void	TWI_VoidSlaveSendByte(u8 data);






/************************************************************/
/* Description :  function to Send Data of  TWI Master 		*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TWI Send Slave Address Function 		*/
/************************************************************/
void	TWI_VoidSendByte(u8 data);





/************************************************************/
/* Description :  function to Send Stop Condtion of  		*/
/*					TWI Master								*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 Sending all data 						*/
/************************************************************/
void	TWI_VoidSendStop(void);




/************************************************************/
/* Description :  function for Send Slave TWI Address	 	*/
/*				  in write Mode								*/
/*				  input	 :	u8								*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TWI Send Start Function 				*/
/************************************************************/
void	TWI_VoidSendSlaveADDWrite(u8 Copy_u8slaveAddress);






/************************************************************/
/* Description :  function for Send Slave TWI Address	 	*/
/*				  in Read Mode								*/
/*				  input	 :	u8								*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TWI Send Start Function 				*/
/************************************************************/
void	TWI_VoidSendSlaveADDRead(u8 Copy_u8slaveAddress);







/************************************************************/
/* Description :  function to Check TWI Status			   	*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TWI Initializtion 						*/
/************************************************************/
u8	TWI_VoidCheckStatus(void);



/************************************************************/
/* Description :  function Recieve Data From TWI		   	*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
u8	TWI_VoidRecieveWithNACK(void);