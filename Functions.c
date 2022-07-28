/*
 * Functions.c
 *
 *  Created on: 28 jul. 2022
 *      Author: nlbguz
 */

# include <stdio.h>  

void function_add_numbers(int a, int b, int c); // declaring prototype of a function, without this compiler generates warnings and this can caouse problems in our code!
int function_add_numbers1(int , int , int );    // This is also fine! Without function protype, compiler just assumes what your function is like and these creates conflicts with your real function.

// int main (int argc, char* argv[]) // other way of defining main function!
int main()    // Main function can have zero or two arguments (parameters). However, in embedded systems we do not use them. There are no command-line arguments in embedded systems! 
{             // Defining main function as void, triggers warnings in C!
    // main function is the special function in C from where execution of a program starts and ends.
    // main function returns the status of a program to parent process (for us parent process is OS of our machine), 0 means SUCCESS, non zero means error!
    // main function is supposed to return an int value to the calling process as per the standard C89 and above.
    // The variables can be defined outside of a function, however all executable statements should be in functions.
    // Every C program has one function which is called main.c.
    // printf is also a function given by a standard library code!
    function_add_numbers(12, 13, 14);    // this is how we call function
    int value1 = 15;
    int value2 = -12;
    int value3 = 31;
    function_add_numbers(value1, value2, value3);    // this is how we call function. If you enter less than 3 args, compiler will generate error!
    
    int returnValue;
    returnValue = function_add_numbers1(value1, value2, value3);
    printf("Sum = %d\n", returnValue);
    return 0;
}

void function_add_numbers(int a, int b, int c)  // void means function does not return any value.
{
    int sum;              // these variables (a,b,c,sum) are called local scope variables and also called as formal parameters.
    sum = a + b + c;
    printf("Sum = %d\n", sum);
}

int function_add_numbers1(int a, int b, int c)  // A function which returns something
{
    int sum;              // these variables (a,b,c,sum) are called local scope variables and also called as formal parameters.
    sum = a + b + c;
    return sum;
}

