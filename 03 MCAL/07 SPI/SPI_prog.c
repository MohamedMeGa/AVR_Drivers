/************************************************************/
/*   		AUTHOR      : Mohamed	MeGa	              	*/
/*   		Description : SPI DRIVER	  					*/
/*   		DATE        : 4 NOV 2021                    	*/
/*   		VERSION     : V02                            	*/
/************************************************************/

/************************************************************/
/*			library Directives						  		*/
/************************************************************/
#include	"STD_Types.h"
#include	"Bit_Math.h"


/************************************************************/
/**			SPI Directives						 			*/
/************************************************************/
#include	"SPI_int.h"
#include	"SPI_config.h"
#include	"SPI_priv.h"

volatile pf SPI_Callback;


/************************************************************/
/* 			Description :  SPI Functions Implementation 	*/
/************************************************************/

/************************************************************/
/* Description :  function for initialization The SPI		*/
/*				  in Master Mode							*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
#if		MODE_OF_MASTER_SLAVE	==	MASTER

void	SPI_VoidMASTERInitialization(void)
{
	SET_BIT(SPCR, 6);
	
	#if		MODE_OF_INTERRUPT	==	ENABLE
		SET_BIT(SPCR, 7);
	#elif	MODE_OF_INTERRUPT	==	DISABLE
		CLEAR_BIT(SPCR, 7);
	#endif
	
	SET_BIT(SPCR, 4);
	
	#if		DATE_ORDER			==	LSB_FIRST
		SET_BIT(SPCR, 5);
	#elif	DATE_ORDER			==	MSB_FIRST
		CLEAR_BIT(SPCR, 5);
	#endif
	
	#if		CLOCK_POLARITY		==	HIGH_IDLE
		SET_BIT(SPCR, 3);
	#elif	CLOCK_POLARITY		==	LOW_IDLE
		CLEAR_BIT(SPCR, 3);
	#endif
	
	#if		CLOCK_PHASE			==	ZERO
		CLEAR_BIT(SPCR, 2);
	#elif	CLOCK_PHASE			==	ONE
		SET_BIT(SPCR, 2);
	#endif
	
	#if		SPI_FREQUENCY	==	F_CPU_BY_4
		CLEAR_BIT(SPCR, 0);
		CLEAR_BIT(SPCR, 1);
		CLEAR_BIT(SPSR, 2);
	#elif	SPI_FREQUENCY	==	F_CPU_BY_16
		SET_BIT(SPCR, 	0);
		CLEAR_BIT(SPCR, 1);
		CLEAR_BIT(SPSR, 2);
	#elif	SPI_FREQUENCY	==	F_CPU_BY_128
		SET_BIT(SPCR, 0);
		SET_BIT(SPCR, 1);
		CLEAR_BIT(SPSR, 2);
	#elif	SPI_FREQUENCY	==	F_CPU_BY_2
		CLEAR_BIT(SPCR, 0);
		CLEAR_BIT(SPCR, 1);
		SET_BIT(SPSR, 2);
	#elif	SPI_FREQUENCY	==	F_CPU_BY_8
		SET_BIT(SPCR, 0);
		CLEAR_BIT(SPCR, 1);
		SET_BIT(SPSR, 2);
	#elif	SPI_FREQUENCY	==	F_CPU_BY_32
		CLEAR_BIT(SPCR, 0);
		SET_BIT(SPCR, 1);
		SET_BIT(SPSR, 2);
	#elif	SPI_FREQUENCY	==	F_CPU_BY_64
		SET_BIT(SPCR, 0);
		SET_BIT(SPCR, 1);
		SET_BIT(SPSR, 2);
	#endif
}




/************************************************************/
/* Description :  function for initialization The SPI		*/
/*				  in SLAVE Mode								*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
#elif	MODE_OF_MASTER_SLAVE	==	SLAVE
void	SPI_VoidSLAVEInitialization(void)
{
	SET_BIT(SPCR, 6);
	
	#if		MODE_OF_INTERRUPT	==	ENABLE
		SET_BIT(SPCR, 7);
	#elif	MODE_OF_INTERRUPT	==	DISABLE
		CLEAR_BIT(SPCR, 7);
	#endif
	
	CLEAR_BIT(SPCR, 4);
	
	#if		DATE_ORDER			==	LSB_FIRST
		SET_BIT(SPCR, 5);
	#elif	DATE_ORDER			==	MSB_FIRST
		CLEAR_BIT(SPCR, 5);
	#endif
	
	#if		CLOCK_POLARITY		==	HIGH_IDLE
		SET_BIT(SPCR, 3);
	#elif	CLOCK_POLARITY		==	LOW_IDLE
		CLEAR_BIT(SPCR, 3);
	#endif
	
	#if		CLOCK_PHASE			==	ZERO
		CLEAR_BIT(SPCR, 2);
	#elif	CLOCK_PHASE			==	ONE
		SET_BIT(SPCR, 2);
	#endif
	
	#if		SPI_FREQUENCY	==	F_CPU_BY_4
		CLEAR_BIT(SPCR, 0);
		CLEAR_BIT(SPCR, 1);
		CLEAR_BIT(SPSR, 2);
	#elif	SPI_FREQUENCY	==	F_CPU_BY_16
		SET_BIT(SPCR, 	0);
		CLEAR_BIT(SPCR, 1);
		CLEAR_BIT(SPSR, 2);
	#elif	SPI_FREQUENCY	==	F_CPU_BY_128
		SET_BIT(SPCR, 0);
		SET_BIT(SPCR, 1);
		CLEAR_BIT(SPSR, 2);
	#elif	SPI_FREQUENCY	==	F_CPU_BY_2
		CLEAR_BIT(SPCR, 0);
		CLEAR_BIT(SPCR, 1);
		SET_BIT(SPSR, 2);
	#elif	SPI_FREQUENCY	==	F_CPU_BY_8
		SET_BIT(SPCR, 0);
		CLEAR_BIT(SPCR, 1);
		SET_BIT(SPSR, 2);
	#elif	SPI_FREQUENCY	==	F_CPU_BY_32
		CLEAR_BIT(SPCR, 0);
		SET_BIT(SPCR, 1);
		SET_BIT(SPSR, 2);
	#elif	SPI_FREQUENCY	==	F_CPU_BY_64
		SET_BIT(SPCR, 0);
		SET_BIT(SPCR, 1);
		SET_BIT(SPSR, 2);
	#endif
}
#endif




/************************************************************/
/* Description :  function for Recieve date using SPI in 	*/
/*				   interrupt Mode							*/
/*				  input	 :	void							*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
#if		MODE_OF_INTERRUPT	==	ENABLE

u8	SPI_U8ReadDateISR(void)
{
	return SPDR;
}




/************************************************************/
/* Description :  function for Send date using SPI in 		*/
/*				   interrupt Mode							*/
/*				  input	 :	u8								*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
void	SPI_VoidSendDateISR(u8 Copy_u8Date)
{
	SPDR = Copy_u8Date;
}


/************************************************************/
/* Description :  function to set the callback function   	*/
/*				  using SPI in interrupt Mode after serial	*/ 
/*				  transfer Complete							*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
void	SPI_VoidSetCallBack(pf copy_functionAddress)
{
	SPI_Callback = copy_functionAddress;
}


#elif		MODE_OF_INTERRUPT	==	DISABLE

/************************************************************/
/* Description :  function for Transfer date using SPI		*/
/*				  input	 :	u8								*/
/*				  output :	u8								*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 SPI Initializtion 						*/
/************************************************************/
u8		SPI_VoidSendTransfer(u8 Copy_u8Date)
{
	SPDR	=	Copy_u8Date;
	while(GET_BIT(SPSR, 7) == 0);
	return SPDR
}

#endif



void	__vector_13(void)		__attribute__((signal, used));
void	__vector_13(void)
{
	SPI_Callback();
}