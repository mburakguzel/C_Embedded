/*
 * Switch.c
 *
 *  Created on: 02 Aug. 2022
 *      Author: nlbguz
 */

# include <stdio.h>  
# include <stdint.h>   


int main(void)     			
{
    uint8_t input;
    printf("Please enter 1 or 2:\n");
    scanf("%d", &input);
    switch (input)
    {
        case 1:   // no need to use curlies!
            printf("You entered 1.");
            break;   // breaks the body, if you do not enter this program will still check other cases!
        case 2:
            printf("You entered 2.");
            break;
        // case 'c': // if you get a char from user add it to case with ''
        default:
        printf("You entered something different than 1 or 2.");
    }

}