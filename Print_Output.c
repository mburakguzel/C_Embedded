/*
 * Print_Output.c
 *
 *  Created on: 27 jul. 2022
 *      Author: nlbguz
 */

# include <stdio.h>   	// this is the header file to use printf function. #include is a preprocessor directive.

int main()     			// according to c90 and c99 standards main should return int!
{
	printf("Hello World!\n");         // \(back slash) is called escape character.
	printf("Today is a great day!\n");

	printf("Hello World! \r");
	printf("Bye !\n");                    // Output should be "Bye ! World!" becouse \r move cursor to beginning of the line and overwrite. However, it did not happen in STM32CubeIDE. Output was same with the above code!
										  // It worked in VSC!
	printf("David says , \" Programming is fun !\"\n");
	printf("Good day !");
	// When we debug our code, compiler creates several files:
		// main.i is for the preprocessor activities. Includes our code and contents of stdio.h file!
		// main.s is collection of assembly instructions. Higher level language (C) is converted into a little lower level language that is called as assembly language.
		// main.o; Assembly level mnemonics (mnemonic is an abbreviation for an operation in assembly language) are converted into opcodes (machine codes for instructions)

// FORMAT SPECIFIER IN C:
	// %d Integer
	// %f Float
	// %c Char
	// %s String
	// %u Unsigned Integer
	// %ld Long Integer (el-di)
	// %lu Long unsigned Integer (el-yu)
	// %I64d for long long int in MinGW compiler (ay-64)
	// %I64u for unsigned long long int in MinGW compiler
	// %I64X for unsigned long long int in hex format in MinGW compiler
	// %lld for long long int in linux or mac compilers
	// %llu for unsigned long long int in linux or mac compilers
	// %x hex format
	// %o octal format
	// %p shows address of a variable as shown below. (Also can see Data_Types.c / Address of a Variable)
    // %lf double
    // %f float
	// %0.9f float prints 9 digits after decimal point. However, after 6 it is not accurate since float stores 6 digits at most.
	// %0.14lf double prints 14 digits after decimal point.
    // %e and %le for real numbers in scientific notation // e.g 4.578977e+001
	// %0.2e and %0.2le for real numbers in scientific notation // e.g 45.8e+001
	unsigned a1 = 160;
	unsigned a2 = 160;
	printf("a1 = %d\n", a1);      // shows a = 160(value of a)
	printf("a1 = %x\n", a1);      // converts a to hex and shows hex equivalent of a
	// One print can print multiple variables:
	printf("a1 = %d, a2 = %d\n", a1, a2); 
	// Print address of avariable:
	printf("Address of variable mydata = %p\n", &mydata);
	char mydata = 'A';
    printf("Address of variable mydata = %p\n", &mydata);


// ESCAPE SECTIONS IN C:
	/*
	\t is a horizontal tab (4 white space chars).
	\0 is considered as null character.
	\r is carriage return, Moves the cursor to the beginning of the current line horizontally.
	\\ to print backslash.
	\" to print double quote.
	\' to print single quote.
	*/
}


