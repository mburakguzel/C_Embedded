/*
 * Arrays.c
 *
 *  Created on: 04 Aug. 2022
 *      Author: nlbguz
 */

# include <stdio.h>   
# include <stdint.h> 

void array_display(uint8_t const *const *pArray, uint32_t nItems);

int main(void)     			
{
    uint8_t studentsAge[100];  // defining an array.
    // Here studensAge is a reference or pointer to base address of array. Therefore, data typeof studentsAge is uint8_t* not uint8_t!! See below statemnent studentAge shows base address of array (same in C++);
    printf ("Base address: %p\n", studentsAge);
    // Data type of items stored is uint8_t.
    // We can use sizeof operator to see size of an array.

    // ARRAY READ AND WRITE:
    uint8_t someData[10] = {0xff, 0xff, 0xff}; // only first three elemnts are initilized. The others will be initialized to 0 automatically.
    uint8_t someData1[] = {0xff, 0xff, 0xff};   // This is also fine, compiler will generate an array with 3 elements!
    // uint8_t someData[];             // This will cause error!

    int len = 4;
    uint8_t someData2[len];   // length can change during code execution. This is called VLA (variable lengt array). Introduced with C99 standard. Not possible in C++, array size can not change in C++. 
    // To change standard in CubeIDE right click to project ==> properties ==> Expand C/C++ Build ==> Settings ==> Dialect (GCC C Compiler) ==> Language Standard
    // Then go to warnings (GCC C Compiler) ==> Enable Pedantic (-pedantic)

    *(someData + 1) = 20; // to write a new value to second data item! This is why indexing starts from 0.
    // Shorthand method;
    someData[1] = 20;     // to write a new value to second data item! Indexing starts from 0.
    printf("2nd element of array: %d\n", someData[1]);
    printf("someData: ");

    // To write all elements of array:
    for(uint32_t i=0; i < 10; i++){
        printf("%x\t", someData[i]);
        someData[i] = 0x33;
    }
        
    printf("\n");
    // Passing array to a function:
    uint8_t const *const someData3[4] = {33, 33, 33, 33};
    // uint32_t nItems = sizeof(someData3) / sizeof(uint8_t);
    array_display(someData3, 4);
    // array_display((someData3+2), 2); // starting from 2nd element!
    // array_display(&somedata[2], 2); // starting from 2nd element!


    return 0;

}

void array_display(uint8_t const *const *pArray, uint32_t nItems)
{   printf("someData3: ");
    for(uint32_t i=0; i < nItems; i++){
        printf("%u\t", *(pArray + i)); 
    }
    printf("\n");
    
    printf("someData3: ");
    for(uint32_t i=0; i < nItems; i++){
        printf("%u\t", pArray[i]);         // bots statemens are same!
    }

    // Why my program generates warnings? Find it!
    // Watch video 182-183!
           
}