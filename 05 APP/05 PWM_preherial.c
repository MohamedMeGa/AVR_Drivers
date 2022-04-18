/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: mabda
 */

#include "STD_TYPES.h";
#include "Bit_Math.h";
#include "DIO_int.h";
#include <avr/io.h>
#define F_CPU 12000000UL

int main(void)
{
	/*TCCR0 	= 0b01101101;
	OCR0 	= 145;		//Servo Motor Values 0 -> 20*/
	DIO_VoidInitialization();
	TIMER0_VoidInitialization();	//1024 prescaller and Fast PWM Mode and clear OC
	TIMER0_VoidSetOCRREG(15);
	while(1){

	}
	return 0;
}
