/************************************************************/
/** 		AUTHOR      : Mohamed MeGa	                   	*/
/**		 	DISCRIPTION : OS DRIVER      				  	*/
/** 		DATE        : 23 DEC 2021                       */
/** 		VERSION     : V01                               */
/************************************************************/

#ifndef	OS_PRIVATE_H
#define	OS_PRIVATE_H


typedef	struct
{
	u16 priodicity;
	void(*FPTR)(void);
	u8 FirstDelay;
	u8 State;
}Task;


#define	NULL		(void *)0

static	Task OS_Task[NUMBER_OF_TASKS]	=	{NULL};


#define	READY		1
#define	SUSPEND		2
#define	DORMINATE	3
#define	RUNNING		4
#define	WAITING		5
#endif