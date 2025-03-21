/*
 * RCC.h
 *
 *  Created on: Feb 23, 2025
 *      Author: Francisco Becerra
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "main.h"
	/* Parameter settings to set the system clock speed to 180MHz.
	 * We set the value of PLL_P to 2 for which it is assigned
	 * the value of "0" due to the datasheet. The PLL_N is set
	 * to 180 and the PLL_M to 4. These values ​​were obtained
	 * using the STM32 HAL calculation tool.
	 */
#define PLL_P 0 // 0 == 2
#define PLL_N 180
#define PLL_M 4

void SystemClock(void);

#endif /* INC_RCC_H_ */
