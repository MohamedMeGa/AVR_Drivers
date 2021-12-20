/************************************************************/
/* AUTHOR      : Mohamed MeGa	                   			*/
/* DISCRIPTION : USART DRIVER     			      			*/
/* DATE        : 29 OCT 2021                       			*/
/* VERSION     : V01                               			*/
/************************************************************/

#ifndef	USART_CONFIG_H
#define	USART_CONFIG_H

#define F_CPU				8000000

/***************************************************/
/**			MODE OF OPERATION can be:			   */
/**								ASYNCRONOUS   	   */
/**								SYNCRONOUS		   */
/***************************************************/
#define		MODE_OF_OPERATION		ASYNCRONOUS



/***************************************************/
/**			SPEED OPERATION can be :			   */
/**								NORMAL_SPEED   	   */
/**								DOUBLE_SPEED	   */
/***************************************************/
#define		SPEED_OPERATION			NORMAL_SPEED



/***************************************************/
/**			Enter your BaudRate					   */
/***************************************************/
#define		BaudRate				9600


/***************************************************/
/**			DATE SIZE Can be :			   		   */
/**							5_BIT   		 	   */
/**							6_BIT	   			   */
/**							7_BIT	   			   */
/**							8_BIT				   */
/**							9_BIT				   */
/***************************************************/
#define		DATE_SIZE				8_BIT


/***************************************************/
/**			STOP BIT Can Be :					   */
/**							ONE_BIT 	   	   	   */
/**							TWO_BIT		   		   */
/***************************************************/
#define		STOP_BIT_SELECT			ONE_BIT



/***************************************************/
/**			PARITY MODE Can be :				   */
/**							DISABLE   	 	   	   */
/**							EVEN	  	 		   */
/**							ODD			   		   */
/***************************************************/
#define		PARITY_MODE				DISABLE




/***************************************************/
/**			CLOCK POLARITY Can be :				   */
/**								RISING  		   */
/**								FALLING			   */
/***************************************************/
#define		CLOCK_POLARITY			RISING

#endif