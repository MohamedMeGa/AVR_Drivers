/************************************************************/
/** 		AUTHOR      : Mohamed MeGa	                   	*/
/**		 	DISCRIPTION : OS DRIVER      				  	*/
/** 		DATE        : 23 DEC 2021                       */
/** 		VERSION     : V01                               */
/************************************************************/



#ifndef	OS_INT_H
#define	OS_INT_H



/************************************************************/
/** 		Description :  PROTOTYPE DECLARTION 		   	*/
/************************************************************/


/************************************************************/
/* Description :  function to Create Task				 	*/
/*				  input	 :	u8 copy_u8ID,					*/
/*							u16 copy_u16Priodicity,			*/
/*							void (* PTR)(void)				*/
/*				  output :	void							*/
/************************************************************/
void OS_VoidCreateTask(u8 copy_u8ID, u16 copy_u16Priodicity, void (* PTR)(void));

void OS_VoidStart(void);

void OS_VoidScheduler(void);

#endif