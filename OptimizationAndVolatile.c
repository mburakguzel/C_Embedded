// Optimization is a series of actions taken by the compiler on your program's code generation process to reduce
    // Number of instructions (code space optimization)
    // Memory access time (time space optimiziation)
    // Power consumption
// By default, the compiler does not invoke any optimization on your program. You can enable the optimization using compiler flags. 
// Compiler flags to enable optimization
    // -O0 (This is used by default) Means optimization limit is zero.
        // No optimization
        // Not recommended for productions if you have limited code and ram space
        // Has fastest compilation time
        // This is debugging friendly and used during development. This is debugging friendly because, when you are trying to debug your code there will be one to one map between the instructions generated and the source code what you have written.
        // A code which works with -O0 optimization may not work with -O0+ (O1, O2 and O3) optimization levels. Code needs to be verified again.
    // -O1
        // If you use O1 optimization level, then it is kind of introducing moderate optimization to decrease memory access time and code space.
    // -O2
        // Full optimization
        // Slow compilation time
        // Not debugging friendly. There will not be one to one mapping between the instructions generated and the source code what you have written.
    // -O3
        // Full optimization of -O2 + some more aggresive optimization steps will be taken by compiler.
        // Slowest compilation time.
        // May cause bugs in the program
        // Not debugging friendly.

// HOW TO SET OPTIMIZATION LEVEL
    // Right click on the project ==> properties ==> Expand C/C++ Build ==> Settings ==> MCU GCC compiler ==> Optimization ==> Select Optimization level apply and close.
    // Always try if built applications is working or not with the new optimization level.

// VOLATILE