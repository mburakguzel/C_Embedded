// WHAT IS A MICROCONTROLLER (MCU):
    // MCU is a small computer on a single chip with limited resources.
    // A typical MCu includes 
        // a processor (CPU)
        // volatile(ucucu-gecici) such as SRAM and non-volatile memories flash, ROM, EEPROM, clock unit, bus interface
        // I/O pins
        // Peripherals: ADC, DAC, or timing perpherals such as timers, connectivity peripherlas such as UART, USB
        // Clock
        // Bus interfaces on a single chip.
// HOW MCU WORK:
    // Program runs in processor.
    // Program memory is a non volatile memory means once you store your program memory that is permanent. We can delete it if we want, but it will be there even when the power is gone.
    // Once you give power to the microcontroller, a CPU actually reads instructions from the program memory. So, it means CPU should communicate with program memory. CPU comminicates with program memory using bus interfaces.
    // CPU first produces the address on the address bus and after that insturction will come into instruction bus (data bus). Then CPU decodes this instruction by using its instruction decoder.
    // How fast CPU executes a instructions depend upon the clock supply to the CPU. Clocking unit supplyes clock to the CPU. Depending on the speed of the clock, speed of code executaion can be controlled.
    // Non volatile memory is also called data memory. This is used to store data of our program (not the program itself, it is stored in non-volatile memory). This memory is also used as a scratchpad (karalama defteri) means we can store a data temprorily.
    // Data memory is used (consumed) during the runtime of the program.
    // When the power of MCU is off, contents of the data memory will be lost.
    // But our MCU should also comminicate with external devices. This can be done with serial I/o or parallel I/O.
    // When MCu comminicates with a bluetooth module, it uses serial I/O.
    // ARM is not a ST product, ARM produces CPUs and other companies uses this CPUs in their microcontrollers. STM is one of them.
    // Flash is the code memory (non-volatile), SRAM is the data memory(volatile).
    // OTP memory means one time programmable memory.
    // CPUs usually have their internal oscillators (clock), so we do not have to provide clock to them.

// CODE MEMORY:
    // Stores instructions and constant data of our program.
    // There are diiferent types of code memories:
        // ROM (Read only memory)
            // MPROM (Mask Programmable Read Only memory): Once you program you can not delete it.
            // EPROM (Ultraviolet Erasable Programmable ROM): Erasable but erase process is too complex, you have to take the chip outside of your circuit and you have to put that under the ultraviolet machine.
            // EEPROM (Electrically Erasable Programmable Read Only memory) Most handy one,  used in some modern MCUs.
        // OTP (On time programmable)
        // Flash is also EEPROM. But the fabrication thechniques is totally different from EEPROM. There is a diffeerence between cost and speed. This is the widely used code memory in today`s MCUs.
        // FRAM (Ferroelectric Random Access Memory) More expensve. but access speed is quite high. You can find them in some of Texas Instruments MSP MCUs (e.g MSP430FR2422).

// PRACTISE WITH MEMORIES
    // Code memory (Flash memory):
        // When we build our code, compiler generates .elf file and we download this file to our MCU. This file also contains the program itself and consts.
        // After, bulding and debugging your program, to see memories of our MCU, click window on IDE ==> show view ==> memory browser
        // Type the base address of the program memory(flash). This can be found in reference manual of the MCU. 
        // Go to embedded flash memory section in reference manual. Find Flash module organization table (for other types of MCUs, thsi can be different.) Main memory is the flash memory.
        // System memory is ROM and here ST factory-built bootloader is stored, which never executes unless we invoke it by some settings. By default, it does not run. User can not write on this read only memory.
        // Starting address is Sector 0 and last address is Sector 11. When we download our code, it will be stored starting from base.
        // Copy 0x0800 0000 (base address of Sector 0) and paste it to memory browser on IDE. 
        // WE can see machine codes(just numbers) there. It shows word by word (32bits).
        // to change this to word by word(32bits / 4 bytes) ==> right click on the window which shows memory addresses ==> coulmns ==> 4
        // to change this to byte by byte(8bits) ==> right click on the window which shows memory addresses ==> coulmns ==> 1
    // Data Memory (SRAM memory):
        // Search for SRAM (Embedded SRAM part) in reference manual. It says SRAM1 and SRAM2 mapped at address 0x2000 0000. This is the abse adress of SRAM1 (starts from there.). SRAM1 is the primary data memory.
        // Copy this address to memory browser on IDE.
        // Right click to window ==> Radix ==> you can change the data type showed. Change it to decimal. You will see your varaibles are stored here.
        // Most of the MCUs has only on SRAM. 
// ANALYZE ELF FILE USING GNU TOOLS:
// When we download our program, it goes to flash. But how the data in SRAM is created? To see this lets analyze .elf file.
// Run "arm-none-eabi-objdump.exe -h projectname.elf" on your command prompt. First add the location of this tool to PATH.
// Go to location of your Cube IDE installation folder (C:\ST\STM32CubeIDE_1.10.1\STM32CubeIDE\plugins) and search for gnu and find the folder whose name includes externaltools.gnu
// C:\ST\STM32CubeIDE_1.10.1\STM32CubeIDE\plugins\com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.10.3-2021.10.win32_1.0.0.202111181127\tools\bin add this address to your path. Otherwise, above command will not work.
// Do not forget to close your command prompt and open again!
// Open MinGW command prompt (search mingw on windows), go to project folder and enter in Debug folder.
// arm-none-eabi-objdump.exe -h projectname.elf type this command to this command prompt. -h displays the contents of section headers. .elf format has a section headers. This will command will display us the section headers.
// You can also find this in the .list file which is located in Debug folder of your project.
// .elf file has many sections.
    // .text section contains codes (machine codes) or all the instructions of our program.
    // .rodata section contains all the read only data of our program.
    // .data section contains all the data of our program. (you can see that this falls into FLASH memory area by checking its LMA). So when, your IDE loads the .elf file to into FLASH memory, sections are also stored in FLASH.
// LMA Load Memory Address (Source in FLASH).
// VMA Virtual Memory Address (Destination in SRAM). Virtual is coming from Linux terminology but everything is physically exist actually.
// LMA shows where the section is currently loaded, VMA shows where the section should finally copied to. This coping is done by software (our code), although we did not write such a code.
// By coping LMA of .data section to memory browser (add 0x beforehand) on the IDE, we can see the variables are also stored on Flash memory.
// In the Startup folder of your project there is a startup....s file, open this file on IDE. You will see REset_handler routine. Whenever processor undergoes reset, this routine is implemented (be called automatically by hardware).
    // Which means, this is the first instruction which will get executed after resetting the processor.
    // And this is the place where data is copied from FLASH to SRAM. (Under CopyDataInit)
        // We can also put breakpoints in this startup file in debug preview. (r0 r1 r2 are registers.)
        // Window ==> Show view ==> registers to check registers.
// You can see it calls main under LoopFillZerobss routine. Before it you can also see it calls C standard library since we included it.


