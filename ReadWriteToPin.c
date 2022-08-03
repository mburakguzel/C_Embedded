    
    // HOW TO WRITE TO OUTPUT PIN:
    // In STM32Fx based MCUs each port has 16 pins where you can connect external peripherals (LED, Display, button, bluetooth receiver, external memory (e.g EEPROM), Joy stick, keypad etc.) (Video112)
    // GPIO stands for general pupose IO. We use those port`s pins for GPIOs. GPIO also has set of registers which are used to control pin's mode, state and other fuctionalities.
    // So, MCU should also be able reach and modify these registers. 
    // These registers can be accessed by using memory addresses, hence you can also say that this peripheral registers are memory mapped.
    // I/O pins are controlled using peripheral registers which are mapped on to processor addressable memory.
    // In Arm Cortex MCUs, processor (CPU) reaches all peripherals (data memory, code memory, GPIOD, Timers, ADC, I2C) via system(central) bus (AHB - Advanced High Performance Bus). 
    // This Bus comprises(icermek, kapsamak) of 2 channels: 32 bit address channel (which means you can put 2^32 addresses (4 gigabyte) on this bus in order to target different peripherals) and 32 bit data channel.
    // Peripherals are controlled by their own set of registers, and a register is addressed by its unique address.
    // Processor can put address ranging from 0x0000_0000 to 0x_FFFF_FFFF on the address bus.
    // When the processor (address generation unit of processor) put these memory locations to address bus, the address bus will be targeting the code memory of the microcontroller.
    // Each peripheral has its memory range which is shown in memory map of ARM Cortex Mx processor. This is fixed for all ARM Cortex Mx processors, and software must be designed according to this.
    // This memory map can be found in MCU's reference manual. Search for memory map in contents! (Section 2)
    // It shows first(base) abd last address of each peripheral.
    // Each bit of GPIO Output data register controls one I/O.

    // Peripheral registers:
        // All peripheral registers in STM32 MCU are of 32 bits wide.
        // Different peripherals has different number of peripherals.
        // GPIO peripheral registers: (There are ten but important ones ae given below)
            // 1) GPIOD port mode register // used for determine the port mode I or O! (GPIOD) since we are checking GPIO-D. It can be GPIOA or GPIOB etc. 
            // 2) GPIOD port output type register // used for determine the type of output
            // 3) GPIOD port pull-up/pull-down registers // used for determine the pert mode I or O! 
            // 4) GPIOD port input data registers // used for reading data from Input! 
            // 5) GPIOD port output data registers // used for wrighting data to Output! 
    // The first register that you find in the address range (given in reference manual) of GPIOD peripheral register is GPIO mode register.

    // How to use an I/O:
        // 1) Identify the GPIO port (a peripheral) used to connect the LED.
        // 2) Identify the GPIO pin where the I/O is connected.
        // 3) Activate the GPIOD peripheral (enable the clock) : In MCUs, by default most of the peripherals are dead, you need to activate them. activating them is nothing but enabling clock for them.
            // For some MCUs peripheral can be ON by default, you do not need to activate them.
        // 4) Configure the GPIO pin mode as input or output.
        // 5) Write or read from GPIO pin.
    
    // How to enable peripheral clock:
        // The peripheral is enabled throug peripheral clock control registers of the MCU.
        // For all STM32 MCU, all clock register are mapped at these address range in the memory map of the MCU: 0x4002 3800 - 0x40023BFF
        // In STM32 microcontrollers there is an encgine called RCC (Reset and Clock Control). This RCC engine takes care of controllin clocks for various part of the MCU such as processor, different peripherals, different buses, memories etc. 
        // RCC engine has its own set of addresses to control the clock and all those registers are mapped at above address renge. 
        // To enable clock, select a appropriate register in the RCC block to enable the clock.
        // Go to reference manual and explore RCC registers (Section 6)
        // RCC AHB1 peripheral clock register is used to enable clocks for those peripherals which are hanging on the AHB1 bus.
        // GPIOD hangs on AHB1 bus. (This information can be found data sheet of the MCU. Check internal architecture scheme of the MCU)
        // We should add the offset, given in 'RCC AHB1 peripheral clock register' section of reference manual, to base address of the RCC to get the address of RCC AHB1 peripheral clock register. 
        // Activate 3rd bit position, GPIODEN: I/O port D clock enable! if 1 enabled.
    
    // How to calculate peripheral register address:
        // The RCC register for GPIOD is AHB1ENR. Let`s calculate the address of this register.
        // Take base address and add offset (given in 'RCC AHB1 peripheral clock register' section of reference manual) 

    // How to calculate address of the GPIOD mode register:
        // Find the GPIOD's base register address in the reference manual.
        // Add offset (given in GPIO registers section 6 of reference manual.) 
        // This register is devided to 16 sections (2 bits for each = 32 bits). Each section controls the mode of the corresponding pin (16 pins on GPIOD)
        // Why 2 bits are dedicated because there are four modes!
            // 00 Input (Default state)
            // 01 General purpose output mode
            // 10 Alternate function
            // 11 Analog function
    
    // How to calculate address of GPIOD output data register (to write):
        // Find the GPIO port output data registers in GPIO registers section 6 of reference manual
        // Only sixteen bit are implemented since there are only 16 pins. 0th port controls 0th pin. Find offset.
        // Add this offset to the base address of GPIOD (in the reference manual)

    // Watch Video 120 again and run the code on your MCU!

    // HOW TO READ FROM INPUT PIN: (Check video 143!)
    // We will read PA0 as an example.
    // First check if PA0 is a free I/o for your board. Go to Extension connectors in reference manual (section 6.11), find PA0 and check if Free I/O is filled for this pin.
    // Enable clock for GPIOA, check above explanations to understand how to enable it.
    // Configue PA0 as input mode. Again check above explanations.
    // Find register address to read input. Check above explanations! You will get 32 bits data but you only need 1 bit, use masking!