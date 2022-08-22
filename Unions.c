// A union in C is similar to a structure except taht all of its members start at the same location in memory.
// A union varable can represent the value of only one of its members at a time.
// Let's say you have a structure called address and you have 2 member elements as shown below. 
struct address 
{
    uint16_t shortAddr;   // 2 bytes + 2bytes padding
    uint32_t longAddr;    // 4 bytes, 8 bytes in total 
};

union address   // There will be only for bytes allocated! The memory consumed by a union is equal to the size of its biggest member element.
{               // Use unions instead of structure to save memory when access to its member element is mutually exclusive (ozel, tek, biricik)
                // For example, let's say you are sending one packet from transmitter to receiver. So, you either send the packet using long address or short address.
    uint16_t shortAddr;
    uint32_t longAddr;    
};

// Example:

#include<stdint.h>
#include<stdio.h>

union Address
{
	uint16_t shortAddr;
	uint32_t longAddr;
};

int main(void)
{

	union Address addr;

	addr.shortAddr = 0xABCD;    // dereference the addr variable to set the value 
	addr.longAddr = 0xEEEECCCC;

	printf("short addr = %#X\n",addr.shortAddr);
	printf("long addr = %#X\n",addr.longAddr);

	getchar();

	return 0;

}

// APPLICABILITY OF UNIONS IN EMBEDDED SYSTEM CODE:
// Unions are used for two reasons:
	// 1) Bit extraction
	// 2) Storing mutually exclusive data thus saving memory.

// IDE EXAMPLE
#include<stdint.h>
#include<stdio.h>

/*
 * This structure we used to store various fields of the packet in to variables
 * The variable of this structure consumes 4 bytes in the memory
*/
union Packet
{
	uint32_t packetValue;

	struct    // creating a struct with bitfields in the union
	{         
		uint32_t crc			:2;
		uint32_t status			:1;
		uint32_t payload		:12;
		uint32_t bat			:3;
		uint32_t sensor			:3;
		uint32_t longAddr		:8;
		uint32_t shortAddr		:2;
		uint32_t addrMode		:1;
	}packetFields;   // Creating a variable of a strucure (like this) is discouraged. But if you use a struct inside of a union or inside of a struct, it is fine.

};


int main(void)
{

   union Packet packet;    // Taking 32 bit packet value
   printf("Enter the 32bit packet value:");
   scanf("%X",&packet.packetValue);

	// Below process can also be done by using bitwise operations. But here we are using the combination of union and a struct to perform this.
   printf("crc      :%#x\n",packet.packetFields.crc);
   printf("status   :%#x\n",packet.packetFields.status);
   printf("payload  :%#x\n",packet.packetFields.payload);
   printf("bat      :%#x\n",packet.packetFields.bat);
   printf("sensor   :%#x\n",packet.packetFields.sensor);
   printf("longAddr :%#x\n",packet.packetFields.longAddr);
   printf("shortAddr:%#x\n",packet.packetFields.shortAddr);
   printf("addrMode :%#x\n",packet.packetFields.addrMode);

   printf("Size of union is %I64u\n",sizeof(packet));



   while(getchar() != '\n');
   getchar();

	return 0;

}

