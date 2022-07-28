/*
 * Storage_Class.c
 *
 *  Created on: 27 jul. 2022
 *      Author: nlbguz
 */

# include <stdio.h> 

void myFunc1(void);

int main()     			
{
    // The storage class in C language decides:
        // Scope of a variable (local or global)
        // Visibility of a variable or function
        // Life time of a variable.
        // These tree are features of a variable. These features can be modified by using storage class specifiers.
    // There are two widely used storage class specifiers in C:
        // static
        // extern
    
    // STATIC
    // Example for static, goal of the program is counting how many times myFunc is called?
    myFunc1();           // Read myFunc1!   
    myFunc1();              
    myFunc1();
    // printf ("This function execuated %d times\n", count);   // This causes a compiler error since count is not a global variable. Only myFunc1 can reach it!
    return 0;

    // Another use case for static: Let`s say that we have multiple source files (.c files), in our project!
    // A static storage class can be used to manage the visibility of the variables across various files.
    /*
    In main.c:
    void file1_myFun1(void); // Prototype of a function (in this case outside of the main.c file), causes error if we dont define the function in main.c and call it in main.c.
    
    // int mainPrivateData;   // Defining this as global! This is not good because this variable can be accessed by any other source file.
    
    static int mainPrivateData; // When we define the variable with as static, it can not be reached outside of the main.c. (by any other source file!)

    int main()
    {
        mainPrivateData = 100;
        printf ("mainPrivateData =  %d\n", mainPrivateData);   // prints 100
        
        file1_myFun1();
        printf ("mainPrivateData =  %d\n", mainPrivateData); // prints 670 unless we define mainPrivateData as static! When it is static, compiler generates error since mainPrivateData can not be reachable by any other source file!

        return 0;
    }

    In the other source file (file1.c)
    extern int mainPrivateData;    // to reach mainPrivateData, we need to add extern!
    
    void file1_myFun1(void)
    {
        mainPrivateData = 670;
    }
    */
    // Another example to static: Static funtions! 
    void change_system_clock(int system_clock)   // Here we assume we are getting sytem clock as an argument to this function.
    static void change_system_clock(int system_clock)  // When we declare our function without static, it can be called by any other souce file (.c file). However, when we declare the function as static, it can only be called in current source (main.c) file.
    {
        printf ("System clock is %d\n", system_clock);
    }
    
    // EXTERN:
    // Extern class specifier is used to access the global variable, which is defined outside the scope of a file. This is mendatory!
    // Extern storage class specifier can also be used during the function call, when the function is defined outside the scope of the file. But this is not mendatory, it is optional!
    // Extern should be used only if we have multiple files in our project, so that we can access a variable defined in another file!
}

void myFunc1(void)
{
    // int count = 0;
    // count = count +1;
    // printf ("This function execuated %d times\n", count);   // Always shows 1 time! Because local variable count is deleted everytime function ends!
    // This problem can be solved by defining count as global variable before the main function! But, making this variable global also makes it public. So, any other function can access and modify it!
    // So we want a global varable that is private to a function! This can be achieved by using storage class specifier which is called static!
    // Instead of above code in this function use:
    static int count = 0;     // now count is global but private to myFunct1! The scope of this variable is global, but visibility is  only for this function.
    count = count +1;
    printf ("This function execuated %d times\n", count);   // Now shows how many times the function was called.
}