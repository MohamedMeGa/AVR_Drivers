/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: mabda
 */

#include "STD_TYPES.h";
#include "Bit_Math.h";
#include "DIO_int.h";
#include "util/delay.h"

int main(void)
{
	DIO_VoidInitialization();
	while(1){
		DIO_voidSetPinValue(DIO_PIN0, DIO_HIGH);
		_delay_ms(5);
		DIO_voidSetPinValue(DIO_PIN0, DIO_LOW);
		_delay_ms(15);
	}
	return 0;
}
