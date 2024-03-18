# go_with_the_flow

The purpose of this lab is to write a class called HeatFlow which will simulate the one-dimensional flow of heat in a thin rod. A user should be able to specify different parameters of the simulation including the initial temperature of the rod, the length of the rod, the constant K, and any number of sources / sinks.

You can specify the location and number of heat sources/sinks in the driver program by adding keys and values to the sourcesAndSinks map.
You can also specify the number of sections and inital temperature by adjusting those variable values in the driver program.

Each call of the tick method will progress time forward one step, and pretty_print will print the temperatures to the screen.

In order to run this program, you must be able to compile and run C++ programs on your machine.

To run the program:
```bash
g++ main.cpp HeatFlow.cpp && ./a.out
```