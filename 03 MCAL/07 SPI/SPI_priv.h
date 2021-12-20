/**************************************************/
/*   AUTHOR      : Mohamed	MeGa           		  */
/*   Description : SPI DRIVER      			 	  */
/*   DATE        : 2 NOV 2021 					  */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	SPI_PRIV_H
#define	SPI_PRIV_H

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
/**			SPI FREQUENCY selections Options	   */
/***************************************************/
#define		5_BIT				0
#define		6_BIT				1
#define		7_BIT				2
#define		8_BIT				3
#define		9_BIT				4


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
/* Description :  MEMEROY MAPPING USART register  */
/***************************************************/

	#define	SPCR	*((volatile	u8	*)	0x2D)
	#define	SPSR	*((volatile	u8	*)	0x2E)
	#define	SPDR	*((volatile	u8	*)	0x2F)

	



	
#endif