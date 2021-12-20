/************************************************************/
/*   		AUTHOR      : MOHAMED	MEGA	              	*/
/*   		Description : DIO DRIVER                     	*/
/*   		DATE        : 29 SET 2021                    	*/
/*   		VERSION     : V02                            	*/
/************************************************************/

#ifndef	DIO_INT_H
#define	DIO_INT_H

/************************************************************/
/**			LOW & HIGH 	DEFINITION							*/
/************************************************************/
#define	DIO_u8_HIGH				1
#define	DIO_u8_LOW				0



/************************************************************/
/* 			Description :  pins of port A 			   	   */
/************************************************************/
#define	DIO_U8_PIN_0		0
#define	DIO_U8_PIN_1		1
#define	DIO_U8_PIN_2		2
#define	DIO_U8_PIN_3		3
#define	DIO_U8_PIN_4		4
#define	DIO_U8_PIN_5		5
#define	DIO_U8_PIN_6		6
#define	DIO_U8_PIN_7		7



/************************************************************/
/* 			Description :  pins of port B 			   	   */
/************************************************************/
#define	DIO_U8_PIN_8		8
#define	DIO_U8_PIN_9		9
#define	DIO_U8_PIN_10		10
#define	DIO_U8_PIN_11		11
#define	DIO_U8_PIN_12		12
#define	DIO_U8_PIN_13		13
#define	DIO_U8_PIN_14		14
#define	DIO_U8_PIN_15		15



/************************************************************/
/* 			Description :  pins of port C 			   	   */
/************************************************************/
#define	DIO_U8_PIN_16		16
#define	DIO_U8_PIN_17		17
#define	DIO_U8_PIN_18		18
#define	DIO_U8_PIN_19		19
#define	DIO_U8_PIN_20		20
#define	DIO_U8_PIN_21		21
#define	DIO_U8_PIN_22		22
#define	DIO_U8_PIN_23		23



/************************************************************/
/* 			Description :  pins of port D 			   	    */
/************************************************************/
#define	DIO_U8_PIN_24		24
#define	DIO_U8_PIN_25		25
#define	DIO_U8_PIN_26		26
#define	DIO_U8_PIN_27		27
#define	DIO_U8_PIN_28		28
#define	DIO_U8_PIN_29		29
#define	DIO_U8_PIN_30		30
#define	DIO_U8_PIN_31		31


/************************************************************/
/* 			Description :  PROTOTYPE DECLARTION 		   	*/
/************************************************************/


/************************************************************/
/* Description :  function for initialization and define	*/
/*				   the direction of ports					*/
/************************************************************/

void	DIO_VoidInitialization(void);



/************************************************************/
/* Description :  function to set the value of any 			*/
/*				  pin to LOW or HIGH						*/
/************************************************************/
void	DIO_voidSetPinValue(u8	copy_u8PinNum, u8	copy_u8PinValue);



/************************************************************/
/* Description :  function to Get the value of any 			*/
/*				  pin 										*/
/************************************************************/
u8	DIO_u8GetPinValue(u8	copy_u8PinNum);



/************************************************************/
/* Description :  function to set the direction of any 		*/
/*				  pin to OUTPUT or INPUT					*/
/************************************************************/
void	DIO_voidSetPinDirection(u8	copy_u8PinNum, u8	copy_u8PinDir);



/************************************************************/
/* Description :  function to Toggle the value of any 		*/
/*				  pin to LOW or HIGH						*/
/************************************************************/
void	DIO_voidTogglePin(u8	copy_u8PinNum);



#endif