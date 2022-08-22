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


// GETTING INPUT BY USING A KEYPAD (SECTION 28)

// First four pins (8 total) of the keypad are called as row pins, R1, R2, R3 and R4.
// Next 4 pins are called column pins C1, C2, C3 and C4.
// Since there are 16 buttons on keypad these are addressed as:
//     C1 C2 C3 C4
// R1  1  2  3  A 
// R2  4  5  6  B
// R3  7  8  9  C
// R4  *  0  #  D

// So we need, 8 I/O pins of MCU to use this keypad.
// 4 pins of the microcontroller, which are connected to column pins, must be set as input in the software of MCU
// However, the other 4 pins of the microcontroller, which are connected to row pins, must be set as output in the software of MCU
// We also need pull-up resistors for the columns (inputs). We will use internal pull-up resistors which are available inside the microcontroler!
// There are also internal pull-down resistors for output pins.

// WHY WE NEED PULL-UP AND PULL-DOWN RESISTORS:
// MCU-Outputpin ____R1PinofKeypad_______/____C1PinofKeypad_____ MCU-OInputpin. => These reperesents there is a key which becomes close circuit when a button is pressed between R and C of the keypad.
// When butoon is not pressed, circuit become open circuit. However, because of the noise of the output pins voltage, output signal (voltage) can flactuate. So when you read a flactuatin pin, it sometimes shows high, sometimes low.
// This is why we use pull up / pull down resistors, to decrease the fluctuation.
// There should be added a pull up resistor between +VCC and the input pin. ???
// There should be added a pull down resistor between ground and the output pin.  ???
// When key not pressed input(P8) becomes high, when key is pressed input(P8) becomes low (grounded).
// R1 (or output of MCU (P0)) must be grounded. 

// HOW TO ENABLE PULL-UP NAD PULL_DOWN RESISTORS:
	// In the GPIO register section of reference manual (Section 8), there is a part which is named GPIO port pull-up/pull-down resister (8.4.4)
	// This register is used to enable internal pull up/ pull-down resistors.
		// 00: No pull-up, pull-down
		// 01: Pull-up
		// 10: Pull-down
		// 11: Reserved

// STEP BY STEP IMPLEMENTATION:
	// First we have to keep all row GPIOSs in output mode and keep all column GPIOs in input mode.
	// Make all outputs (rows) in Hihg state.
	// Start a infinite loop here.
	// Make R1 low. (R2, R3 and R4 are still high)
	// Read C1, check whether C1 is low. If yes put 200ms delay and we understand Key is 1. Delay is for key debouncing. Software must be in a busy loop during debouncing.
	// If C1 is not 0, continue and check other columns one by one and apply the same procedure that we applied to C1.
	// Make R2 low. (R1, R3 and R4 are still high) and perform above process again to understand which button is pressed.
	// Repeat for R3.
	// Repeat for R4.
	// Using bitwise operations is suggested for this code, structures and bit fields will be used later.
	// The code that we used to see printf functions on our IDE must be added to this project.

	// Check video 176 04:48 to how to implement this program step by step. Can be a good practice.

// Implementation of Keypad exercise Video 177: 
#include<stdint.h>
#include<stdio.h>

void delay(void)
{
	for(uint32_t i =0 ; i < 300000 ; i++);    // delay function to stop code during button debouncing.
										      // After download the code to MCU open window ==> show view ==> SWV ==> SWV ITM Data console
											  // Then press red circle and click on 0th bit to start tracing.
// HOW TO CALCULATE DELAY:
// Put a break point in front of for loop and start debugging.
// Open machine code (assembly level implementation) tab (starting with Dis... on the right hand side) to debug one by one there.
// Press i==> button to perform Instruction Stepping mode, going step by step on assembly code. 
// We can see there are 7 instructions in assemble code for this for loop. means it executes 7 instructions for each iteration.
// Processor is running with 16Mhz of internal RC oscillator.
// Let;s say 1 instruction takes 1 cycle, so 1 ins = 0.0625 micro seconds
// 7 instructions = 0.5micro seconds. (0.4375 actually)
// Means 0.5 micro seconds is for 1 iteration of for loop.
// 2000 iterations will be 1000 microseconds (1ms(milisecond)).
// For 150ms  2000*150 = 300000 iterations.
// That is why this for loop cause APPROXIMATELY 150ms of delay.


}

