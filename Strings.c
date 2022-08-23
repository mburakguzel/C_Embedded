/*
 * Strings.c
 *
 *  Created on: 04 Aug. 2022
 *      Author: nlbguz
 */

# include <stdio.h>   
# include <stdint.h> 
# include <string.h>



int main(void)     			
{
    // A string is nothing but collection of characters terminated by a null character.
    // A null character is used to indicate end of a string.
    // Unlike C++, Java, Python, C does not have any dedicated data type to store string data. In C we we use arrays to store strings.

    char message [] = "Hello";    // but in memory it will be stored as H e l l o \o(null char)! So, it consumes 6 bytes in memory!
    char message1 [] = {'h', 'e', 'l', 'l', 'o', '\0'};  // another way of defining strings!

    printf("My message is: %s\n", message);
    printf("Address of 'message' variable is: %p\n", &message);     // shows base address of message
    printf("Value of 'message' vaiable is: %p\n", message);         // also shows base address of message

    char message2 [] = {'h', 'e', 'l', 'l', 'o'};  // this is not a string. We are just storing chars in array here!
    
    char message3 [10] = "Hello";  // first 5 will be hello, others will be /0

    sizeof(message);      // will show 6 including null
    strlen(message);      // function exists in c standard library. Will show 5! Include <string.h> to use this command!

    char message4[] = "A"; // this is a string there will be A and \0
    // char message5[] = 'A'; // this is an array with one char!!! NOT STRING! Ther will be only A!

    // Getting a string as input:
    char name [30];
    printf("Enter your name: ");
    scanf("%s", name);                  // it can not read the characters after the white space. Whne you enter Burak Guzel, it shows only Burak. This is because scanf ignore white space \n char. Remember when you enter multiole integers by using space, it was getting the ints right? not the space!
    // Instead we can use below code:
    char lname [30];
    printf("Enter your name: ");
    scanf("%s %s", name, lname);                  
    printf("Hi, %s %s\n", name, lname);        
    // OR use scanset function of scanf:
    char fullname [30];
    printf("Enter your name: ");
    // scanf("[^s]s", fullname);                  // reads all the string untill it finds a 's' in string!
    scanf("[^\n]s", fullname);                    // We will use new line character instead!
    printf("Hi, %s\n", fullname);  



    // STRING LITERAL (STRING CONSTANT)
    // char *mesage6 = "hello";    // also a valid method to store strings in our program! Compiler will allocate some memory to this string literal and compiler stores the base address of that message into the character pointer here.
                                   // This is called as string literal (constant), since it can not be modified.
        
    // The difference between char message [] = "Hello"; and char *mesage6 = "hello"; is:
        // char *mesage6 = "hello"; This string is stored in read only memory (ROM).
        // char message [] = "Hello"; However, this is stored in RAM (randomly accesable memory.). I can modify the this but I can not modify the statement given above.
        // message6 [1] = 's';  This can not be done! You are trying to modify a variable lies in the ROM.
        // message [1] = 's'; Can be done!
        // To see where a variable is stored in cubeIDE: window ==> show view ==> variables 
        // NOTE: RAM starts form 0x200!
        // To see the variable and its address in cubeIDE: window ==> show view ==> Memory browser 
        // Normal Strings:
            // Global variables are stored in the data memory throughout the lifespan of the program.
            // But since our string is local variable, it is not needed to store it data memory permanently throughout the lifespan of the program.        
            // So, during execution of the program it is copied from flash memory (permanent memory - code memory) into this array (RAM). This is not done by the startup code. This is done by function executation (in this case main(), since the variable message is local not global!)
            // After, the fucntion execution is done, it will be deleted from RAM.
            // This variable (message) is actually created in stack memory of the RAM.
            // RAM consists of 3 parts: global data, stack and heap (for dynamic memory allocation!).
            // When the function is called all local variables are created in stack. When the program exits, all these memories will be reclaimed.
            // Stack will be tracked by the stack pointer register of the processor.
            // Whenever the variables are created in stack, the stack actually decrements. Whenever variables are destroyed a stack pointer will reclaim those memory addresses. So, dynamically stack will shrink and expand.
            // When we download our program binaries to flash memory, our string also is stored there with binaries.
            // Since our message variable is local, it will be copied from flash to stack when thefunction is called. 
            // In case there is a global variable, startup code would copy the global from flash to global data part of the RAM. This happens before the main, startup code performs this!
            // So when we modify message variable, we actually modify the copied one in RAM not the one in Flash!! You can not jus change the contents of the flash using your pointer access.
        // String Literal:
        char *message6 = "hello";    // in this case this is not pointing to copied data to RAM, but it points to the string stored in binaries in Flash memory.
        
        printf("My message is: %s\n", message6);
        printf("Address of 'message6' variable is: %p\n", &message6);     // shows the RAM address, where the string is copied from flash to RAM.
        printf("Value of 'message6' vaiable is: %p\n", message6);         // This shows the address in Flash
        // That is why we can not perfor below statement. Because we are trying to reach to the FLASH memory.
        // message6 [1] = 'S';   // if we try to run this on our host machine, program may even crash! On MCU, it only ignores this statement.
    
    
    return 0;

}

// DO EXERCISE ON VIDEO 189