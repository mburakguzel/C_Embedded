/*
 * Pointers.c
 *
 *  Created on: 31 jul. 2022
 *      Author: nlbguz
 */

# include <stdio.h>   


int main()     			
{
    // Pointers are heavily used in embedded systems in order to talk to peripherals, read data from peripherals, write data to peripherals, to configure the peripheral, to store a data in some RAM location.
    // Pointer is the address of the memory location.
    // On 64 bits machines pointers occupies 8 bytes but for 32 bit machines it allocates 4 bytes no matter which variable data type it is.
    // During varable decleration asteriks(*) is used to differentiate between a pointer varable decleration and a non pointer variable declaration.
        // char*, int*, long long int*, float*, double*
        // unsigned char*, unsigned int*, unsigned long long int*, unsigned float*, unsigned double*
    // If all pointer types occupies 8 bytes, why it is important to define a pointer type:
        // The pointer data type decides the behaviour of the operations carried out on the pointer variable.
        // Such as: read, write, increment, decrement. This allows compiler to understand how many bytes of data should be read or written to the varable pointed by the pointer.
    // char* address1 = 0x00007FFF8E3C824;           // 0x00007FFF8E3C824 is number which occupies 8 bytes, 2 for each! BUT THIS IS NOT PROPER WAY OF DEFINING 
    char* address1 = (char*) 0x00007FFF8E3C3824;     // Explicit casting!! Now compiler consider RHS(right hand side) as a pointer. THIS IS A VALID POINTER DEIFINITION. Compiler allocates 8 bits for this pointer.
    // char *address1 = (char*) 0x00007FFF8E3C3824;     // Also works! Use this syntex!
    // If you try to assign a pointer to a different type of varable, compiler generates warning, not error. But it is not suggested because:
    long long int g_data = 0xFFFEABCD11112345;
    char *pAddress1 = (char*)&g_data;
    printf("Value at address %p is : %x\n", pAddress1, *pAddress1);  // will show only 1 byte of the long long int (in this case 45!) since pointer is defined as char!!

    pAddress1 = pAddress1 + 1;
    
    printf("Value at address %p is : %x\n", pAddress1, *pAddress1);  // This time we will se the next byte, shows the next byte`s address and 23 since it is the data stored in the next address!
    // However if you define the pointer as short, it will show 2 bytes not one byte. And when you increment the pointer by 1, it will increment two becasue next data is stored in the next two bytes.
    // Or if you define the pointer as int, it will show 4 bytes not one byte. And when you increment the pointer by 1, it will increment 4 becasue next data is stored in the next two bytes.
    short *pAddress2 = (short*)&g_data;
    printf("Value at address %p is : %x\n", pAddress2, *pAddress2);
    pAddress2 = pAddress2 + 1;                  // increases the address by two. This is how the pointer type effects the arithmatic opeations!
    printf("Value at address %p is : %x\n", pAddress2, *pAddress2);



    // Read and write data from pointer can be done but dereferencing it:
    char data = *address1;  // This is called dereferencing.
    *address1 = 0x89;       // This is called dereferencing. 

    /* Exercise video 80
    char data = 100;
    printf("Address of varable: %p\n", &data);
    char* pData = &data;
    char data1 = *pData;
    printf("Address of varable: %d\n", data1);   // if %c, shows ASCII equivalent of 100!
    *pData = 65;                                 // Hre we are assigning 65 to data by using its pointer!                                
    printf("Address of varable: %d\n", data);    // Shows 65 since we write to the pointer (memory address of data)
    */

//    Pointers are quite important in embedded programing:
    // Since they are used to store data into required SRAM location.
    // To copy data from peripheral register to SRAM memory or visa versa. In embedded systems we talk to the peripherals by using their addresses.
    // Peripheral registers are memory-mapped and each register will be given unique address in the MCU memory map. To configure peripheral register, we use pointers.
    // Pointers to ISRs (Interrupt Service Routine) are stored in a vector table to handle the interrupts.
    // Pointers are also used to configure the memory-mapped processor specific registers like interrupt configuration registers.

}