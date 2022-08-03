/*
 * While.c
 *
 *  Created on: 03 Aug. 2022
 *      Author: nlbguz
 */

# include <stdio.h>   
# include <stdint.h> 	

int main(void)     			
{
    // Multiple statements while loop
    uint8_t i = 1;
    while (i < 10){
        printf("%d\n", i++);
    }

    // Single statement while loop 
    i = 0;
    while (i < 10)
        printf("%d\n", i++);

    // if you enter a semicolon after while (), compiler generates only warning! But program does not execuate the while loop!

    // while (1);   // program hangs continuesly here! Also called forever loop or infinity loop!
    // It is common to see this in an embedded application in the main program. Unlike a PC program, an embedded program may just run forever (or as long as it is powered up!)

// DO - WHILE LOPP
	// First executes the statements under do then checks the condition in while and run the code again depends on if the condition is satisfied.
	i = 0;
    do{
		printf("i = %d\n", i++);
	}while(i < 3);
    // Do-while loop is used a lot to write multiline C macros in a header file. 

    // Watch Video130 again and try to write the code!!
}