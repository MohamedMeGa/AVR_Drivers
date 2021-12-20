/************************************************************/
/* AUTHOR      : Mohamed MeGa	                   			*/
/* DISCRIPTION : IIC DRIVER     			      			*/
/* DATE        : 5 NOV 2021                       			*/
/* VERSION     : V01                               			*/
/************************************************************/

#ifndef	IIC_CONFIG_H
#define	IIC_CONFIG_H

#define F_CPU				8000000

/***************************************************/
/**			MODE OF INTERRUPT can be:			   */
/**								ENABLE		   	   */
/**								DISABLE			   */
/***************************************************/
#define		MODE_OF_INTERRUPT		DISABLE



/***************************************************/
/**			MODE OF MASTER SLAVE can be :		   */
/**								MASTER   	 	   */
/**								SLAVE			   */
/***************************************************/
#define		MODE_OF_MASTER_SLAVE	MASTER





/***************************************************/
/**			SPI FREQUENCY Can be :			   	   */
/**							F_CPU_BY_2   		   */
/**							F_CPU_BY_4	   		   */
/**							F_CPU_BY_8	 		   */
/**							F_CPU_BY_16			   */
/**							F_CPU_BY_64			   */
/**							F_CPU_BY_64			   */
/**							F_CPU_BY_128		   */
/***************************************************/
#define		SPI_FREQUENCY		F_CPU_BY_2


/***************************************************/
/**			DATE ORDER Can Be :					   */
/**							LSB_FIRST 	   	   	   */
/**							MSB_FIRST	   		   */
/***************************************************/
#define		DATE_ORDER			LSB_FIRST



/***************************************************/
/**			CLOCK PHASE Can be :				   */
/**							ZERO	   	 	   	   */
/**							ONE	  	 			   */
/***************************************************/
#define		CLOCK_PHASE			ZERO




/***************************************************/
/**			CLOCK POLARITY Can be :				   */
/**								LOW_IDLE  		   */
/**								HIGH_IDLE		   */
/***************************************************/
#define		CLOCK_POLARITY			LOW_IDLE

#endif