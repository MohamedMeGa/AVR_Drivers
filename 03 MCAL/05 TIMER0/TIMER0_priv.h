/**************************************************/
/*   AUTHOR      : Mohamed	MeGa           		  */
/*   Description : TIMER 0 DRIVER      			  */
/*   DATE        : 21 OCT 2021 					  */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	TIMER0_PRIV_H
#define	TIMER0_PRIV_H

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
#define		CLK_NO_PRES			1
#define		CLK_NO_PRES			2
#define		PRES_64_DIV			3
#define		PRES_256_DIV		4
#define		PRES_1024_DIV		5
#define		External_Falling	6
#define		External_Rising		7





/***************************************************/
/* Description :  MEMEROY MAPPING Timer0 register  */
/***************************************************/

	#define	TCCR0	*((volatile	u8	*)	0x53)
	#define	TCNT0	*((volatile	u8	*)	0x52)
	#define	OCR0	*((volatile	u8	*)	0x5C)
	#define	TIMSK	*((volatile	u8	*)	0x59)
	#define	TIFR	*((volatile	u8	*)	0x58)
	



	
#endif