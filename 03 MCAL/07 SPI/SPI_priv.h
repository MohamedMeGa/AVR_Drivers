/**************************************************/
/*   AUTHOR      : Mohamed	MeGa           		  */
/*   Description : SPI DRIVER      			 	  */
/*   DATE        : 2 NOV 2021 					  */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	SPI_PRIV_H
#define	SPI_PRIV_H



/***************************************************/
/* Description :  MEMEROY MAPPING SPI register     */
/***************************************************/

	#define	SPCR	*((volatile	u8	*)	0x2D)
	#define	SPSR	*((volatile	u8	*)	0x2E)
	#define	SPDR	*((volatile	u8	*)	0x2F)

	



	
#endif