/*
 * Pointers.c
 *
 *  Created on: 02 Aug. 2022
 *      Author: nlbguz
 */

# include <stdio.h>   


int main()     			
{
    // Unary operators (Increment - decrement): Since these requires only one operand, these are called unary operators.
        int a1 = 0;
        int a2 = 0;
        a1++;     
        ++a1;   // Also works but a bit different.  
        a2 = a1++;  // assume both started wit 0, a2 will be 0, a1 will be 1. (this is called postincrementin, first assigns a1 to a2 than increments a1)
        a2 = ++a1;  // assume both started wit 0, both will be 1 (this is called preincrementing, first increments a1, than assigns a1 to a2)
        a1--;
        // Can also be used with pointers.
        int *pAdress1 = &a1;
        pAdress1++;
    
    // Binary Operators: Requires two operands. All below are binary operators: 
    // Aritmatic Operators:
        // +,-,*,/,%
        // % is modulus operator, returns reminder.
    
    // Relational Operators:
        // <, <=, >, >=, ==, !=

    // Logical Operators:
        // &&, ||, !

    // Bitwise Operators:
        // &, |, <<, >>, ~, ^
        // << bitwise left shift!
        // ~ bitwise not!
        // ^ bitwise XOR!
        // Lets say that A = 0 0 1 0 1 0 0 0
        //               B = 0 0 0 1 1 1 1 0
        //           A & B = 0 0 0 0 1 0 0 0 
        // However A && B = 1, since both A and B are nonzero!
        // Lets say that A = 0 0 1 0 1 0 0 0
        //              ~A = 1 1 0 1 0 1 1 1        C = ~A also possible!
        // 
        // Lets say that A = 0 0 1 0 1 0 0 0
        //               B = 0 0 0 1 1 1 1 0
        //           A ^ B = 0 0 1 1 0 1 1 0 
        // Bit masking: is a teqnique in programming used to test or modify the states of the bits of a given data.
            // This is the number we want to check:                         0 0 1 0 1 0 0 0
            // Mask: Set the nth bit of 1 and rest 0 ant use bitwise and:   0 0 0 0 0 0 0 1 we are checking the right most bit! When compare the two numbers, we will understand whether 1st bit of number is 1 or 0.
            // Example: (number & 1) this checks the right most bit since 1 = 0 0 0 0 0 0 0 1
            // & is used to test, | is used to set bits:
                // Lets say that A = 0 0 1 0 1 0 0 0
                //               B = 0 0 0 1 1 1 1 0   if nth bit of B is 1 the result also be 1, we are stting bits!
                //           A | B = 0 0 1 1 1 1 1 0 
            // & can also be used to clear! Using & and ~ together also another method. Learn how to apply this method.
                // Lets say that A = 0 0 1 0 1 0 0 0
                //               B = 0 0 0 1 1 1 1 0   You are setting each nth bit of result to 0 by using zero in that bit in B.
                //           A & B = 0 0 0 0 1 0 0 0 
            // ^ can be used to toggle bits by using more once
                    // Lets say that A = 0 0 0 0 0 0 0 1
                    //               B = 0 0 0 0 0 0 0 1   You are setting each nth bit of result to 0 by using zero in that bit in B.
                    //           A ^ B = 0 0 0 0 0 0 0 0 
                    // Next turn     A = 0 0 0 0 0 0 0 0
                    //               B = 0 0 0 0 0 0 0 1   You are setting each nth bit of result to 0 by using zero in that bit in B.
                    //           A ^ B = 0 0 0 0 0 0 0 1   Continues like this!
    // First bit of a bite is least significant bit, last bit of a byte is most significant bit.

    // Assignment Operators:
        // =, +=, -=, *=, /= , %=

    // Ternary Operators: Requires three operands. 
    // Conditional Operators:
        // ?:
    // CONDITIONAL OPERATOR

        uint32_t a4 = (5 + 4) ? (9 - 4) : 99;   // first checks if (5 + 4) is true if yes a4 = (9-4) Anything nonzero is true!
                                                                                //if not a4 = 99   
        uint32_t a5 = (5 - 5) ? (9 - 4) : 99;   // first checks if (5 - 5) is true if yes a4 = (9-4) Anything nonzero is true!
                                                                                  //if not a4 = 99 
                                                
        printf("a4 = %d\n", a4);
        printf("a4 = %d\n", a5);


    // To see the precedence(oncelik) of the operators, check internet. However, using paranthesis is also okay. You do not need to know precedence.
    // * and / have precedence, then associatiativity comes in place, it goes from left tot right. Whatever comes first will be processed first! 
    // Each bit of GPIO Output data register controls one I/O.

    // How to use an I/O:
        // 1) Identify the GPIO port (a peripheral) used to connect the LED.
        // 2) Identify the GPIO pin where the I/O is connected.
        // 3) Activate the GPIOD peripheral (enable the clock) : In MCUs, by default most of the peripherals are dead, you need to activate them. activating them is nothing but enabling clock for them.
            // For some MCUs peripheral can be ON by default, you do not need to activate them.
        // 4) Configure the GPIO pin mode as input or output.
        // 5) Write or read from GPIO pin.
    
    // How to enable peripheral clock:
        // The peripheral is enabled throug peripheral clock control registers of the MCU.
        // For all STM32 MCU, all clock register are mapped at these address range in the memory map of the MCU: 0x4002 3800 - 0x40023BFF
        // In STM32 microcontrollers there is an encgine called RCC (Reset and Clock Control). This RCC engine takes care of controllin clocks for various part of the MCU such as processor, different peripherals, different buses, memories etc. 
        // RCC engine has its own set of addresses to control the clock and all those registers are mapped at above address renge. 
        // To enable clock, select a appropriate register in the RCC block to enable the clock.
        // Go to reference manual and explore RCC registers (Section 6)
        // RCC AHB1 peripheral clock register is used to enable clocks for those peripherals which are hanging on the AHB1 bus.
        // GPIOD hangs on AHB1 bus. (This information can be found data sheet of the MCU. Check internal architecture scheme of the MCU)
        // We should add the offset, given in 'RCC AHB1 peripheral clock register' section of reference manual, to base address of the RCC to get the address of RCC AHB1 peripheral clock register. 
        // Activate 3rd bit position, GPIODEN: I/O port D clock enable! if 1 enabled.
    
    // How to calculate peripheral register address:
        // The RCC register for GPIOD is AHB1ENR. Let`s calculate the address of this register.
        // Take base address and add offset (given in 'RCC AHB1 peripheral clock register' section of reference manual) 

    // How to calculate address of the GPIOD mode register:
        // Find the GPIOD's base register address in the reference manual.
        // Add offset (given in GPIO registers section 6 of reference manual.) 
        // This register is devided to 16 sections (2 bits for each = 32 bits). Each section controls the mode of the corresponding pin (16 pins on GPIOD)
        // Why 2 bits are dedicated because there are four modes!
            // 00 Input (Default state)
            // 01 General purpose output mode
            // 10 Alternate function
            // 11 Analog function
    
    // How to calculate address of GPIOD output data register (to write):
        // Find the GPIO port output data registers in GPIO registers section 6 of reference manual
        // Only sixteen bit are implemented since there are only 16 pins. 0th port controls 0th pin. Find offset.
        // Add this offset to the base address of GPIOD (in the reference manual)


}