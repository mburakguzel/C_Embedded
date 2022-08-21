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