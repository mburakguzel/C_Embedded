/*
 * Pointers.c
 *
 *  Created on: 02 Aug. 2022
 *      Author: nlbguz
 */

# include <stdio.h>   


int main()     			
{
    // Unary operators (Increment - decrement): Since these requires only one operand, these are called unary operators.
        int a1 = 0;
        int a2 = 0;
        a1++;     
        ++a1;   // Also works but a bit different.  
        a2 = a1++;  // assume both started wit 0, a2 will be 0, a1 will be 1. (this is called postincrementin, first assigns a1 to a2 than increments a1)
        a2 = ++a1;  // assume both started wit 0, both will be 1 (this is called preincrementing, first increments a1, than assigns a1 to a2)
        a1--;
        // Can also be used with pointers.
        int *pAdress1 = &a1;
        pAdress1++;
    
    // Binary Operators: Requires two operands. All below are binary operators: 
    // Aritmatic Operators:
        // +,-,*,/,%
        // % is modulus operator, returns reminder.
    
    // Relational Operators:
        // <, <=, >, >=, ==, !=

    // Logical Operators:
        // &&, ||, !

    // Bitwise Operators:
        // &, |, <<, >>, ~, ^
        // << bitwise left shift!
        // ~ bitwise not!
        // ^ bitwise XOR!
        // Lets say that A = 0 0 1 0 1 0 0 0
        //               B = 0 0 0 1 1 1 1 0
        //           A & B = 0 0 0 0 1 0 0 0 
        // However A && B = 1, since both A and B are nonzero!
        // Lets say that A = 0 0 1 0 1 0 0 0
        //              ~A = 1 1 0 1 0 1 1 1        C = ~A also possible!
        // 
        // Lets say that A = 0 0 1 0 1 0 0 0
        //               B = 0 0 0 1 1 1 1 0
        //           A ^ B = 0 0 1 1 0 1 1 0 
        // Bit masking: is a teqnique in programming used to test or modify the states of the bits of a given data.
            // This is the number we want to check:                         0 0 1 0 1 0 0 0
            // Mask: Set the nth bit of 1 and rest 0 ant use bitwise and:   0 0 0 0 0 0 0 1 we are checking the right most bit! When compare the two numbers, we will understand whether 1st bit of number is 1 or 0.
            // Example: (number & 1) this checks the right most bit since 1 = 0 0 0 0 0 0 0 1
            // & is used to test, | is used to set bits:
                // Lets say that A = 0 0 1 0 1 0 0 0
                //               B = 0 0 0 1 1 1 1 0   if nth bit of B is 1 the result also be 1, we are stting bits!
                //           A | B = 0 0 1 1 1 1 1 0 
            // & can also be used to clear! Using & and ~ together also another method. Learn how to apply this method.
                // Lets say that A = 0 0 1 0 1 0 0 0
                //               B = 0 0 0 1 1 1 1 0   You are setting each nth bit of result to 0 by using zero in that bit in B.
                //           A & B = 0 0 0 0 1 0 0 0 
            // ^ can be used to toggle bits by using more once
                    // Lets say that A = 0 0 0 0 0 0 0 1
                    //               B = 0 0 0 0 0 0 0 1   You are setting each nth bit of result to 0 by using zero in that bit in B.
                    //           A ^ B = 0 0 0 0 0 0 0 0 
                    // Next turn     A = 0 0 0 0 0 0 0 0
                    //               B = 0 0 0 0 0 0 0 1   You are setting each nth bit of result to 0 by using zero in that bit in B.
                    //           A ^ B = 0 0 0 0 0 0 0 1   Continues like this!
    // First bit of a bite is least significant bit, last bit of a byte is most significant bit.

    // Bitwise shift operators:
        // operan1 >> operand2 // bits of the 1st operand will be right shifted by the amount decided b the 2nd operand. Example:
        char a6 = 111;        //                  a7 = 0 1 1 0 1 1 1 1 = 111 =  2^6 + 2^5 + 2^3 + 2^2 + 2^1 + 2^0
        char a7 = a6 >> 4;    // first shift: a6 >> 1  0 0 1 1 0 1 1 1   a >> 4 means, a will be shifted 4 times!
                             // second shift: a6 >> 2  0 0 0 1 1 0 1 1 
                             // third shift:  a6 >> 3  0 0 0 0 1 1 0 1
                             // fourth shift: a6 >> 3  0 0 0 0 0 1 1 0
        // Some process with left shift <<
        // When left shif is implemented the value will be incresed (value will be multiplied by 2 for each shift) while in right shift value will decrease (value will be devided by 2 for each shift)!
        // Bitwise shift operators are very ,uch helpful in bit masking of data along with other bitwise operators.
        // Mostly used for setting or clearing of bits. Example: set 4th bit of given data:
            // First method use a mask value with bitwise or
            // Second method: Take number 1 (0 0 0 0 0 0 0 1) and left shift it 4 times! This is the recommended method 0 0 0 1 0 0 0 0 = 0 0 0 0 0 0 0 1 << 4
        // Example clear 4th bit:
            // First method: Use & operator with a mask!
            // Second method: Take number 1 (0 0 0 0 0 0 0 1), shift 4 times and use bitwise and and not operators to clear 4th bit: data = data & ~(1 << 4). Use this one!
        // Bit extraction: Example: Extract bit positions from 9th to 14th in a given data and save it in to another variable.
            // Lets say we have data 1 0 1 1 0 1 0 0 0 0 0 1 0 0 0 0 = 0xB410 (each digit represents 4 bits)
            // The bits from 9 to 14 will be extracted (0 1 0 1 1 0)
            // Shift the identified portion to right hand side until it touches the least significant bit(0th bit)
            // Mask the value with bitwise and& to extract only 6 bits (0 to 5) and then save it into another variable.
            uint16_t Data = 0xB410;
            uint8_t output;
            output = (uint8_t) ((Data >> 9) & 0x003F);


    // Assignment Operators:
        // =, +=, -=, *=, /= , %=

    // Ternary Operators: Requires three operands. 
    // Conditional Operators:
        // ?:
    // CONDITIONAL OPERATOR

        uint32_t a4 = (5 + 4) ? (9 - 4) : 99;   // first checks if (5 + 4) is true if yes a4 = (9-4) Anything nonzero is true!
                                                                                //if not a4 = 99   
        uint32_t a5 = (5 - 5) ? (9 - 4) : 99;   // first checks if (5 - 5) is true if yes a4 = (9-4) Anything nonzero is true!
                                                                                  //if not a4 = 99 
                                                
        printf("a4 = %d\n", a4);
        printf("a4 = %d\n", a5);


    // To see the precedence(oncelik) of the operators, check internet. However, using paranthesis is also okay. You do not need to know precedence.
    // * and / have precedence, then associatiativity comes in place, it goes from left tot right. Whatever comes first will be processed first! 





}