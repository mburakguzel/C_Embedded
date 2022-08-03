/*
 * For.c
 *
 *  Created on: 03 Aug. 2022
 *      Author: nlbguz
 */

# include <stdio.h>   
# include <stdint.h> 	

int main(void)     			
{
    for(uint8_t i=0; i <= 10; i++){   // statemnts inside paranthesis are not mendatory but semicolons(;) are mendotory.
        printf("i = %d\n", i);
    }

    // Video 133 - 135 tekrar izle ve yap!

    // In our program we can create delays with two features:
        // Hardware: Use timers of MCU.
        // Software: use loops (while or for) to create a delay. Keep processor busy with software loop doing nothing. Not suggested!
            // However, this method is not an accurate method to obtain the desired time delay.
}