/*
 * Functions.c
 *
 *  Created on: 28 jul. 2022
 *      Author: nlbguz
 */

# include <stdio.h>  

int main()    
{
    // Using printf outputs are only applicable for ARM Crotex M3/M4/M7. For M0 there is a specific way (openOCD based semi hosting)! 
    // printf works over SWO oin (Serial Wire Output) of SWD interface.
    // The second circuit on our board is called ST Link V2 Debug circuit. This is a ST link onboard debug circuitry. By using this circuit, our PC can communicate with the board.
    // We actually write our program to the internal flash of the mc(microcontroller) through this circuit, we read various memory locations of the mc, we make processor run and stop owing to this debug circuitry.
    // Debug circuitry will talk wit the PC over a USB connection. There is a pin called SWO pin which is coming all the way from processor(ARM Cortex M) and it is connected to debug circuitry.
    // So printf works on this SWO pin.
    // In processor there is a ITM (Instrumentation Trace Macrocell Unit), It is an operational driven trace source that supports printf style debugging to trace operating system and application events, and generates diagnostic system information.
    // ITM is only available on ARM Crotex M3 and above processors.
    // SWD (Serial Wire Debug) is a two-wire protocol for accessing the ARM debug Interface.
    // Debugging the processor means reading the memory location, reading the processor register, making the processor halt(stop) or run. All these are done via SWD.
    // Also we can use serial wire wiever of SWD to debug printf statements. This is the third optional pin called as SWO
    // SWD has 3 pins. Two pins for debug one pin for trace! Trace means get the trace related information from the processor.
    // SWD is part of the ARM Debug Interface Specifications v5 and is an alternative to JTAG.
        // JTAG needs more pins(4 excluding GND) than SWD. JTAG is used in ARM7/9 family. SWD is used in Cortex-M family.
        // SWD proveide one more pin called SWO(single wire output) which is used for single wire wieving (SWV), which is a low cost tracing technology.
    // The physical layer of SWD consists of two lines:
        // SWDIO: a bidirectional (communication on both ways) data line. Carries debug related commands. When you insert a reakpoint in your IDE, so that information will be sent over SWDIO.
        // SWCLK; a clock driven by host (on our board the host is actually the ST link circuitry)
    
    // In the ITM unit there is also a FIFO (which is a hardware buffer).
    // We need to write printf data into this FIFO, the FIFO is actually connected to SWo pin.
    // Not all IDEs support this functionality, however STM32Cube IDE does.
    // Debug Exception and Monitor Control Register base address.
    // This is the code that we use to make our MCU run printf function.
    // Go to project, go to syscalls.c in Src ==> after #include <sys/times.h> paste below code
#define DEMCR        			*((volatile uint32_t*) 0xE000EDFCU )

/* ITM register addresses */
#define ITM_STIMULUS_PORT0   	*((volatile uint32_t*) 0xE0000000 )
#define ITM_TRACE_EN          	*((volatile uint32_t*) 0xE0000E00 )

void ITM_SendChar(uint8_t ch)
{

	//Enable TRCENA
	DEMCR |= ( 1 << 24);

	//enable stimulus port 0
	ITM_TRACE_EN |= ( 1 << 0);

	// read FIFO status in bit [0]:
	while(!(ITM_STIMULUS_PORT0 & 1));

	//Write to ITM stimulus port0
	ITM_STIMULUS_PORT0 = ch;
}

    // After that find _write function and command out below statement:
    __io_putchar(*ptr++);
    // And isted of this line call ITM_SendChar function.
    ITM_SendChar(*ptr++);   // add this line instead of below line
    // Cross compiler means we build our code on our host mavhine but we create a executable file for other architecture(MCU in ur case).
    // We genereate three different format for ARM CCortex MCU:
        // .elf is a type of ececutable which stands for executable and linkable and used for debugging. .eld is used during debugging.
        // .bin and .hex are pure binary executables which are used for productions.
        // Assume we give an executable of our project to a customer, then we should give .bin or .hex not .elf! There are tools to dissamble .elf file to get all information about the code!
        // We will ise .elf since we wil be debugging our code on the target. debugging is not possible if we use .bin or .hex. These are pure binary files and only used in production.
    
    // native compiler means the compiler runs on a host machine and produce executables whicl also runs on the same machine.

    // 1st time for the project, for another project we need to do the same:
    // Connect MCU ==> Right click to project ==> Debug as ==> Debug Configuration ==> Double click STM32 C/C++ Application ==> In debugger path, we should select ST-LINK GDB Server
    // Interface should ne SWD and enable SWV, click apply and close
    // After first time
    // Right click to project ==> Debug as ==> STM32 C/C++ Application ==> Click Switch (this switches to debug percpective)
    // This will load our code to processor and stop in the first statement.
    // Click window ==> Show view ==> SWV ==> SWV ITM Data Console
    // Click Configure Trace (asagidaki bolmede sag ustte anahtar ve tornavida) ==> Enable port 0 ==> ok (ITM has 32 channels but printf uses channel 0, so we use it here.)
    // Click resume to run the code. or click step over to go one by one!
    // Reset the board via IDE, (play altinda ok geri dogru)
    // Click start trace next (kirmizi yuvarlak) to Configure Trace (asagidaki bolmede sag ustte anahtar ve tornavida)
    // Now run the code again via IDE.
    // Printf goes to standard library, from standard library it is coming to the write function, in write function it goes to the ITM FIFO, from there it is coming over the SWO pin to the IDE.

    // Switching from c++ perspective to debug perspective can also be done by clicking the bug symbol at the upper right corner of the IDE.
    // If after we run the code and terminate it via the button at the bottom side of the IDE, we try to debg again this causes an error.
    // Switch to debugging perspective  manually, right click to <terminated... ==> terminate and remove ==> go back to c/c++ perspective and debug your code again!

    // HOW BUILD PROCESS WORKS ON MCUs
    // Build process can be divided into three stages:
        // Preprocessing: source file will be preprocessed using preprocessor engine of the compiler. This produces a .i file for every .c file.
            // This is the stage where the #include files will be resolved and all the C macros will be resolved.
        // Compilation stage
            // Parsing (Parse: incelemek, cozumlemek gramer olarak) parser engine checks .i files to find out if there is any syntax error.
            // If everything is fine, the code is converted into .s file using another engine of the compiler called code generator. That means .i will be converted to .s
                // This is where higher level code such as C, converted into lower level language such as assembly language.
                // That means for every C statement you have written, the equivalent mnemonics will be created in the .s. (mnemonics are rom ARM Cortex instruction set architecture)
            // The assembler engine of the compiler converts mnemonics into machine codes (just numbers). This process generates .o file also called as relocatable object files.
                // For every .c file, there will be a .o file created by assembler. If you have 5 .c file, 5 .o file will be created.
        // Linking stage will be invoked here!        
            // Multiple relocatable object files will be combined into one executable file. The linker will merge all .o files (machine codes) into one file. 
            // An executable will be generated. In our case, format of the final executable file will be .elf (eld refers to executable and link format).
                // The GCC based compilers will actually generate executable file of .elf.
            // Post processing of the executabel (optional!). We can do post processing on that .elf file using tools such as object copy and other tools to produce various other files like .bin, .hex, etc.

    // To see all this created files: right click to project ==> properties ==> resource ==> click icon at the end of the location ==> this will take you to the folder where this project is placed ==> Open folder with name Debug3
    // .o file can be found under Src folder.
    // .i and .s files are not there, because compiler generates them internally. To make compiler store them right click to project ==> properties ==> Expand C/C++ Build ==> Settings ==> Click miscellaneous under MCU GCC Compiler ==> Click icon (a paper with green arrow on it) ==> type -save-temps ==> press ok ==> apply ==> rebuild project


            
}