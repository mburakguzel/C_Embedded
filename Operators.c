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
    // Assignment Operators:
        // =, +=, -=, *=, /= , %=

    // Ternary Operators: Requires three operands. 
    // Conditional Operators:
        // ?:

    // To see the precedence(oncelik) of the operators, check internet. However, using paranthesis is also okay. You do not need to know precedence.
    // * and / have precedence, then associatiativity comes in place, it goes from left tot right. Whatever comes first will be processed first! 
}