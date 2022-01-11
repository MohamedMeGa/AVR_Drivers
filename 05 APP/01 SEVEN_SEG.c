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


	while(1){
		 
		for(int i=0; i<=9; i++){
			
			SEV_VoidSET7SegmentValue(SEV_SEG_RIGHT, i);
			
			_delay_ms(500);
			if(i==9)
				i=0;
		}
	}


	return 0;
}


