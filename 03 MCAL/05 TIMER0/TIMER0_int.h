/**************************************************/
/*   AUTHOR      : MOHAMED	MEGA	              */
/*   Description : TIMER 0 	DRIVER				  */
/*   DATE        : 19 OCT 2021                    */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	TIMER0_INT_H
#define	TIMER0_INT_H

/***************************************************/
/**			Compare Output Mode Selections Options */
/***************************************************/
#define		TIMER0_NO_ACTION	4					
#define		TIMER0_TOGGLE		7
#define		TIMER0_CLEAR		9
#define		TIMER0_SET			2


/***************************************************/
/**			TIMER0 Mode selection Options		   */
/***************************************************/
#define		TIMER0_NORMAL		0
#define		TIMER0_PWM			1
#define		TIMER0_CTC			2
#define		TIMER0_FASTPWM		3


/***************************************************/
/**			Prescaller selections Options		   */
/***************************************************/
#define		NO_CLOCK			0
#define		CLK_NO_PRES			2
#define		PRES_64_DIV			3
#define		PRES_256_DIV		4
#define		PRES_1024_DIV		5
#define		External_Falling	6
#define		External_Rising		7






/************************************************************/
/* 			Description :  PROTOTYPE DECLARTION 		   	*/
/************************************************************/

/************************************************************/
/* Description :  function for initialization The TIMER0	*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/

void	TIMER0_VoidInitialization(void);






/************************************************************/
/* Description :  function to Enable the TIMER0 	 		*/
/*				  of overflow Interrupt	 					*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TIMER0 Initializtion	 				*/
/************************************************************/

void	TIMER0_VoidEnableOVInterrupt(void);



/************************************************************/
/* Description :  function to Disable the TIMER0 of			*/
/*				   overflow Interrupt	 					*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TIMER0 Initializtion	 				*/
/************************************************************/

void	TIMER0_VoidDisableOVInterrupt(void);





/************************************************************/
/* Description :  function to Enable the TIMER0 	 		*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TIMER0 Initializtion	 				*/
/************************************************************/

void	TIMER0_VoidEnableCTCInterrupt(void);



/************************************************************/
/* Description :  function to Disable the TIMER0 			*/
/*					of CTC Interrupt	 					*/
/*				  input	 :	void							*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 TIMER0 Initializtion	 				*/
/************************************************************/

void	TIMER0_VoidDisableCTCInterrupt(void);





/************************************************************/
/* Description :  function to Set TCNT Regisers		 		*/
/*				  input	 :	u8								*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 Timer0 Enable			 				*/
/************************************************************/

void	TIMER0_VoidSetTIMER0REG(u8 Copy_u8TIMER0REG);



/************************************************************/
/* Description :  function to set OCR Register				*/
/*				  input	 :	u8								*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 Timer0 initialized 					*/
/************************************************************/
void	TIMER0_VoidSetOCRREG(u8 Copy_u8OCRREG);


/************************************************************/
/* Description :  function to set Timer0 Callback Function	*/
/*				  input	 :	Pointer to function (pf)		*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 enable OverFlow Interrupt 				*/
/************************************************************/

void	TIMER0_VoidSetOVCallback(pf	copy_FunctionAdress);



/************************************************************/
/* Description :  function to set CTC Callback Function		*/
/*				  input	 :	Pointer to function (pf)		*/
/*				  output :	void							*/
/************************************************************/
/* Pre_condition  :  this function must be used after  		*/
/*     				 enable CTC Interrupt 					*/
/************************************************************/

void	TIMER0_VoidSetCTCCallback(pf	copy_FunctionAdress);

#endif