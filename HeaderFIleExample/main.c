/*
 * main.c
 *
 *  Created on: 28 jul. 2022
 *      Author: nlbguz
 */


# include <stdio.h> 
# include "math.h"  	// This is how we include a user defined header file! <> can not be used with user defined header files!
int main(void)     			
{

    printf("Add : %d\n,", math_add(10,12));
    printf("Add : %d\n,", math_sub(10,12));
    printf("Add : %d\n,", math_mul(10,12));
    printf("Add : %d\n,", math_div(10,12));

    return 0;
}