/*
 * Print_Output.c
 *
 *  Created on: 27 jul. 2022
 *      Author: nlbguz
 */

# include <stdio.h>   
# include <stdint.h>   	
int main()     			
{
    // Integer data types: represent whole numbers
        // Integer data types for signed data:
            // char:          1 byte / -128 to 127
            // short int:     2 bytes / -32,768 to 32,767  / also can be called as short, compiler will refer to short int
            // int:           4 bytes / -2,147,483,648 to 2,147,483,647
            // long int:      8 bytes (4 bytes for arm based MCUs) /  / also can be called as long, compiler will refer to long int
            // long long int: 8 bytes / same with long int / also can be called as long long, compiler will refer to long long int
        // Integer data types for unsigned data: (we need to use unsigned everytime we want to define them)
            // unsigned char:             1 byte / 0 to 255
            // unsigned short int:        2 bytes / 0 to 65,535
            // unsigned int:              4 bytes / 0 to 4,294,967,295
            // unsigned long int:         8 bytes (4 bytes for arm based MCUs) / 0 to ...
            // unsigned long long int:    8 bytes / 0 to ... same with long int! 
    // Float data types: represent real numbers
	// The size of the data can be vary depends on compiler! Numbers given above are for standard C data types. Check reference manual of the compiler that you use!
    // Size of short, char and long is always fixed, does not cahnge depends on the compiler! 

    // 7 6 5 4 3 2 1 0 Let`s say this represents bits in a byte.
        // If bit number 7 (most significant bit) is 0 data is +, if bit number 7 is 1 data is negative!
        // Other seven bits are used to store magnitude.
        // When bit number 7 is 0(positive), 0 0 0 0 0 0 0 0 means 0. 0 1 1 1 1 1 1 1 means +127.
        // When bit number 7 is 1(negative), 1 0 0 0 0 0 0 0 means -128. 1 1 1 1 1 1 1 1 means -127. That is why chars are from +127 to -128!!! No need to define 0 two times!
        // For unsigned data types no need to define sign with a bit, so all 8 bits are used to store magnitude.

    // CHAR: is an integer data type to store a single character (ASCII code) value or 1 byte of signed integer value.
    // Allocates only 1 byte in memory.
    // Signed char -128 to 127, unsigned char 0 to 255.

    /* An example to calculate distance between 2 cities.
    unsigned char distanceA2B = 160;
    unsigned char distanceB2C = 40;
    unsigned char distanceA2C = distanceA2B + distanceB2C;
    printf("Total distance from A2C = %d Km \n", distanceA2C);
    printf("Total distance from A2C = %x Km \n", distanceA2C);   // converts distanceA2C to hex and shows hex equivalent of distanceA2C
    printf("Total distance from A2C = %c Km \n", distanceA2C);   // displays an unknown character which is equavalent to 200.
    */

    // SHORT INT AND UNSIGNED SHORT INT:
    // Allocates 2 bytes in memory.
    // short int:     2 bytes / -32,768 to 32,767  / also can be called as short, compiler will refer to short int.
    // unsigned short int:        2 bytes / 0 to 65,535
    // Takes ones complement to store a negative value (one`s complement is converting all 1s to 0 and 0s to 1.) and add 1 (2`s complement)
        // 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 = 25
        // 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1 0            1s complement
        // 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1 1 = -25      Added 1 2s complement
    
    // INT AND UNSIGNED INT:
    // Allocates min 2 max 4 bytes in memory. Depends on the compiler used.

    // LONG AND UNSIGNED LONG:
    // Allocates min 4 max 8 bytes in memory. Depends on the compiler used.

    // SIZEOF OPERATOR
    // Used to find out the size of a variable.
    // The output of the sizeof operator can be different on different machines because it is compiler dependent.
    // printf("Size of char data type = %d\n",sizeof(distanceA2B));
    // printf("Size of char data type = %d\n",sizeof(char));
    // printf("Size of int data type = %d\n",sizeof(int));
    // printf("Size of long data type = %d\n",sizeof(long));
    // printf("Size of long long data type = %d\n",sizeof(long long));

    // VARIABLES:
    // Variables are identifiers for your data.
    // Data are usually stored in computer memory.
    // So, a variable acts as a label to a memory location where the data is stored.
    // Variable names are not stored inside the computer memory, and the compiler replaces them with memory location addresses during data manipulation.
    // Variable definition (also called variable decleration but actually it is different) is nothing more than letting the compiler know you will need some memory space for your program data so it can reserve some.
    // variable definitian and initialization can be done in one statement: int a = 100;
    // Rules for varable names:
        // Not more than 30 chars
        // can contain only alphabets(uppercase or lowercase), digits and underscore.
        // first letter can not be a digit can be either alphabet or underscore.
        // C standard keywords can not be used as variable name! (Keywords can be found in google)

    // Difference Between Defining and Declaring a Variable:
    // A variable definition is decleration, but not all declerations are definitions.
    // When we define a global variable, we can use extend C keyword to tell compiler that this is defined outside of the main.c (current file).

    /*
    extern int myExamScore;         // Compiler will not allocate any memory for this cariable, this is decleration!
    int main()
    {
        int myExamScore;          // This is definition!
        myExamScore = 540;
        return 0;
    }
    */

    // A variable scope refers to accessibility of a variable in a given program or function. For example, a variable may only be available within a specific function, or it may be available to the entire C program.   
        // Local scope variables (Local variables)
            // Default value is garbage value (always initialize!)
            // Life time is till the end of the execution of a function in which a varable is defined.
        // Global Scope Variables (Global Variables)
            // Can be even accessed from another file of the project.
            // All uninitialized global variables will have 0 as default value.
            // Lifetime is till the end of the executation of the program!
    
    /*    To run this code command out main() and curlies!
    void myFun1(void);     // This is a function protoype! Should be added here to tell main this will be defined later!
    
    // int myExamScore = 80;   // NO need to write global!!
    
    int main()
    {
        int myExamScore;       // If we define the samevariable again in local, compiler will not generate an error. However, when you print this in local function, program will be calling local value not the global one! 
        myExamScore = 70;      
        printf ("1) Value of my score = %d\n", myExamScore);
        
        myFun1();          // Calling the function
        return 0;
    }
    
    void myFun1(void)    // means this function does not return anything, and no argument is needed.
    {
        myExamScore = 100;   // causes error since MyExamScore is local to function main! Define it as global (before main!)!
        printf("2) Value of my score = %d\n", myExamScore);
    }

    */
    // If we define the samevariable again in local, compiler will not generate an error. However, when you print this in local function, program will be calling local value not the global one!
    /*

    // int myExamScore = 80;   
    
    int main()
    {
        {
            int myExamScore = 67;       // If we define the samevariable again in local, compiler will not generate an error. However, when you print this in local function, program will be calling local value not the global one! 
                                        // This variable is not available to use outside this block. It will be deleted!
        }
        
        printf ("Value of my score = %d\n", myExamScore);   // shows 80 since 67 was defined in local!        
        
        return 0;
    }
    */

    // ADRESS OF A VARIABLE AND TYPECASTING 
    // Putting an ampersand operator before the variable, shows us its location address on our memory.
        // Example &mydata
    // This address is also called as a pointer, since it is pointing a data!
    // /*
    char mydata ='A';
    printf("Address of variable mydata = %p\n", &mydata);
    // We can also save this address in a variable:
    // unsigned long long int addressofmydata = &mydata; // Although, unsigned long long int allocates 8 bytes as pointers do, this causes a warning since we are trying to save a pointer data type to int!
    // Using unside long can cause another warning, because in MinGW compiler unsigned long allocates 4 bytes!
    // To solve this issue, we need to use type casting (converting the data type!)
    unsigned long long int addressofmydata = (unsigned long long int)&mydata; // here we convert pointer to unsigned long int before assigning it to a unsigned long int variable!
    printf("Address of variable mydata = %I64u\n", addressofmydata); // Used I64u since this is a unsigned long long int
    printf("Address of variable mydata = %I64X\n", addressofmydata); // Used I64X to convert the address in hex format. Only prints 3 bytes since other bytes are actually zero. 
    // */

    // Address size is 8 bytes, since my machine is a 64 bits machine. It would be 4 bytes for 32 bits machine and 2 bytes for 16bits machine!
    // Address size is compiler and hardware-specific. For ARM cortex Mx based STM32 Microcontrollers, the pointer size is 4 bytes.

    // ASCII CODES:
    // ASCII refers to The American Standard Code for Information Interchange
    // By using ASCII standard, you can encode 128 different chars.
    // To encode a ASCII character, you need 7 bits! You can use char type!
    // Check ASCII table to see which code refers to a char!
    // For machienes everything is numbers, it stores 'apple' with their ASCII codes in its memory.
    char a1 = 65;
    // char a1 = 'A'; // These are both same since A's ASCII code is 65.
    printf("a1 = %c\n", a1); // prints A
    printf("a1 = %d\n", a1); // prints 65, because A is converted to integer!

// MANIPULATE DECIMAL NUMBERS IN C (FLOAT AND DOUBLE)
    // Too small or too big numbers or numbers with fractional part (decimal number) are represented by using floating-point representation data types such as float and double.
    // IEEE 574 floating point standard are used to store and modify floating point formats. This is the format follwed by all modern MCUs and PCs.
    // Imagine a really big or small number, storing it with its binary equavalent cause waste of memory. IEE574 standard stores only mantissa (significand) and exponent.
    // +7.432x10^48 ==> +7.432 is the mentissa, 48 is the exponent. The number will be approximated and saved in the memory.
    // There are two formats to store this numbers:
        // Single precision (float): 32 bits representation. 23 bit for significan, 8 bits for exponent, 1 bit for sign.
        // Double precision (double): 64 bits representation. 52 bit for significan, 11 bits for exponent, 1 bit for sign. Does higher level approximation.
    // Format specifiers for these data types:
        // %lf double
        // %f float
        // %e and %le for  real numbers in scientific notation
        // %0.9f float prints 9 digits after decimal point. However, after 6 it is not accurate since float stores 6 digits at most.
	    // %0.14lf double prints 14 digits after decimal point.
        // %e and %le for real numbers in scientific notation // e.g 4.578977e+001
	    // %0.2e and %0.2le for real numbers in scientific notation // e.g 45.8e+001
    // All constants with a decimal point are considered as double by default.
    // Float 4 bytes / precision up to 6 decimal places
    // Double 8 bytes / precision up to 15 decimal places

    float chargeE = -1.602176662e-19;

    // MULTIPLE INPUTS:
    double b1=0, b2 = 90;
    printf("%lf %lf", b1, b2);

    // TYPE QUALIFIERS IN C
    // There are two time qualifiers (niteleyici (niteleme sifati), a word or phrase, especially an adjective, used to attribute a quality to another word(noun).) in C:
        // 1) const: used to enforce read-only feature on variables. Can not be changed after initialization. 
            uint8_t const data1 = 10;   // this is preferred!
            // const unit8_t data1 = 10;  // also works
            // data1 = 20; // causes compile error since data1 is read-only!
            // You can still modify the content of the variable by using its address (pointer)!
            uint8_t *ptr = (uint8_t*)&data1;
            *ptr = 50;   // no error!
            // Const values are also stored in RAM(data memory) as non-const variables are.
            // All global const variables are stored in ROM or Flash (code memory). This also depends on linker script rules and the hardware on which code runs.
            // For STM32 MCUs, all global const variables are stored in FLASH memory. So, when you try to modify the const varable using its address, operation has no effect. Because flash memory of the microcontroller is write-protected.
            // Modifying global const by using pointer causes crash (on PC) since they are stored in read only memory (flash (code memory))!! On STM32 program will not crash but not be executed.
            // Const data modifiable pointer:
                uint8_t const *pData = (uint8_t*) 0x40000000;   // Here the pointer pData is modifiable, but the data pointed by the pData can not be modifiable (read-only).
                // We can say that pData is a pointer pointing to read-only data. Pointer itself can be modifed but not the data it is pointing to.
                // Use this for example you want copy the data to somewhere else. Program can not modify the data but copy! Espacially when a function is getting the data from user!
            // Modifiable data, const pointer:
                uint8_t *const pData1 = (uint8_t*) 0x40000000;   // Here the pointer pData is const, but the data pointed by the pData1 can be modifiable.
                // Used especially when a function gets the data from another function.
            // Const data, const pointer:
                uint8_t const *const pData1 = (uint8_t*) 0x40000000;   // Both const! Both read only.
                // Used when we want to read data from the status register of HW. Status register should not be modified otherwise cause the system to fail.
        // 2) volatile (ucucu)
            // It telss the compiler that the value of the variable may change at any time with or without the programmer's constent. So, the compiler turns off optimizing the read-write operations on variables which are declared using volatile keyword.
            uint8_t data1;
            uint8_t data2;

            data1 = 50;

            data2 = data1;
            data2 = data1;  // this is not needed since we laready copied the data1 to data2. In order to optimize our code, compiler do not generate machine code for this statement when optimization is set to O1. When optimization is set to O1, compiler generates anyway.
            // Also valid for unused varables, compiler does not generate a machine code for them to optimize our code.
            // Being in optimization level1, how can we make our compiler to geenrate machine codes in the above cases. We use volatile keyword! Tell the compiler that do not make optimization on these varables.
            uint8_t volatile data3;
            

            // A variable must be declared using a volatile qualifier when there is a possibility of unexpected changes in the varable value.
            // The unexpected change in the variable may happen from within the code or from outside the code (from HW).
            // Use volatile when your code is dealing with below scenarios:
                // Memory-mapped peripheral registers of the MCU.
                // Multiple tasks accessing global varables(read/write) in an RTOS multithreaded application.
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

}