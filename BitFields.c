// Bitfields and structures are used in embeddd code heavily to bring abstraction.

// IDE EXAMPLE:

#ifndef MAIN_H_
#define MAIN_H_

#include<stdint.h>


typedef struct
{
	uint32_t gpioa_en		:1;
	uint32_t gpiob_en		:1;
	uint32_t gpioc_en		:1;
	uint32_t gpiod_en		:1;
	uint32_t gpioe_en		:1;
	uint32_t gpiof_en		:1;
	uint32_t gpiog_en		:1;
	uint32_t gpioh_en		:1;
	uint32_t gpioi_en		:1;
	uint32_t reserved1		:3;
	uint32_t crc_en			:1;
	uint32_t reserved2		:3;
	uint32_t reserved3		:2;
	uint32_t bkpsram_en		:1;
	uint32_t reserved4		:1;
	uint32_t ccmdat_en		:1;
	uint32_t dma1_en		:1;
	uint32_t dma2_en		:1;
	uint32_t reserved5		:2;
	uint32_t ethmac_en		:1;
	uint32_t ethmactx_en	:1;
	uint32_t ethmacrx_en	:1;
	uint32_t ethmacptp_en	:1;
	uint32_t otghs_en		:1;
	uint32_t otghsulpi_en	:1;
}RCC_AHB1ENR_t; // _t signifies that this is a typedef name (not mendatory, we added this.). RCC is one of the internal peripheral of the MCU and AHB1ENR is its associated register. 

typedef struct
{
   uint32_t pin_0		:1;
   uint32_t pin_1		:1;
   uint32_t pin_2		:1;
   uint32_t pin_3		:1;
   uint32_t pin_4		:1;
   uint32_t pin_5		:1;
   uint32_t pin_6		:1;
   uint32_t pin_7		:1;
   uint32_t pin_8		:1;
   uint32_t pin_9		:1;
   uint32_t pin_10		:1;
   uint32_t pin_11		:1;
   uint32_t pin_12		:1;
   uint32_t pin_13		:1;
   uint32_t pin_14		:1;
   uint32_t pin_15		:1;
   uint32_t reserved	:16;
}GPIOx_ODR_t;


typedef struct
{
   uint32_t pin_0		:2;
   uint32_t pin_1		:2;
   uint32_t pin_2		:2;
   uint32_t pin_3		:2;
   uint32_t pin_4		:2;
   uint32_t pin_5		:2;
   uint32_t pin_6		:2;
   uint32_t pin_7		:2;
   uint32_t pin_8		:2;
   uint32_t pin_9		:2;
   uint32_t pin_10		:2;
   uint32_t pin_11		:2;
   uint32_t pin_12		:2;
   uint32_t pin_13		:2;
   uint32_t pin_14		:2;
   uint32_t pin_15		:2;
}GPIOx_MODE_t;

#endif /* MAIN_H_ */

// Below code was written to toggle the LED of our board. Here we modify it to use generate a user interface for peripheral registers. Interface fo peripheral registers are defined in above header file.
// Commented out statements of the below code is performing the same thing by using bitwise operations (Which is harder)
#include<stdint.h>
#include "main.h"

int main(void)
{
	// uint32_t *pClkCtrlReg =   (uint32_t*)0x40023830;
	// uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
	// uint32_t *pPortDOutReg =  (uint32_t*)0x40020C14;
    
    // Create a pointer variable with the same type of the structure.
    RCC_AHB1ENR_t volatile *const pClkCtrlReg   = (RCC_AHB1ENR_t*) 0x40023830;   // Initialize the edresss with the register's address from datasheet (reference manual).
	GPIOx_MODE_t  volatile *const pPortDModeReg = (GPIOx_MODE_t*) 0x40020C00;  
	GPIOx_ODR_t   volatile *const pPortDOutReg  = (GPIOx_ODR_t*) 0x40020C14;

    // Setting which bit can be found in datasheet of the board. However, providers also should give an easier interface to set these bits for users.
    // In order to provide that easier interface, we need to create a similar structure that we created in Union.c, but in this case for peripheral register.
    // Basically we convert the bit structure given in dataheet as "RCC AHB1 peripheral clock enable register" (RCC-AHB1ENR) table.
	
    // 1. enable the clock for GPOID peripheral in the AHB1ENR (SET the 3rd bit position)
	// *pClkCtrlReg |= ( 1 << 3); // here we are trying to change the 3th bit position of this peripheral register (RCC AHB1ENR).
    pClkCtrlReg->gpiod_en = 1;



	//2. configure the mode of the IO pin as output
    pPortDModeReg->pin_12 = 1;
	//a) clear the 24th and 25th bit positions (CLEAR)
	// *pPortDModeReg &= ~( 3 << 24); 
	//b) make 24th bit position as 1 (SET)
	// *pPortDModeReg |= ( 1 << 24);  // Changing the 24th bit positon

	while(1)
	{
		//SET 12th bit of the output data register to make I/O pin-12 as HIGH
		// *pPortDOutReg |= ( 1 << 12);    // when we using this statement, we use bitwise operators to program the appropriate bit positions of the peripheral. But in the below statement we shift this work to compiler.
        pPortDOutReg->pin_12  = 1;   // dereferencing the pointer element to set the pin

		//introduce small human observable delay
		//This loop executes for 10K times
		for(uint32_t i=0 ; i < 300000 ; i++ );

		//Tun OFF the LED - //Reset 12th bit of the output data register to make I/O pin-12 as LOW
		// *pPortDOutReg &= ~( 1 << 12);
        pPortDOutReg->pin_12  = 0;

		for(uint32_t i=0 ; i < 300000 ; i++ );
	}

	for(;;);

}