int main(void)
{
	//peripheral register addresses
	uint32_t volatile *const pGPIODModeReg  =  (uint32_t*)(0x40020C00);
	uint32_t volatile *const pInPutDataReg  =  (uint32_t*)(0x40020C00+0x10);
	uint32_t volatile *const pOutPutDataReg =  (uint32_t*)(0x40020C00+0x14);
	uint32_t volatile *const pClockCtrlReg  =  (uint32_t*)(0x40023800+0x30);
	uint32_t volatile *const pPullupDownReg =  (uint32_t*)(0x40020C00 + 0x0C);

     //1.Enable the peripheral clock of GPIOD peripheral
	*pClockCtrlReg |= ( 1 << 3);


    // 2.configure PD0,PD1,PD2,PD3 as output (rows)
	*pGPIODModeReg &= ~(0xFF); // we clear these fields first.
	*pGPIODModeReg |= 0x55;   //set


	// 3. configure PD8 , PD9, PD10, PD11 as input (columns)
    *pGPIODModeReg &= ~(0xFF << 16);    // we clear 8 consecutive bits starting from 16th bit.

	// 4.Enable internal pull-up resistors for PD8 PD9 PD10 PD11
    *pPullupDownReg &= ~(0xFF << 16);    // we clear 8 consecutive bits starting from 16th bit.
    *pPullupDownReg |=  (0x55 << 16);    // Set the bit accordingly.

while(1)
{
    //make all rows HIGH
    *pOutPutDataReg |= 0x0f;

    //make R1 LOW(PD0)
    *pOutPutDataReg &= ~( 1 << 0);

    //scan the columns
    //check C1(PD8) low or high
    if(!(*pInPutDataReg & ( 1 << 8))){
    	//key is pressed
    	delay();
    	printf("1\n");
    }

    //check C2(PD9) low or high
    if(!(*pInPutDataReg & ( 1 << 9))){
    	//key is pressed
    	delay();
    	printf("2\n");
    }

    //check C3(PD10) low or high
    if(!(*pInPutDataReg & ( 1 << 10))){
    	//key is pressed
    	delay();
    	printf("3\n");
    }

    //check C4(PD11) low or high
    if(!(*pInPutDataReg & ( 1 << 11))){
    	//key is pressed
    	delay();
    	printf("A\n");
    }


    //make all rows HIGH
     *pOutPutDataReg |= 0x0f;
    //make R2 LOW(PD1)
    *pOutPutDataReg &= ~( 1 << 1);

    //scan the columns
    //check C1(PD8) low or high
    if(!(*pInPutDataReg & ( 1 << 8))){
    	//key is pressed
    	delay();
    	printf("4\n");
    }

    //check C2(PD9) low or high
    if(!(*pInPutDataReg & ( 1 << 9))){
    	//key is pressed
    	delay();
    	printf("5\n");
    }

    //check C3(PD10) low or high
    if(!(*pInPutDataReg & ( 1 << 10))){
    	//key is pressed
    	delay();
    	printf("6\n");
    }

    //check C4(PD11) low or high
    if(!(*pInPutDataReg & ( 1 << 11))){
    	//key is pressed
    	delay();
    	printf("B\n");
    }

    //make all rows HIGH
     *pOutPutDataReg |= 0x0f;
    //make R3 LOW(PD2)
    *pOutPutDataReg &= ~( 1 << 2);

    //scan the columns
    //check C1(PD8) low or high
    if(!(*pInPutDataReg & ( 1 << 8))){
    	//key is pressed
    	delay();
    	printf("7\n");
    }

    //check C2(PD9) low or high
    if(!(*pInPutDataReg & ( 1 << 9))){
    	//key is pressed
    	delay();
    	printf("8\n");
    }

    //check C3(PD10) low or high
    if(!(*pInPutDataReg & ( 1 << 10))){
    	//key is pressed
    	delay();
    	printf("9\n");
    }

    //check C4(PD11) low or high
    if(!(*pInPutDataReg & ( 1 << 11))){
    	//key is pressed
    	delay();
    	printf("C\n");
    }

    //make all rows HIGH
     *pOutPutDataReg |= 0x0f;
    //make R4 LOW(PD2)
    *pOutPutDataReg &= ~( 1 << 3);

    //scan the columns
    //check C1(PD8) low or high
    if(!(*pInPutDataReg & ( 1 << 8))){
    	//key is pressed
    	delay();
    	printf("*\n");
    }

    //check C2(PD9) low or high
    if(!(*pInPutDataReg & ( 1 << 9))){
    	//key is pressed
    	delay();
    	printf("0\n");
    }

    //check C3(PD10) low or high
    if(!(*pInPutDataReg & ( 1 << 10))){
    	//key is pressed
    	delay();
    	printf("#\n");
    }

    //check C4(PD11) low or high
    if(!(*pInPutDataReg & ( 1 << 11))){
    	//key is pressed
    	delay();
    	printf("D\n");
    }

}//while end

}
