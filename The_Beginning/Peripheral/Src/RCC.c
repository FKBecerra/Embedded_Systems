/*
 * RCC.c
 *
 *  Created on: Feb 23, 2025
 *      Author: Francisco Becerra
 */

#include "RCC.h"
	// Page 165 reference manual rev 21. RCC register
void SystemClock(void){
	/* Firstly, before starting to modify the bits of the
	 * registry we need to make sure they are clean
	 * and set to 0, to do this we need to clean the entire
	 * registry using pointers as shown in the following line of code
	 * RCC_PLLCFGR_PLLM = "0X3F<<0" The hex value of 0x3F equals to "0011 1111"
	 * in binary, and the sentence says it starts on the position "0" as shown on
	 * the datasheet. Using these macros we send chains of "1" to the register
	 * and then using the "~" operator we transform those "1" to "0" and that way
	 * we clean the entire register in those bit locations. (PLL_M, PLL_N, PLL_P)
	 */
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLP);
	/* Once all bits are set to 0 we need to send "1" to those bits in order to
	* configure the system clock. */
	RCC->PLLCFGR |= (PLL_N<<6) | (PLL_P<<16) | (PLL_M<<0);
	/* Now we need to turn on the clock source, in this case we'll use the
	 * external source, to do so we need to access the CR register and set to "1"
	 * as shown in the following code line: */
	RCC->CR |= RCC_CR_HSEON;
	/* I'm going to use the while control loop to check if the external clock
	 * source is ready to work and compare it with the CR register, if that's true
	 * the loop will end and the process will flow to the next instruction. */
	while((RCC->CR & RCC_CR_HSERDY) == 0 );

	// Turn on the PLL
	RCC->CR |= RCC_CR_PLLON;
	// Select the PLL clock source to work as the system clock
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC;
	// Check if the PLL was turned on correctly
	while((RCC->CR & RCC_CR_PLLRDY) == 0 );

	// Page 99 reference manual rev 21. FLASH-> ACR register (Access Control Register)
	/* Now to read the information from the flash memory we need to set
	 * the number of wait states or latency which must be set according to
	 * the operating voltage of the development board (3.6V) and the frequency
	 * of the system clock which is the maximum possible (180MHz).
	 * For this configuration, according to the datasheet we need to set a
	 * total of 5 wait states, as shown in the following code line: */

	// Clean FLASH register
	FLASH->ACR &= ~(FLASH_ACR_LATENCY);
	// Set latency to 5 wait states
	FLASH->ACR |= (FLASH_ACR_LATENCY_5WS);
	// Prefetch enable
	FLASH->ACR |= FLASH_ACR_PRFTEN;

	// Page 167 reference manual rev 21. RCC-> CFGR register
	// Cleaning the bits of the register CFGR register
	RCC->CFGR &= ~(RCC_CFGR_SW);
	// Page #169 Sending "2" indicates the PLL as the clock
	// source for the system clock
	RCC->CFGR |= (RCC_CFGR_SW_PLL);
	// Check if the PLL was selected correctly as clock source for the system
	while((RCC->CFGR & RCC_CFGR_SWS_PLL) == 0 );

	// Cleaning all bits of AHB Prescaler (HPRE) section of RCC-> CGFR register
	RCC->CFGR &= ~(RCC_CFGR_HPRE);

	/* According to the HAL Calculator results in order to set the system clock
	 * we need to divide the AHB clock by 4 to get the frequency of 180MHz,
	 * to do so we need to send "101" binary value to PPRE1 bits in CGFR register */

	// APB 1 - Cleaning bits of PPRE1
	RCC->CFGR &= ~(RCC_CFGR_PPRE1);
	// Sending value of "101" to divide APB1 (Low Speed Prescaler) by 4
	RCC->CFGR |= (RCC_CFGR_PPRE1_DIV4);

	// APB2 - Cleaning bits of PPRE2
	RCC->CFGR &= (RCC_CFGR_PPRE2);
	// Sending value of "100" to divide APB2 (High Speed Prescaler) by 2
	RCC->CFGR |= (RCC_CFGR_PPRE2_DIV2);



}
