/************************************************************/
/* AUTHOR      : Mohamed MeGa	                   			*/
/* DISCRIPTION : TIMER 0 DRIVER     			      		*/
/* DATE        : 21 OCT 2021                       			*/
/* VERSION     : V01                               			*/
/************************************************************/

#ifndef	TIMER0_CONFIG_H
#define	TIMER0_CONFIG_H

/***************************************************/
/**			TIMER0 Mode :				   		   */
/**							TIMER0_NORMAL    	   */
/**							TIMER0_PWM	   		   */
/**							TIMER0_CTC	   		   */
/**							TIMER0_FASTPWM		   */
/***************************************************/
#define		TIMER0_MODE				TIMER0_NORMAL



/***************************************************/
/**			Compare Output Mode :				   */
/**								TIMER0_NO_ACTION   */
/**								TIMER0_TOGGLE	   */
/**								TIMER0_CLEAR	   */
/**								TIMER0_SET		   */
/***************************************************/
#define		TIMER0_COM_EVENT		TIMER0_NO_ACTION


/***************************************************/
/**			Prescaller :						   */
/**							NO_CLOCK    	   	   */
/**							CLK_NO_PRES	   		   */
/**							PRES_8_DIV	   		   */
/**							PRES_64_DIV		   	   */
/**							PRES_256_DIV    	   */
/**							PRES_1024_DIV	   	   */
/**							External_Falling	   */
/**							External_Rising		   */
/***************************************************/
#define		TIMER0_PRESCALLER		NO_CLOCK

#endif