/**************************************************/
/*   AUTHOR      : Mohamed	MeGa           		  */
/*   Description : IIC DRIVER      			 	  */
/*   DATE        : 5 NOV 2021 					  */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	IIC_PRIV_H
#define	IIC_PRIV_H



/***************************************************/
/**			Master Slave selections Options		   */
/***************************************************/
#define		MASTER				2
#define		SLAVE				3


/***************************************************/
/**			Prescaller selections Options		   */
/***************************************************/
#define		PRES_1_DIV			1
#define		PRES_4_DIV			2
#define		PRES_16_DIV			3
#define		PRES_64_DIV			4




/***************************************************/
/**			MODE OF Acknowledge Selections Options */
/***************************************************/
#define		DISABLE				4					
#define		ENABLE				7






/***************************************************/
/**** Description :  MEMEROY MAPPING IIC register **/
/***************************************************/
#define     TWBR_REG       *((volatile u8 *)0x20)
#define     TWCR_REG       *((volatile u8 *)0x56)
#define     TWSR_REG       *((volatile u8 *)0x21)
#define     TWDR_REG       *((volatile u8 *)0x23)
#define     TWAR_REG       *((volatile u8 *)0x22)

	
#endif