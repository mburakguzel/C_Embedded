// Download IDE via https://www.st.com/en/development-tools/stm32cubeide.html
// STM32CubeIDE is an Eclipse based IDE and can be used for stm32 arm based microcontrollers.
// STM32CubeIDE supports all OS platforms!
// Using this IDE, we can also write and compile C programs for our HOST machine (our own computer).

// INSTALL GCC
// STM32Cube IDE also installs the GCC cross compiler for ARM Cortex Mx processors, we do not need to install them.
// However it is needed to intall of GNU Compiler Collections (GCC) for host. 
    // Download and install MinGW
    // Download and install msys2 https://www.msys2.org/ Do not run when intallation ends.
    // Open computer, right click properties, advanced system settings, in advanced tab press environmental variables, click path and click edit, add new path as the directory of mingw/bin
    // Also add C:\msys64\usr\bin as a new path.

// Importing projects of courses into cube IDE:
    // IMPORT HOST FILES:
    // Run cube IDE.
    // Choose instructor/host as the workspace
    // File ==> import ==> general ==> Existing projects into workspace ==> select the downloaded files host directory ==> only check copy projects into workspace
    // Click small restore button on the upper left corner
    // Right click to a project ==> build project to build a project.
    // Right click to a project ==> clean project to delete files creted while building the project. (Binary is deleted.)
    // IMPORT TARGETT FILES:
    // Click file on IDE ==> switch workspace ==> enter intructor/path and repeat above instructions

// Create a project for your HOST:
    // File ==> New ==> C/C++ project ==> C manage Build ==> Enter the project name ==> Choose Compiler (MinGW for Windows) (since this settings is for host!) ==> Finish
    // Right click to project ==> New ==> Source File ==> main.c
    // Right click to project ==> Build project ==> Generates a .exe file in Binaries
    // Right click to this .exe file ==> Properties ==> Click to folder icon to go to the directory of the .exe file.
    // Double click to file to run the file!

// Create a project for your TARGET:
    // Switch workspace to workingdirectory/target.
    // File ==> New ==> STM32 Project (wait for IDE to create settings)
    // Select your board! You can download documents of your product as well!
    // Enter project name ==> Select use default location ==> C ==> Executable ==> Empty (NOT STM32Cube unless you know how to work STM32CubeMX Software)
    // Click Finish!

// GET RID OF FPU WARNING WHEN YOU BUILD TARGET PROJECT
    // right click on the project -->properties -> expand C/C++ build --> Settings --> Tool settings -->MCU settings
    // Set floating point unit as None 
    // and Floating point ABI as Software Implemetation!
    // Apply and close ==> Clean project ==> Build again!


