/**************************************************/
/*   AUTHOR      : Mohamed	MeGa           		  */
/*   Description : IIC DRIVER      			 	  */
/*   DATE        : 5 NOV 2021 					  */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	IIC_PRIV_H
#define	IIC_PRIV_H

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
/**** Description :  MEMEROY MAPPING IIC register **/
/***************************************************/
#define     TWBR_REG       *((volatile u8 *)0x20)
#define     TWCR_REG       *((volatile u8 *)0x56)
#define     TWSR_REG       *((volatile u8 *)0x21)
#define     TWDR_REG       *((volatile u8 *)0x23)
#define     TWAR_REG       *((volatile u8 *)0x22)

	
#endif