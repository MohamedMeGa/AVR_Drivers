#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "OS_interface.h"

void LED1(void);
void LED2(void);
void LED3(void);


void main(void)
{
	
	MRCC_voidInitSysClock();

	MRCC_voidEnableClock(2 , 0);

	MRCC_voidEnableClock(2 , 2);

	MGPIO_VidSetPinDirection( GPIOA , PIN0 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_VidSetPinDirection( GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_VidSetPinDirection( GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP );


	SOS_voidCreateTask(0,1000,LED1, 0);
	SOS_voidCreateTask(1,2000,LED2, 1);
	SOS_voidCreateTask(2,3000,LED3, 2);

	SOS_voidStart();


	while(1)
	{

	}
}

void LED1(void)
{
	static u8 Local_Pin=0;
	TOGGLE_BIT(Local_Pin,0);
	MGPIO_VidSetPinValue( GPIOA , PIN0 , Local_Pin );
}

void LED2(void)
{
	static u8 Local_Pin=0;
	TOGGLE_BIT(Local_Pin,0);
	MGPIO_VidSetPinValue( GPIOA , PIN1 , Local_Pin );
}

void LED3(void)
{
	static u8 Local_Pin=0;
	TOGGLE_BIT(Local_Pin,0);
	MGPIO_VidSetPinValue( GPIOA , PIN2 , Local_Pin );
}
