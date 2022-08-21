// Optimization is a series of actions taken by the compiler on your program's code generation process to reduce
    // Number of instructions (code space optimization)
    // Memory access time (time space optimiziation)
    // Power consumption
// By default, the compiler does not invoke any optimization on your program. You can enable the optimization using compiler flags. 
// Compiler flags to enable optimization
    // -O0 (This is used by default) Means optimization limit is zero.
        // No optimization
        // Not recommended for productions if you have limited code and ram space
        // Has fastest compilation time
        // This is debugging friendly and used during development. This is debugging friendly because, when you are trying to debug your code there will be one to one map between the instructions generated and the source code what you have written.
        // A code which works with -O0 optimization may not work with -O0+ (O1, O2 and O3) optimization levels. Code needs to be verified again.
    // -O1
        // If you use O1 optimization level, then it is kind of introducing moderate optimization to decrease memory access time and code space.
    // -O2
        // Full optimization
        // Slow compilation time
        // Not debugging friendly. There will not be one to one mapping between the instructions generated and the source code what you have written.
    // -O3
        // Full optimization of -O2 + some more aggresive optimization steps will be taken by compiler.
        // Slowest compilation time.
        // May cause bugs in the program
        // Not debugging friendly.

// HOW TO SET OPTIMIZATION LEVEL
    // Right click on the project ==> properties ==> Expand C/C++ Build ==> Settings ==> MCU GCC compiler ==> Optimization ==> Select Optimization level apply and close.
    // Always try if built applications is working or not with the new optimization level.

