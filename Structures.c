/*
 * Structures.c
 *
 *  Created on: 03 Aug. 2022
 *      Author: nlbguz
 */

# include <stdio.h>   
# include <stdint.h> 	

    struct CarModel   // This is how we define structures. Definiton of a structure does not consume any memory, it is just a description or a record.
    {                 // This is usually created outside of the function or even in a header file. Best practise is defining in header file!!
        unsigned int carNumber;
        uint32_t carPrice;
        uint16_t carMaxSpeed;
        float carWeight;
    };

    struct DataSet   // This is how we define structures. Definiton of a structure does not consume any memory, it is just a description or a record.
    {                 // This is usually created outside of the function or even in a header file. Best practise is defining in header file!!
        char  data1;
        int   data2;
        char  data3;
        short data4;
    };

int main(void)     			
{
    // Structure is a data structure used to create user-defined data types in C.
    // Structures allow us to combine data of different types.   
    // Structure is a record where we combine data of different data types.


    // Variables of a Structure
    // struct CarModel CarBMW, CarFord;    // Memory will be consumed when you create structure variables.
    // What is the type of above variables, data type is struct CarModel! A user defined data type!
    // Each variable consumes the total amount of the memory of elemnts defined in CarModel above. 14 bytes in this case. (4+4+2+4)
    
    // Initialize Structure:
    // struct CarModel carBMW = {2021, 15000, 220, 1330};        // the order must be in the same order given in struct definition above!
    struct CarModel carFord = {4021, 35000, 160, 1900.96};    // This method is also called as C89 method.
    // Another Initialize Method introduced in C99:
    struct CarModel carBMW = {.carNumber=2021, .carPrice=15000, .carMaxSpeed=220, .carWeight=1330}; // The order is not important. We used designated initializers with . operator

    // Accessing Structure Member Elements
    // Use a . operator to access structure elements:
    printf ("Details of car BMW is as follows:\n");
    printf ("carNumber  =  %u\n", carBMW.carNumber);
    printf ("carPrice  =  %u\n", carBMW.carPrice);
    printf ("carMAxspeed  =  %u\n", carBMW.carMaxSpeed);
    printf ("carWeight  =  %f\n", carBMW.carWeight);
    
    // Modify initialized member element:
    carFord.carMaxSpeed = 5021;

    // Structure padding:
    printf("Size of struct carModel is %I64u\n", sizeof(carBMW));           // both works but prints 16. we said our member would consume 14. This is called Struct padding.
    printf("Size of struct carModel is %I64u\n", sizeof(struct CarModel));  // If your struct has only one element, this command shows the correct value. But if you have more than 1, it shows more than it should.

    // Aligned and unaligned data access:
    // For efficiency, the compiler generates instructuions to store variables on their natural size boundary addresses in the memory.
    // This is also true for structures. Member elements of a structure are located on their natural size boundary. 
    // Natural sizes of data types:
        // Char = 1 byte (adress would end with 0403010, 0403011, 0403012)          This is the natural size boundaries for char
        // Short = 2 bytes (adress would end with 0403010, 0403012, 0403014)        This is the natural size boundaries for Short
        // Int = 4 bytes (adress would end with 0403010, 0403014, 0403018)          This is the natural size boundaries for Int
    // When you compile the code, the compiler generates the instructions to store the variables in memory according to the variables natutal size boundary, and that waht we call as align data storage.
    
    struct DataSet data;
    data.data1 = 0x11;
    data.data2 = 0xFFFFEEEE;
    data.data3 = 0x22;
    data.data4 = 0xABCD;
    
    uint8_t *ptr;
    ptr = (uint8_t*)&data;     // struct DataSet
    uint32_t totalSize = sizeof(struct DataSet);

    printf("Memory address        Content \n");
    printf("==============================\n");

    for(uint32_t i = 0; i < totalSize; i++){
        printf("%p     %X\n", ptr, *ptr);   // we are printing the address and data in it, one by one. 
        ptr++;
    }
    
    printf("Total memory consumed by this struct variable = %I64u\n", sizeof(struct DataSet));
    // Output of the above code: THIS IS CALLED ALIGNED DATA STORAGE!
        // 000000000064FDE4     11   // This is base address of struct and first element is stored.
        // 000000000064FDE5     0    // However, second element is not stored here! Becouse compiler stored the variable according to its natural size boundary.
        // 000000000064FDE6     0    // By natural size boundary it means the how the address ends normally. For integers it ends 0, 4, 8, C. So it will start storing from address ending with 8. 
        // 000000000064FDE7     0    // These three bytes are waste!
        // 000000000064FDE8     EE   // Here storage of int started!
        // 000000000064FDE9     EE
        // 000000000064FDEA     FF
        // 000000000064FDEB     FF
        // 000000000064FDEC     22   // Car can be stored in any memory because it consumes only 1 byte.
        // 000000000064FDED     0    // Also waste
        // 000000000064FDEE     CD   // Again short short should be stored starting from (0,2,4,8,A,C,E)
        // 000000000064FDEF     AB
        // Total memory consumed by this struct variable = 12 (should be 8 normally!) 8 + 4 waste.

        // Aligned data storage is better than unaligned. Because processor can do read and wite transactions with the memory easier. Processor performance is increased with aligned data storage.
        // Unaligned data storege increases code volume.
        // But aligned data storage also causes losing some meory as shown above.
        // If your resources are really limited, then use packed feature of compiler to store data unaligned.


   
    return 0;
}