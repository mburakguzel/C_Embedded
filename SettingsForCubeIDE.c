// To see debugging settings:
// Right click to project ==> Properties ==> Expand C/C++ Build Options ==> Settings
// Setting toolchain to default is fine. To upgrade this, go to ARM website and download newer version of toolchain.
// In tool settings ==> MCU settings: we can see MCu that we select.
    // Also we can change the runtime library. By default Cube IDE uses reduce C standard library, which is quite small conpared to C standard library. We can switch to standard from here.
// In tool settings ==> MCU Post Build outputs:
    // If you want to generate binary file or hex file or any other extension, then you can do so by selecting these options.
// In tool settings ==> MCU GCC Compiler: GNU11 is an extension to ISO-C11 standard. Use this one! Can also switch to pure ISO standard.

// To exclude a source file from build on STM32CubeIDE:
    // Right click to source file ==> Click C/C++ Build ==> Check the box "Exclude resource from build"