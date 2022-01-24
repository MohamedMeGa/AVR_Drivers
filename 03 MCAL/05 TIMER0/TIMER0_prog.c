/************************************************************/
/*   		AUTHOR      : Mohamed	MeGa	              	*/
/*   		Description : ADC DRIVER	  					*/
/*   		DATE        : 07 OCT 2021                    	*/
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
#include	"TIMER0_int.h"
#include	"TIMER0_config.h"
#include	"TIMER0_priv.h"


/************************************************************/
/* Description :  Timer 0 Implemention 		   	   			*/
/************************************************************/

volatile pf Timer0_OV_CallBack;
volatile pf Timer0_CTC_CallBack;


/************************************************************/
/* Description :  function for initialization The TIMER0	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/

void	TIMER0_VoidInitialization(void)
{
/**			Prescaller Selection Options				*/
	#if		TIMER0_PRESCALLER	==	NO_CLOCK
		CLEAR_BIT(TCCR0, 0);
		CLEAR_BIT(TCCR0, 1);
		CLEAR_BIT(TCCR0, 2);
	#elif	TIMER0_PRESCALLER	==	CLK_NO_PRES
		SET_BIT(TCCR0, 0);
		CLEAR_BIT(TCCR0, 1);
		CLEAR_BIT(TCCR0, 2);
	#elif	TIMER0_PRESCALLER	==	PRES_8_DIV
		CLEAR_BIT(TCCR0, 0);
		SET_BIT(TCCR0, 1);
		CLEAR_BIT(TCCR0, 2);
	#elif	TIMER0_PRESCALLER	==	PRES_64_DIV
		SET_BIT(TCCR0, 0);
		SET_BIT(TCCR0, 1);
		CLEAR_BIT(TCCR0, 2);
	#elif	TIMER0_PRESCALLER	==	PRES_256_DIV
		CLEAR_BIT(TCCR0, 0);
		CLEAR_BIT(TCCR0, 1);
		SET_BIT(TCCR0, 2);
	#elif	TIMER0_PRESCALLER	==	PRES_1024_DIV
		SET_BIT(TCCR0, 0);
		CLEAR_BIT(TCCR0, 1);
		SET_BIT(TCCR0, 2);
	#elif	TIMER0_PRESCALLER	==	External_Falling
		CLEAR_BIT(TCCR0, 0);
		SET_BIT(TCCR0, 1);
		SET_BIT(TCCR0, 2);
	#elif	TIMER0_PRESCALLER	==	External_Rising
		SET_BIT(TCCR0, 0);
		SET_BIT(TCCR0, 1);
		SET_BIT(TCCR0, 2);
	#endif
	
	
/**			TIMER0 Mode Selection Options				*/
	#if		TIMER0_MODE			==	TIMER0_NORMAL
		CLEAR_BIT(TCCR0, 3);
		CLEAR_BIT(TCCR0, 6);
	#elif	TIMER0_MODE			==	TIMER0_PWM
		SET_BIT(TCCR0, 6);
		CLEAR_BIT(TCCR0, 3);
	#elif	TIMER0_MODE			==	TIMER0_CTC
		CLEAR_BIT(TCCR0, 6);
		SET_BIT(TCCR0, 3);
	#elif	TIMER0_MODE			==	TIMER0_FASTPWM
		SET_BIT(TCCR0, 3);
		SET_BIT(TCCR0, 6);
	#endif
	


	/**			Compare Output Mode Selection Options	*/
	#if		TIMER0_COM_EVENT	==	TIMER0_NO_ACTION
		CLEAR_BIT(TCCR0, 4);
		CLEAR_BIT(TCCR0, 5);
	#elif	TIMER0_COM_EVENT	==	TIMER0_TOGGLE
		SET_BIT(TCCR0, 4);
		CLEAR_BIT(TCCR0, 5);
	#elif	TIMER0_COM_EVENT	==	TIMER0_CLEAR
		CLEAR_BIT(TCCR0, 4);
		SET_BIT(TCCR0, 5);
	#elif	TIMER0_COM_EVENT	==	TIMER0_SET
		SET_BIT(TCCR0, 4);
		SET_BIT(TCCR0, 5);
	#endif
	
	/**			Disable	OverFlow Interrupt				*/
	CLEAR_BIT(TIMSK, 0);
	
	/**			Disable Output Comapre Match Interrupt	*/
	CLEAR_BIT(TIMSK, 1);
	
	/**			Clear Output Comapre Match Flag			*/
	SET_BIT(TIFR, 0);
	
	/**			Clear OverFlow Flag						*/
	SET_BIT(TIFR, 1);
	
	/**			Free OverFlow and OCR	Regesters		*/
	TCNT0	=	0x00;
	OCR0	=	0x00;
}






/************************************************************/
/* Description :  function to Enable the TIMER0 	 		*/
/*				  of overflow Interrupt	 					*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TIMER0 Initializtion	 				*/
/************************************************************/

void	TIMER0_VoidEnableOVInterrupt(void)
{
	SET_BIT(TIMSK, 0);
}



/************************************************************/
/* Description :  function to Disable the TIMER0 of			*/
/*				   overflow Interrupt	 					*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TIMER0 Initializtion	 				*/
/************************************************************/

void	TIMER0_VoidDisableOVInterrupt(void)
{
	CLEAR_BIT(TIMSK, 0);
}









/************************************************************/
/* Description :  function to Enable the TIMER0 	 		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TIMER0 Initializtion	 				*/
/************************************************************/

void	TIMER0_VoidEnableCTCInterrupt(void)
{
	SET_BIT(TIMSK, 1);
}



/************************************************************/
/* Description :  function to Disable the TIMER0 			*/
/*					of CTC Interrupt	 					*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TIMER0 Initializtion	 				*/
/************************************************************/

void	TIMER0_VoidDisableCTCInterrupt(void)
{
	CLEAR_BIT(TIMSK, 1);
}





/************************************************************/
/* Description :  function to Set TCNT Regisers		 		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 Timer0 Enable			 				*/
/************************************************************/

void	TIMER0_VoidSetTIMER0REG(u8 Copy_u8TIMER0REG)
{
	TCNT0	=	Copy_u8TIMER0REG;
}



/************************************************************/
/* Description :  function to set OCR Register				*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 Timer0 initialized 					*/
/************************************************************/
void	TIMER0_VoidSetOCRREG(u8 Copy_u8OCRREG)
{
	OCR0	=	Copy_u8OCRREG;
}


/************************************************************/
/* Description :  function to set Timer0 Callback Function	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 enable OverFlow Interrupt 				*/
/************************************************************/

void	TIMER0_VoidSetOVCallback(pf	copy_FunctionAdress)
{
	Timer0_OV_CallBack	=	copy_FunctionAdress;
}



/************************************************************/
/* Description :  function to set CTC Callback Function		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 enable CTC Interrupt 				*/
/************************************************************/

void	TIMER0_VoidSetCTCCallback(pf	copy_FunctionAdress)
{
	Timer0_CTC_CallBack	=	copy_FunctionAdress;
}


void	__vector_11(void)	__attribute__((signal, used));
void	__vector_11(void)
{
	Timer0_OV_CallBack();
}


void	__vector_10(void)	__attribute__((signal, used));
void	__vector_10(void)
{
	Timer0_CTC_CallBack();
}