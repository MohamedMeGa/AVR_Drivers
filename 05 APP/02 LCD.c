/*
 * main.c
 *
 *  Created on: Jun 18, 2019
 *      Author: mabda
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include <util/delay.h>
#include	"SEV_int.h"

int main(void){
	DIO_VoidInitialization();


	LCD_VoidLCDInit();
//	LCD_VoidWriteCharacter('M');
	LCD_VoidWriteString("MEGA");
	 while(1){
		
	}


	return 0;
}


