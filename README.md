# CPU Emulator

This is a simple CPU emulator with a tiny assembly-like language for it.

A CPU has 8 32 bit registers (AX, BX, CX, DX, EX, FX, GX, HX) and a stack.

## Available commands

1) begin - Start executing commands;
2) end - Stop executing commands;
3) push - value0 - push back value0 to stack;
4) pop - pop back from stack;
5) pushr reg0 - read reg0 and pushing it to stack;
6) popr reg0 - pop back from stack to reg0;
7) add - adding two values from back of stack and push it back to stack;
8) sub - subtraction of two back values in stack and push result to stack;
9) mul - multiplication of two back values in stack and pushing result to stack;
10) div - division of two back values on stack and pushing result to stack;
11) out - printing back value on stack;
12) in - console input and push to stack;
13) jmp label - unconditional jump to label;
14) jeq label - jump to label if two back values on stack are equal;
15) jne label - jump to label if two back values on stack are not equal;
16) ja label - jump to label if back value on stack is greater than the next one;
17) jae label - jump to label if back value on stack is greater or equals than the next one;
18) jb label - jump to label if back value on stack is less than the next one;
19) jbe label - jump to label if back value on stack is less or equals than the next one;
20) call label - call function that is located on label.
21) ret - return from function


This language is able to do recursion.

## Running emulator

**CPU Emulator works only with Linux**. To run it, do the following:

go to directory Emulator-main and do

    cmake .
    make CPU

Now you can run CPU from console with command

    ./CPU *.txt

where *.txt is a file with your program. It must be located in directory Emulator-main,
not in some of it's subdirectories, like programs that are already written. 