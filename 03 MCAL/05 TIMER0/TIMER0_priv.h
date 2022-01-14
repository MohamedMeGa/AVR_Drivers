/**************************************************/
/*   AUTHOR      : Mohamed	MeGa           		  */
/*   Description : TIMER 0 DRIVER      			  */
/*   DATE        : 21 OCT 2021 					  */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	TIMER0_PRIV_H
#define	TIMER0_PRIV_H




/***************************************************/
/* Description :  MEMEROY MAPPING Timer0 register  */
/***************************************************/

	#define	TCCR0	*((volatile	u8	*)	0x53)
	#define	TCNT0	*((volatile	u8	*)	0x52)
	#define	OCR0	*((volatile	u8	*)	0x5C)
	#define	TIMSK	*((volatile	u8	*)	0x59)
	#define	TIFR	*((volatile	u8	*)	0x58)
	



	
#endif