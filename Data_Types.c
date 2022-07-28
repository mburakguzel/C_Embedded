/*
 * Print_Output.c
 *
 *  Created on: 27 jul. 2022
 *      Author: nlbguz
 */

# include <stdio.h>   	
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
}