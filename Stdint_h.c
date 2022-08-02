/*
 * Pointers.c
 *
 *  Created on: 02 Aug. 2022
 *      Author: nlbguz
 */

# include <stdio.h>   
# include <stdint.h>


int main()     			
{
    // stdint.h is one of the standard library header file. Let's saywe have written a C program, when we compile it in different compilers, our code become buggy since different data types occupies different number of bytes in memory.
    // This is called portability issues.
    // Portability issues in C programming due to size of data types:
        // The storage size of the int and long long type is not defined within C standard (C90 and C99).
        // Standard tells us about minimum and maximum amount of storage that a data type can occupy, therefore compilers use different amounts depends on their HW capabilities. For example int occupies 2 bytes for PIC8 MCUs, but for ARM MCUs 4 bytes.

    // So, the Standard Library header file stdint.h defines fixed width integers using alias data types for the standard data types available in C.
    // A fixed width integer data type is an aliased data type that is based on the exact number of bits required to store the data.
    // stdint.h library helps you to choose an exact size for your variable and makes code portable no matter which compiler the code may be compiled.
    // Below hte aliased names of standard data are given. Keep in mind that these are not new data types, just aliased(takma isim) names to standard data types of C. Each compiler carries its own stdint.h which needs to be included in the project to use these.
    int8_t a1;    // signed char 8 bits of memory. Normally what is signed data which occupies 8 bits is signed char. So, instead of signed char use this one!
    uint8_t a1;   // unsigned char 8 bits of memory
    int16_t a1;   // signed data with 16 bits
    uint16_t a1;  // unsigned data with 16 bits
    int32_t a1;   // signed data with 32 bits
    uint32_t a1;  // unsigned data with 32 bits
    int64_t a1;   // signed data with 64 bits
    uint64_t a1;  // unsigned data with 64 
    // It does not matter under which compiler this code compiles, the compiler will always reserve that amount of memory by usin stdint
    // To see standard libraries go to location of your compiler in my case MingW ==> include  \\ here you can see all standard libraries (.h files) 
    // This stdint.h file is different for different compilers! Because for PIC int16_t is assigned to int, but for ARM int32_t is assigned to int. (assigned means defined as allias to this!)
    // MingW ==> bin file has the binaries (.exe) files that we use during our code compilation!
    // For CubeIDE ST ==> STmCubeIDE_1.0.1 ==> STMCubeIDE ==> Plugins ==> externaltools.gnu-arm... ==> tools ==> arm-none-eabi ==> include for standard .h files!

    // Some other usefull stdint aliases:
    uintmax_t a2; // defines the largest fixed width unsigned integer possible on the system.
    intmax_t a2; // defines the largest fixed width signed integer possible on the system.
    uintptr_t a2; // defines a unsigned integer type that is wide enough to store the value of a pointer. (for 64 bit systems max pointer 8 bytes (64 bits))

}