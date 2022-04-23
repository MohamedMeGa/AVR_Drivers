/************************************************************/
/*   		AUTHOR      : Mohamed	MeGa	              	*/
/*   		Description : IIC DRIVER	  					*/
/*   		DATE        : 5 NOV 2021                    	*/
/*   		VERSION     : V02                            	*/
/************************************************************/

/************************************************************/
/*			library Directives						  		*/
/************************************************************/
#include	"STD_Types.h"
#include	"Bit_Math.h"


/************************************************************/
/**			IIC Directives						 			*/
/************************************************************/
#include	"IIC_int.h"
#include	"IIC_config.h"
#include	"IIC_priv.h"


/************************************************************/
/* 			Description :  IIC Functions Implementation 	*/
/************************************************************/

/************************************************************/
/* Description :  function for initialization The TWI		*/
/*				  in Master Mode							*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/

#if MASTER_SLAVE_MODE	==	MASTER
void	TWI_VoidMasterInitialization(void)
{
	/**			select prescalle b1 0 in twsr			*/
	#if TWI_FREQUENCY == PRES_1_DIV
		CLEAR_BIT(TWSR, 0);
		CLEAR_BIT(TWSR, 1);
	#elif TWI_FREQUENCY == PRES_4_DIV
		SET_BIT(TWSR, 0);
		CLEAR_BIT(TWSR, 1);
	#elif TWI_FREQUENCY == PRES_16_DIV
		CLEAR_BIT(TWSR, 0);
		SET_BIT(TWSR, 1);
	#elif TWI_FREQUENCY == PRES_64_DIV
		SET_BIT(TWSR, 0);
		SET_BIT(TWSR, 1);
	#endif
	
	/**			TWI Acknowledge 					   */
	#if TWI_ACK_MODE == ENABLE
		SET_BIT(TWCR, 6);
	#elif TWI_ACK_MODE == DISABLE
		CLEAR_BIT(TWCR, 6);
	#endif
	
	
	
	/**			Enable TWI 								*/
	SET_BIT(TWCR, 2);
}





/************************************************************/
/* Description :  function to Send start Condtion of  		*/
/*					TWI Master								*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
void	TWI_VoidSendStart(void)
{
	/**			Enable TWI 								*/
	SET_BIT(TWCR, 2);
	
	/**			Start Condition 						*/
	SET_BIT(TWCR, 5);
	
	/**			Clear Flag 								*/
	SET_BIT(TWCR, 7);
	
	while(GET_BIT(TWCR, 7) == 0 );
}




/************************************************************/
/* Description :  function to Send Data of  TWI Master 		*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TWI Send Slave Address Function 		*/
/************************************************************/
void	TWI_VoidMasterSendByte(u8 data)
{
	TWDR = data;
	
	/**			Enable TWI 								*/
	SET_BIT(TWCR, 2);
	
	/**			Clear Flag 								*/
	SET_BIT(TWCR, 7);
	
	while(GET_BIT(TWCR, 7) == 0 );
}





/************************************************************/
/* Description :  function to Send Stop Condtion of  		*/
/*					TWI Master								*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 Sending all data 						*/
/************************************************************/
void	TWI_VoidSendStop(void)
{
	/**			Enable TWI 								*/
	SET_BIT(TWCR, 2);
	
	/**			Start Condition 						*/
	SET_BIT(TWCR, 4);
	
	/**			Clear Flag 								*/
	SET_BIT(TWCR, 7);
}






/************************************************************/
/* Description :  function for Send Slave TWI Address	 	*/
/*				  in write Mode								*/
/*				  input	 :	u8								*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TWI Send Start Function 				*/
/************************************************************/
void	TWI_VoidSendSlaveADDWrite(u8 Copy_u8slaveAddress)
{
	TWDR = Copy_u8slaveAddress << 1;
	
	/**			make Write option 						*/
	SET_BIT(TWDR, 0);
	
	/**			Enable TWI 								*/
	SET_BIT(TWCR, 2);
	
	/**			Clear Flag 								*/
	SET_BIT(TWCR, 7);
	
	while(GET_BIT(TWCR, 7) == 0 );
}






/************************************************************/
/* Description :  function for Send Slave TWI Address	 	*/
/*				  in Read Mode								*/
/*				  input	 :	u8								*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TWI Send Start Function 				*/
/************************************************************/
void	TWI_VoidSendSlaveADDRead(u8 Copy_u8slaveAddress)
{
	TWDR = Copy_u8slaveAddress << 1;
	
	/**			make Write option 						*/
	CLEAR_BIT(TWDR, 0);
	
	/**			Enable TWI 								*/
	SET_BIT(TWCR, 2);
	
	/**			Clear Flag 								*/
	SET_BIT(TWCR, 7);
	
	while(GET_BIT(TWCR, 7) == 0 );
}







/************************************************************/
/* Description :  function to Check TWI Status			   	*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TWI Initializtion 						*/
/************************************************************/
u8	TWI_VoidCheckStatus(void)
{
	retrn TWSR & 0xF8;
}





#elif MASTER_SLAVE_MODE	==	SLAVE
/************************************************************/
/* Description :  function for initialization The TWI		*/
/*				  in Slave Mode								*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
void	TWI_VoidSlaveInitialization(u8 copy_u8SlaveAddress)
{
	/**			Enable TWI 								*/
	SET_BIT(TWCR, 2);
	
	TWAR = copy_u8SlaveAddress << 1;
	
	/**			TWI Broadcast Mode 					   */
	#if TWI_BROADCAST == ENABLE
		SET_BIT(TWAR, 0);
	#elif TWI_BROADCAST == DISABLE
		CLEAR_BIT(TWAR, 0);
	#endif
	
	/**			Clear Flag 								*/
	SET_BIT(TWCR, 7);
	
	/**			Enable TWI 								*/
	SET_BIT(TWCR, 2);
	
	/**			Enable Acknowledge 						*/
	SET_BIT(TWCR, 6);
}





/************************************************************/
/* Description :  function to Send Data of  TWI Slave 		*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TWI Slave initialize			 		*/
/************************************************************/
void	TWI_VoidSlaveSendByte(u8 data)
{
	TWDR = data;
	
	/**			Enable TWI 								*/
	SET_BIT(TWCR, 2);
	
	/**			Clear Flag 								*/
	SET_BIT(TWCR, 7);
	
	/**			Enable Acknowledge 						*/
	SET_BIT(TWCR, 6);
	
	while(GET_BIT(TWCR, 7) == 0 );
}


/************************************************************/
/* Description :  function to listen on Data Bus		  	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TWI Slave Initializtion 				*/
/************************************************************/
void	TWI_VoidSlaveListen(void)
{
	while(GET_BIT(TWCR, 7) == 0 );
}
#endif





/************************************************************/
/* Description :  function Recieve one Byte Data From TWI  	*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TWI Initializtion 						*/
/************************************************************/
u8	TWI_VoidRecieveWithNACK(void)
{
	/**			Enable TWI 								*/
	SET_BIT(TWCR, 2);
	
	/**			Clear Flag 								*/
	SET_BIT(TWCR, 7);
	
	while(GET_BIT(TWCR, 7) == 0 );
	
	return TWDR;
}



#endif