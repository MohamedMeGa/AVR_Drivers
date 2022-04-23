/************************************************************/
/* AUTHOR      : Mohamed MeGa	                   			*/
/* DISCRIPTION : IIC DRIVER     			      			*/
/* DATE        : 22 APR 2022                       			*/
/* VERSION     : V1.1                               		*/
/************************************************************/

#ifndef	IIC_CONFIG_H
#define	IIC_CONFIG_H

#ifndef
	#define F_CPU				8000000
#endif


/***************************************************/
/**			Master Slave Mode Can be :			   */
/**							ENABLE		   		   */
/**							DISABLE			  	   */
/***************************************************/
#define MASTER_SLAVE_MODE		MASTER



/***************************************************/
/**			TWI FREQUENCY Can be :			   	   */
/**							PRES_1_DIV   		   */
/**							PRES_4_DIV	   		   */
/**							PRES_16_DIV	 		   */
/**							PRES_64_DIV			   */
/***************************************************/
#define		TWI_FREQUENCY		PRES_1_DIV



/***************************************************/
/**			TWI Acknowledge Can be :			   */
/**							ENABLE		   		   */
/**							DISABLE			  	   */
/***************************************************/
#define		TWI_ACK_MODE		ENABLE




/***************************************************/
/**			TWI Broadcast Mode Can be :			   */
/**							ENABLE		   		   */
/**							DISABLE			  	   */
/***************************************************/
#define		TWI_BROADCAST		ENABLE



#endif