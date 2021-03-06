/************************************************************/
/*   		AUTHOR      : Mohamed	MeGa	              	*/
/*   		Description : USART DRIVER	  					*/
/*   		DATE        : 29 OCT 2021                    	*/
/*   		VERSION     : V02                            	*/
/************************************************************/

/************************************************************/
/*			library Directives						  		*/
/************************************************************/
#include	"STD_Types.h"
#include	"Bit_Math.h"


/************************************************************/
/**			EXTI Directives						 			*/
/************************************************************/
#include	"UART_int.h"
#include	"UART_config.h"
#include	"UART_priv.h"


/************************************************************/
/* Description :  Timer 0 Implemention 		   	   			*/
/************************************************************/

/************************************************************/
/* Description :  function for initialization The USART		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/

void	USART_VoidInitialization(void)
{
	u16	Loc_u8BaudeRateEquation = 0;
	u8	Loc_u8UCSRC = 0;
	
	#if		MODE_OF_OPERATION	==	ASYNCRONOUS
		CLEAR_BIT(Loc_u8UCSRC, 6);
	#elif	MODE_OF_OPERATION	==	SYNCRONOUS
		SET_BIT(Loc_u8UCSRC, 6);
	#endif
	
	#if		PARITY_MODE	==	DISABLE
		CLEAR_BIT(Loc_u8UCSRC, 5);
		CLEAR_BIT(Loc_u8UCSRC, 4);
	#elif	PARITY_MODE	==	EVEN
		SET_BIT(Loc_u8UCSRC, 5);
		CLEAR_BIT(Loc_u8UCSRC, 4);
	#elif	PARITY_MODE	==	ODD
		SET_BIT(Loc_u8UCSRC, 5);
		SET_BIT(Loc_u8UCSRC, 4);
	#endif
	
	#if		MODE_OF_OPERATION	==	ASYNCRONOUS
		if		(SPEED_OPERATION	==	DOUBLE_SPEED)
			SET_BIT(UCSRA, 1);
		else if	(SPEED_OPERATION	==	NORMAL_SPEED)
			CLEAR_BIT(UCSRA, 1);
		
	#elif	MODE_OF_OPERATION	==	SYNCRONOUS
		CLEAR_BIT(UCSRA, 1);
	#endif
	
	/**			BaudeRate Equation						*/
	#if		MODE_OF_OPERATION	==	ASYNCRONOUS
		if		(GET_BIT(UCSRA, 1)	==	0)
			Loc_u8BaudeRateEquation = ((F_CPU / (16 * BaudRate)) - 1);
		else if	(GET_BIT(UCSRA, 1)	==	1)
			Loc_u8BaudeRateEquation = ((F_CPU / (8 * BaudRate)) - 1);
		
	#elif	MODE_OF_OPERATION	==	SYNCRONOUS
		Loc_u8BaudeRateEquation = ((F_CPU / (2 * BaudRate)) - 1);
	#endif
	
	UBRRH	= (u8)(Loc_u8BaudeRateEquation >> 8);
	UBRRL	= (u8)(Loc_u8BaudeRateEquation);
	
	
	SET_BIT(UCSRB, 4);
	SET_BIT(UCSRB, 3);
	
	/**			DATE SIZE Selection Options				*/
	#if		DATE_SIZE	==	DATA_5BIT
		CLEAR_BIT(Loc_u8UCSRC, 1);
		CLEAR_BIT(Loc_u8UCSRC, 2);
		CLEAR_BIT(UCSRB, 2);
	#elif	DATE_SIZE	==	DATA_6BIT
		SET_BIT(Loc_u8UCSRC, 	1);
		CLEAR_BIT(Loc_u8UCSRC, 	2);
		CLEAR_BIT(UCSRB, 2);
	#elif	DATE_SIZE	==	DATA_7BIT
		CLEAR_BIT(Loc_u8UCSRC, 	1);
		SET_BIT(Loc_u8UCSRC	, 	2);
		CLEAR_BIT(UCSRB, 2);
	#elif	DATE_SIZE	==	DATA_8BIT
		SET_BIT(Loc_u8UCSRC, 1);
		SET_BIT(Loc_u8UCSRC, 2);
		CLEAR_BIT(UCSRB, 2);
	#elif	DATE_SIZE	==	DATA_9BIT
		SET_BIT(Loc_u8UCSRC, 1);
		SET_BIT(Loc_u8UCSRC, 2);
		SET_BIT(UCSRB, 2);
	#endif
	
	
	#if		STOP_BIT_SELECT	==	ONE_BIT
		CLEAR_BIT(Loc_u8UCSRC, 3);
	#elif	STOP_BIT_SELECT	==	TWO_BIT
		SET_BIT(Loc_u8UCSRC, 	3);
	#endif
	
	


	#if	MODE_OF_OPERATION	==	SYNCRONOUS		
		#if		CLOCK_POLARITY	==	FALLING
			SET_BIT(Loc_u8UCSRC, 0);
		#elif	CLOCK_POLARITY	==	RISING
			CLEAR_BIT(Loc_u8UCSRC, 0);
		#endif
	#endif
	
	/****************************************************************/
	/** !comment :													*/
	/** 		  This bit selects between accessing the UCSRC or 	*/
	/*							the UBRRH Register.					*/
	/*				It is read as one when reading UCSRC.			*/
	/*				The URSEL must be one when writing the UCSRC.	*/
	/****************************************************************/
	SET_BIT(Loc_u8UCSRC, 7);
	UCSRC = Loc_u8UCSRC;
}


/************************************************************/
/* Description :  function for Transmit date using USART	*/
/*				  input	 :	u8								*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 USART Initializtion 					*/
/************************************************************/
void	USART_VoidTransmit(u8 Copy_u8Date)
{
	/* Wait for empty transmit buffer */
	while(GET_BIT(UCSRA, 5) == 0);
	
	UDR	=	Copy_u8Date;
}




/************************************************************/
/* Description :  function for Recieve date using USART		*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 USART Initializtion 					*/
/************************************************************/
u8	USART_U8Recieve(void)
{
	/* Wait for data to be received 						*/
	while(GET_BIT(UCSRA, 7) == 0);
	
	/**	Clear the Flag (USART Recieve Complete) 			*/
	CLEAR_BIT(UCSRA, 7);
	return	UDR;
}