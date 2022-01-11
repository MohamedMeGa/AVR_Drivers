/************************************************************/
/** 		AUTHOR      : Mohamed MeGa	                   	*/
/**		 	DISCRIPTION : OS DRIVER      				  	*/
/** 		DATE        : 23 DEC 2021                       */
/** 		VERSION     : V01                               */
/************************************************************/

/************************************************************/
/*			library Directives						  		*/
/************************************************************/
#include	"STD_TYPES.h"
#include	"Bit_Math.h"

#include	"STK_interface.h"

/************************************************************/
/**			OS Directives						 			*/
/************************************************************/
#include	"OS_interface.h"
#include	"OS_config.h"
#include	"OS_private.h"


volatile	u8	TickCount = 0;


/************************************************************/
/**			Description :  PROTOTYPE DECLARTION				*/
/************************************************************/

/************************************************************/
/* Description :  function to Create Task				 	*/
/*				  input	 :	u8 copy_u8ID,					*/
/*							u16 copy_u16Priodicity,			*/
/*							void (* PTR)(void)				*/
/*				  output :	void							*/
/************************************************************/


void OS_VoidCreateTask(u8 copy_u8ID, u16 copy_u16Priodicity, void (* PTR)(void))
{
	OS_Task[copy_u8ID].priodicity	=	copy_u16Priodicity;
	
	OS_Task[copy_u8ID].FTPR			=	PTR;
}



/************************************************************/
/* Description :  function to Create Task				 	*/
/*				  input	 :	u8 copy_u8ID,					*/
/*							u16 copy_u16Priodicity,			*/
/*							void (* PTR)(void)				*/
/*				  output :	void							*/
/************************************************************/
void OS_VoidStartOS(void)
{
	STK_voidInit();
	STK_voidSetIntervalperiodic(1000, OS_VoidScheduler());
}






void OS_VoidScheduler(void)
{
	u8 Local_u8TaskCounter = 0;
	for(Local_u8TaskCounter = 0; Local_u8TaskCounter < NUMBER_OF_TASKS, Local_u8TaskCounter++)
	{
		//if(TickCount % OS_Task[i].priodicity == 0)
		if(OS_Task[Local_u8TaskCounter].FPTR != NULL && OS_Task[Local_u8TaskCounter].State == READY)
		{
			if(OS_Task[Local_u8TaskCounter].FirstDelay == 0)
			{
				OS_Task[Local_u8TaskCounter].FirstDelay = OS_Task[Local_u8TaskCounter].priodicity - 1;
				OS_Task[Local_u8TaskCounter].FPTR();
			}
			else
			{
				OS_Task[Local_u8TaskCounter].FirstDelay--;
			}
		}
		else
		{
			
		}
		
	}
	TickCount++;
}