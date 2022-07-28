/*
 * Functions.c
 *
 *  Created on: 28 jul. 2022
 *      Author: nlbguz
 */

# include <stdio.h>  

int main()    
{
    // Typecasting is a way of converting a variable or data from one type to another data type.
    // Data will be truncated (kirpilmak) when the higher data type is converted in to lower.
    // There are two types of casting:
        // Implicit casting (compiler does this, also called assumed casting)
        // Explicit casting (programmer does this)
    // Example:
    unsigned char data = 0x87 + 0xFF00;   // here both 0x87 and 0xFF00 are considered as an integer by compiler. So it occupies 4 bytes. This is also called as integer promotion.
                                          // However, char allocates 1 byte. This causes a conflict!
                                          // Compiler did a implicit casting twice here:
                                            // 1) it promotes the data sizes of RHS constants to int.
                                            // 2) And converting int to char to assign it to a char! May cause data loss.
    
    // unsigned char data = (unsigned char) (0x87 + 0xFF00);   // in order to solve above conflict we can use type casting as we did here. This is called explicit typecasting.
    
    float result = 80 / 3;   // Int/Int will generate int, we will loose some data!
    float result = (float)80 / 3;   // The fraction part will be lost here! Three will be promoted to float implicitly.

    printf("Data: %u result : %f\n", data, result);
}