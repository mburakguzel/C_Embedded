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
	// %x hex format
	// %o octal format
	unsigned a = 160;
	printf("a = %d\n", a);      // shows a = 160(value of a)
	printf("a = %x\n", a);   // converts a to hex and shows hex equivalent of a

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


