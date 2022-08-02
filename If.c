/*
 * Pointers.c
 *
 *  Created on: 02 Aug. 2022
 *      Author: nlbguz
 */

# include <stdio.h>  
# include <stdint.h>   


int main(void)     			
{
    // Single statement executaion:
        int a = 1;
        if (a)   // if you put a semicolon here compiler wil not generate an error but do not execuate if!
            printf("a = %d\n",a);   // indentation (taba basit sagdan baslamak C'de zorunlu degil, ama kodumuzu daha anlasilir yapar. Python'da zorunlu!)
    
    // Multiple statement executaion:
        char a1 = 1;
        if (a1){
        // { putting the curly here also okay!
            a1 = 0;   // We can also put an empty block or a block with only ; (semicolon!)
            printf("a1 = %d\n",a1);
        }

        // IF - ELSE also works with single statement but I will use multiole one!
        char a2 = 0;
        if (a2){
            a2 = 0;   // We can also put an empty block or a block with only ; (semicolon!)
            printf("a2 = %d\n",a2);
        }
        else{
            printf("a2 is not 1");
        }

        // IF - ELSE ILF

        char a3 = 0;
        if (a3 == 0){
            a3 = 0;   // We can also put an empty block or a block with only ; (semicolon!)
            printf("a3 = %d\n",a3);
        }
        else if (a3 == 1){
            printf("a3 is 1\n");
        }
        else {
            printf("a3 is differnet than 1 or 0\n");
        }
        
        // CONDITIONAL OPERATOR

        uint32_t a4 = (5 + 4) ? (9 - 4) : 99;   // first checks if (5 + 4) is true if yes a4 = (9-4)  Anything nonzero is true!
                                                                                //if not a4 = 99   
        uint32_t a5 = (5 - 5) ? (9 - 4) : 99;   // first checks if (5 - 5) is true if yes a4 = (9-4)  Anything nonzero is true!
                                                                                  //if not a4 = 99 
                                                
        printf("a4 = %d\n", a4);
        printf("a4 = %d\n", a5);

    

}