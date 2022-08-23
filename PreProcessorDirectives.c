// In C programming pre-processor directives are used to affect compile-time settings.
// Pre-processor directives are also used to create macros used as a textual replacement for numbers and other things.
// Pre-processor directives begin with the "#" (hash) symbol.
// Pre-processor directives are resolved or taken cared during the preprocessing stage of compilation.
// Pre-processor directives actually direct the compiler to take certain actions during the compile time.

// PRE_PROCESSOR DIRECTIVES SUPPORTED IN "C" 
    // MACROS:
        // We most commonly use pre-processor directives while we write macros and when we want to do file inclusion.
        // Macros are nothing but they are just tectual replacement for numbers and other things.
        // #define is one type of pre-processor directive and it is used to write macros in 'C'.
    // FILE INCLUSION: #include is another type of pre-processor directive supported by 'C', which is used for file inclusion. File can be a header file or any other file like standard library header file or user defined etc.
    // CONDITIONAL COMPILATION: Used to direct compiler about the code compilation. (#ifdef, #endif, #if, #else, #ifndef, #undef)
    // OTHERS: #error, #pragma!

// Macros in 'C' (#define):
    // Macros are written in C using #define preprocessor directive.
    // Macros are used for textual replacement in the code, commonly used to define constants.
    // Syntax: #define <Identifier> <Value>
    // Example: #define MAX_RECORD 10
    // Macro names (identifiers) are replaced by the associated values inside the program. Remember once somethin is defined in macro it is not a variable. It is called as identifier. Just a textual replacement for a number.
    // One adventage of using macros is when you define a ideetifier with macros and used it several times in your code and after that you need to change it. You do not have to make several changes in your code, just changing the value of the identifier in macro is enough.
    // In Embedded system programing, we use lots of 'C' macros to define pin numbers, pin values, crystal speed, peripherla register addresses, memory addresses and for other configuration values. Examples:
    #define PIN_8 8     // Using capital or latter name is optinal. But mostly we use capital letters for macros to distingush between variable name and a macro.
    #define GREE_LED PIN_8 // No semicolon to terminate the statement!
    #define LED_STATE_ON 1
    #define LED_STATE_OFF 0
    #define XTAL _SPEED 8000000UL // UL means unsigned long, so that is allowed to tell the compiler about the type of the data.
    #define FLASH_BASE_ADDR 0x08000000UL
    #define SRAM_BASE_ADDR 0x20000000ul

    // Function like macros:
        // To define a function-like macro, use the same '#define' directive, but put a pair of parantheses immediately after the macro name.
        #define PI_VALUE 3.1415
        #define ARE_OF_CIRCLE(r) PI_VALUE * r * r
    	// in main.c
        areaCircle = ARE_OF_CIRCLE(radious);
    
    // Always be careful for macros with multiple operations. Always keep in mind that macros are only replacements!!
        areaCircle = ARE_OF_CIRCLE(1+1); // if you pass a value like shown left, it will replace the argument of the macro with this value 
        // 3.1415 * 1 + 1 * 1 + 1 this will be calculated because of replacement and becouse of the precedence of the operators, tis will be calculated wrong.
        // DEFINE MACROS WITH PARANTHESIS AS SHOWN BELOW:
        #define PI_VALUE (3.1415)
        #define ARE_OF_CIRCLE(r) ((PI_VALUE) * (r) * (r))
    // Best practises while writing Macros in C:
        // Use meaningful names
        // It is recommended to use upper case latters for macro names to distinguish them from variables.
        // Remember, macro's names are not variables. They are labels or identifiers, and they do not consume any code space or ram space during compile time or run time of the program.
        // Make sure that paranthesese surround the macro value.
        // While using function-like macris or when you are using macros along with any operators, always surround the operands with parantheses.

    // CONDITIONAL COMPILATION DIRECTIVES:
        // Examples: #ifdef, #endif, #if, #else, #ifndef, #undef
        // These directives help you to include or exclude individual code blocks based on varous conditions set in the program.
        // #if, #else and #endif: REMEMBER THIS IS CHECKED DURING PRE_PROCESSCOR STAGE OF THE PROGRAM WHETHER TO INCLUDE A CODE BLOCK OR NOT IN THE FINAL EXECUTABLE OF THE PROGRAM.
            // This directive checks whether the constant ecpression is zero or non zero value. If constant is 0, then the code block will not be included for the code compilation and vice versa.
            #if <constatn expression> // constant expression must be a number or integer.
            #if 1 // or 0
            // code block
            #else
            // code block
            #endif // marks the end of scope of #if, #ifdef, #ifndef, #else, #elif
            // The above code is used in main function to add or remove some code statements. This statements will be included or excluded to build!
        // #ifdef(if defined) directive checks whether the identifier is defined in the program or not. If the identifier is defined, the code block will be included for compilation.
            // So, the evaluation of this pre-processor directive depends upon definition of a macro.
            #ifdef NEW_FEATURE // If this NEW_FEATURE macro is defined in program, tinclude this code block, otherwise exclude this code block.
            // code block
            #endif // marks the end of scope of #if, #ifdef, #ifndef, #else, #elif
            // Example: 1) Execute triangle area calculation code block only if AREA_TRI macro is defined in program.
            #define AREA_TRI
            //  In main func:
            #ifdef AREA_TRI // checks if this macro is defined or not! In this case it is defined.
            // codeblock    // #else can also be used between ifdef and endif
            #endif
            // If you are not able to edit source file to include this statement (#define AREA_TRI), you can also send this macro name as a compiler argument.
            // To do this, copy macro name, right click to project ==> properties ==> Expand C/C++ Build ==> Settings ==> GCC C Compiler ==> Preprocessor ==> Add Macro name to Defined sybols ==> Apply and close
            // That compiler argument is passed as a compiler argument.
            // Command to perform build become gcc -DAERA_TRI -O0 -g3 -Wall -c -fmessage-length=0 -o test.o
            // Example: 2) Execute circle area calculation code block only if AREA_CIR macro is defined and execute triangle area calculation code block only if AREA_TRI macro is defined in the program.
            #ifdef AREA_CIR // checks if this macro is defined or not! In this case it is defined.
            // codeblock
            #endif
        // #undef is used to undefine a defined macro
        #define AREA_TRI  // defines macro
        #undef AREA_TRI   // undefines macro
            // Example 3) Execute circle area calculation code block only if AREA_TRI macro is NOT defined in program.
            #ifndef AREA_CIR // checks if this macro is  NOT defined! If it is not defined includes the code block.
            // codeblock     // #else can also be used between ifndef and endif
            #endif
    
    // DEFINED OPRATOR:
    // The defined operator is used when you want to check definitions of multiple macros using single #if, #ifdef or #ifndef directives.
    // C logical operators such as AND, NOT, OR can also be used with defined operator.
    // Example, if both AREA_CIR and AREA_TRI are defined, codeblock will be included to build.
    #ifdef AREA_CIR
        #ifdef AREA_TRI
        // codeblock
        #endif
    #endif
    // Instead of this nested if we can use defined operator.
    #if defined(AREA_TRI) && defined(AREA_CIR)
    // codeblock
    #endif
    
    // To terminate the compilation with an error message, we can use #error pre-processor directive. Below code works both in main fucntion or out of the main function.
    #if !defined(AREA_TRI) && !defined(AREA_CIR)
    #error "No macros defined!"
    #endif

    // To terminate the compilation with a warning message, we can use #error pre-processor directive. Below code works both in main fucntion or out of the main function.
    #if !defined(AREA_TRI) && !defined(AREA_CIR)
    #warning "No macros defined!"
    #endif