// VOLATILE
    // It telss the compiler that the value of the variable may change at any time with or without the programmer's constent. So, the compiler turns off optimizing the read-write operations on variables which are declared using volatile keyword.
    uint8_t data1;
    uint8_t data2;

    data1 = 50;

    data2 = data1;
    data2 = data1;  // this is not needed since we laready copied the data1 to data2. In order to optimize our code, compiler do not generate machine code for this statement when optimization is set to O1. When optimization is set to O1, compiler generates anyway.
    // Also valid for unused varables, compiler does not generate a machine code for them to optimize our code.
    // Being in optimization level1, how can we make our compiler to geenrate machine codes in the above cases. We use volatile keyword! Tell the compiler that do not make optimization on these varables.
    uint8_t volatile data3;
            

    // A variable must be declared using a volatile qualifier when there is a possibility of unexpected changes in the varible value.
    // The unexpected change in the variable may happen from within the code or from outside the code (from HW).
    // Use volatile when your code is dealing with below scenarios:
        // Memory-mapped peripheral registers of the MCU.
        // Multiple tasks accessing global variables(read/write) in an RTOS multithreaded application.
        // When a global variable is used to share data between the main code and an ISR code.
    
    // Case1: Volatile data
    uint8_t volatile data4;
    // volatile uint8_t data4;  // also okay
            
    // Case2: non-volatile pointer to volatile data. Perfect case of accessing memory-mapped registers.
    uint8_t volatile *pStatusReg;

    // Case3: Volatile pointer to non-volatile data. Rarely used.
    uint8_t *volatile pStatusReg;

    // Case4: Volatile pointer to volatile data. Rarely used.
    uint8_t volatile *volatile pStatusReg;
    
    // Applying these qualifiers to a variable decleration is called qualifying the decleration.

    // An example to memory-mapped peripheral registers of MCUs.
    // In the below code *pPortAInReg must be read by MCu again and again. However, when we make out optimization level O2, compiler thinks that this parameter does not change, so it reads this file only once.
    // So, we have to tell the compiler that the DATA pointed by this pointer may change at any time, So, not to do any optimizations on DATA READ and DATA WRITE operations using this pointer. So we need to declare this pointer as:
    uint32_t volatile *const pPortAInReg =   (uint32_t*)0x40020010;
    // Insted of:
    uint32_t *const pPortAInReg =   (uint32_t*)0x40020010;
    // So now, compiler will not optimize any read and write operations performed on this pointer. So, that would solve this issue.
    while(1)
	{
		//read the pin status of the pin PA0 (GPIOA INPUT DATA REGISTER)
		uint8_t  pinStatus = (uint8_t)(*pPortAInReg & 0x1); //zero out all other bits except bit 0

		if(pinStatus){
			//turn on the LED
			*pPortDOutReg |= ( 1 << 12);
		}else{
			//turn off the LED
			*pPortDOutReg &= ~( 1 << 12);
		}
	}

    // An example to When a global variable is used to share data between the main code and an ISR(Interrupt Service Routine) code: 

    /**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/
// !!!!!!!! IN ORDER TO MAKE THIS CODE RUNNING YOU NEED TO CHECK WHERE BUTTON IS CONNECTOED FOR YOUR BOARD! 
#include <stdint.h>
#include <stdio.h>

//global shared variable between main code and ISR. If the below parameter is not declared as volatile, program does not work properly for different optimization levels!
uint8_t volatile g_button_pressed = 0;

uint32_t g_button_press_count =0;

void button_init(void);

// These are memory mapped peripheral registers being configured and accessed in this project.
// THIS ONLY RUNS WITH OPTIMIZATION LEVEL O0 UNLESS YOU ADD THE VOLATILE KEYWORDS GIVEN BELOW!
uint32_t volatile *pEXTTIPendReg			= (uint32_t*) (0x40013C00 + 0x14);
uint32_t volatile *pClkCtrlReg				= (uint32_t*) (0x40023800 + 0x30);
uint32_t volatile *pClkCtrlRegApb2			= (uint32_t*) (0x40023800 + 0x44);
uint32_t volatile *pGPIOAModeReg 			= (uint32_t*) (0x40020000 + 0x00);
uint32_t volatile *pEXTIMaskReg 			= (uint32_t*) (0x40013C00 + 0x00);
uint32_t volatile *pEXTTIEdgeCtrlReg		= (uint32_t*) (0x40013C00 + 0x08);
uint32_t volatile *pNVICIRQEnReg 			= (uint32_t*) 0xE000E100;


int main(void)
{
	button_init();

	while(1)
	{
		//Disable interrupt
		*pEXTIMaskReg &= ~( 1 << 0);

		if(g_button_pressed){      // each iteration main code checks this global flag. If this is set by the ISR, it prints how many times this button is pressed.
			
			for(uint32_t volatile i=0;i<500000/2;i++);   //This is a delay for button debouncing gets over. When we change optimiztion level, compiler deletes this statement since it thinks this slows our program. That's why we added a volatile keyword here.
			g_button_press_count++;
			printf("Button is pressed : %lu\n",g_button_press_count);
			g_button_pressed = 0;
		}

		//Enable interrupt
		*pEXTIMaskReg |= ( 1 << 0);
	}


}


void button_init(void)
{

  *pClkCtrlReg |= ( 1 << 0);

  *pClkCtrlRegApb2 |= ( 1 << 14);

  *pEXTTIEdgeCtrlReg |= ( 1 << 0);

  *pEXTIMaskReg |= ( 1 << 0);

  *pNVICIRQEnReg |= ( 1 << 6);

}

/* This is button interrupt handler, it will be executed whenever the onboard button of the board is pressed.*/ 

void EXTI0_IRQHandler(void)
{
	//Make this flag SET . if button pressed
  g_button_pressed = 1;   // What we do in this ISR is that we set the global flag.

  *pEXTTIPendReg |= ( 1 << 0);   // Then, ISr exits, that's all.
}

// CONST AND VOLATILE!
// Const and volatile are not opposite of eachother. Both are different type qualifiers.
uint_8 volatile *const pReg = (uint8_t*)0x40000000;  // pReg is a const pointer pointing to volatile data of type uint8. Const is just to guard this pointer from unexpected changes from the programmer.
                                                     // An we are telling the compiler that, the data present at this address may undergo unexpected changes. Do not operate any optimization on this pointer.

uint_8 const volatile pReg = (uint8_t*)0x40000000;   // pReg is a const pointer pointing to const volatile data of type uint8. Data pointed by this pointer is volatile, it is subjected to unexpected changes but programmer must not change the data present at this address. So, that's the meaning of const volatile.
                                                     // Again const here for programmer not to change the value present at this address. And volatile is for the compiler not to optimize the read and write operation on this address.

// Case of reading from read-only buffer or address which is prone to unexpected change. (For instance: input data register, this is read-only, you need to only read not modify.) In this case use below statement:
uint8_t const volatile *const pReg = (uint8_t*) 0x40000000;  // The address should not be modified by the programmer, because it is const. But the data at this address may get changed by the data coming from the external world.
                                                             // So the address can still undergo unexpected change but the programmer should not modify it.