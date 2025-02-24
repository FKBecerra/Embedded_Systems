/*
 * RCC.c
 *
 *  Created on: Feb 23, 2025
 *      Author: Francisco Becerra
 */

#include "RCC.h"
	// Page 165 reference manual. RCC registry
void SystemClock(void){
	/* Firstly, before starting to modify the bits of the
	 * registry we need to make sure they are clean
	 * and set to 0, to do this we need to clean the entire
	 * registry using pointers as shown in the following line of code
	 */
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLP);


}