// IDE EXAMPLE: Led toggle with Macros
// main.h:
#ifndef MAIN_H_
#define MAIN_H_

#include<stdint.h>

#define ADDR_REG_AHB1ENR  ((RCC_AHB1ENR_t*) 0x40023830)
#define ADDR_REG_GPIOD_MODE ((GPIOx_MODE_t*) 0x40020C00)
#define ADDR_REG_GPIOD_OD ((GPIOx_ODR_t*) 0x40020C14)

#define CLOCK_ENABLE (1)
#define MODE_CONF_OUTPUT (1)
#define PIN_STATE_HIGH (1)
#define PIN_STATE_LOW (0)
#define DELAY_COUNT (300000ul) // unsigned long! both lowercase and uppercase are fine

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


#include<stdint.h>
#include "main.h"

int main(void)
{
	// uint32_t *pClkCtrlReg =   (uint32_t*)0x40023830;
	// uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
	// uint32_t *pPortDOutReg =  (uint32_t*)0x40020C14;
    
    // Create a pointer variable with the same type of the structure.
    RCC_AHB1ENR_t volatile *const pClkCtrlReg   = ADDR_REG_AHB1ENR;   // Initialize the edresss with the register's address from datasheet (reference manual).
	GPIOx_MODE_t  volatile *const pPortDModeReg = ADDR_REG_GPIOD_MODE;  
	GPIOx_ODR_t   volatile *const pPortDOutReg  = ADDR_REG_GPIOD_OD;

    // Setting which bit can be found in datasheet of the board. However, providers also should give an easier interface to set these bits for users.
    // In order to provide that easier interface, we need to create a similar structure that we created in Union.c, but in this case for peripheral register.
    // Basically we convert the bit structure given in dataheet as "RCC AHB1 peripheral clock enable register" (RCC-AHB1ENR) table.
	
    // 1. enable the clock for GPOID peripheral in the AHB1ENR (SET the 3rd bit position)
	// *pClkCtrlReg |= ( 1 << 3); // here we are trying to change the 3th bit position of this peripheral register (RCC AHB1ENR).
    pClkCtrlReg->gpiod_en = CLOCK_ENABLE;



	//2. configure the mode of the IO pin as output
    pPortDModeReg->pin_12 = MODE_CONF_OUTPUT;
	//a) clear the 24th and 25th bit positions (CLEAR)
	// *pPortDModeReg &= ~( 3 << 24); 
	//b) make 24th bit position as 1 (SET)
	// *pPortDModeReg |= ( 1 << 24);  // Changing the 24th bit positon

	while(1)
	{
		//SET 12th bit of the output data register to make I/O pin-12 as HIGH
		// *pPortDOutReg |= ( 1 << 12);    // when we using this statement, we use bitwise operators to program the appropriate bit positions of the peripheral. But in the below statement we shift this work to compiler.
        pPortDOutReg->pin_12  = PIN_STATE_HIGH;   // dereferencing the pointer element to set the pin

		//introduce small human observable delay
		//This loop executes for 10K times
		for(uint32_t i=0 ; i < DELAY_COUNT ; i++ );

		//Tun OFF the LED - //Reset 12th bit of the output data register to make I/O pin-12 as LOW
		// *pPortDOutReg &= ~( 1 << 12);
        pPortDOutReg->pin_12  = PIN_STATE_LOW;

		for(uint32_t i=0 ; i < DELAY_COUNT ; i++ );
	}

	for(;;);

}
