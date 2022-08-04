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
        // You can not define a member with data type as same struct:
        // struct CarModel carBMW;   // not allowed!
        // However, structure types can contain pointers to their own type.
        struct CarModel *pcarBWM;  // allowed!
        // Nested structs are also possible.
        struct 
        {
            char data5;
            int data6;
        }moreData;
    };

    struct DataSet    // This is how we define structures. Definiton of a structure does not consume any memory, it is just a description or a record.
    {                 // This is usually created outside of the function or even in a header file. Best practise is defining in header file!!
        char  data1;
        int   data2;
        char  data3;
        short data4;
    };

    void displayMemberElements(struct Dataset *pData);

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

        /* In order to store unaligned add the below statement at the end of the structure. 
        struct DataSet   
        {                 
            char  data1;
            int   data2;
            char  data3;
            short data4;
        };__attribute__((packed));
        
        */

    //    In assembly code:
        // STRB ==> store a byte   these commands stores data aligned 
        // STR  ==> store a word

    // Typedef with syructure:
    // typedef is used to give an alias name to primitive and user defined data types.
    // While calling a struct your code, you always need to write struct struct_name ..., however when you use typedef using only struct's name is enough see below codes: 

    struct CarModel   // This is how we define structures. Definiton of a structure does not consume any memory, it is just a description or a record.
    {                 // This is usually created outside of the function or even in a header file. Best practise is defining in header file!!
        unsigned int carNumber;
        uint32_t carPrice;
        uint16_t carMaxSpeed;
        float carWeight;
    };
    // in main.c
    // struct CarModel carBMW;

    // with typedef:
    typedef struct   
    {                
        unsigned int carNumber;
        uint32_t carPrice;
        uint16_t carMaxSpeed;
        float carWeight;
    }CarModel_t;    
    // in main.c
    // CarModel_t carBMW;   // alias name for the structure! _t is used for distinguishing enum and type for programmers (so not mendatory!). For enums we use _e!
    // If you open the MCU's header file, you will see lots of typedef structure.

    // STRUCTURES AND POINTERS:
    // Let's say we define a pointer with the base address of a struct:
    // uint8_t *ptr = (uint8_t*)&data;   // ptr has the base address (Address of first byte of the data!)

    // Modify first element of data structure:
    // *ptr = 0x55;

    // To Modify second element of data structure becomes hustle since, you do not know how many times you need to increment ptr because of the data type of second element is different.
    // So instead of this define a struct pointer! BURDAN ASAGISI BENDE CALISMADI! VIDEO 161-162-163 TEKRAR IZLE!!!
    struct DataSet newdata;
    newdata.data1 = 0x11;
    newdata.data2 = 0xFFFFEEEE;
    newdata.data3 = 0x22;
    newdata.data4 = 0xABCD;

    struct Dataset *pData;  // pData is a pointer variable of type struct DataSet.

    pData = &newdata;   // pData now holds the address structure of data1 element.

    // Change the value of first element data1:
    pData->data1 = 0x55;   // -> is called dereferencing (arrow) operator when a structure pointer is involved. Use this operator ONLY when structure pointer is involved!
    // Above statement is actually same with *ptr = 0x55;
    // We use . operator when a non pointer type variable is involved.

    // To modify second element of struct:
    pData->data2 = 0x11;  // you do not have to calculate the address of the second element to increment the pointer!

    // Why we need to modify the value of struct's element via pointer. Because most of the time, you will be sending the address of the structure variable to some another function, and that function has to receive your address
    // and manipulate the member elements. See displayMemberElements function given out of the main(). 
    */

   displayMemberElements(&data);

    // STRUCTURE BIT FIELDS!    (HEAVILY USED WHEN YOU DEAL WITH NETWORKING ACTIVITIES IN A CODE!)
    // Also can be used when you know the max value of a struct element. So lets say max amount of speed is 500 you can define speed element with 7 bits which is sufficient to store till 500.
    // In the previous example we extracted a package with 4 bytes, however we used 10 bytes to extract them. This is waste of memory!
    // For example we created crc as uint8_t(8 bits) but we only used two bits for crc. In order to prevent this we can use bit fields:
    // Define the struct: Define all variables with 32 buts since our packed consume 32 bits in total!
    struct Packet
    {
        uint32_t crc        :2;    // we tell compiler that use only two bits for crc
        uint32_t status     :1;    
        uint32_t payload   :12;
        uint32_t bat        :3;
        uint32_t sensor     :3;
        uint32_t longAddr   :8;
        uint32_t shortAddr  :2;
        uint32_t addrMode   :1;
        // All these variables will be referring to different bit fields of single uint32_t memory!!!. We reduced the memory consumption.
    }
   
    return 0;
}

void displayMemberElements(struct Dataset *pData)
{
    printf("data1 = %X\n", pdata->data1);
    printf("data2 = %X\n", pdata->data2);
    printf("data3 = %X\n", pdata->data3);
    printf("data4 = %X\n", pdata->data4);
}