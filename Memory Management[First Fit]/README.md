Memory Management is the act of managing computer memory at the system level. The essential requirement of memory management is to provide ways to dynamically allocate portions of memory to programs (user processes) at their request, and free it for reuse when no longer needed. Consider the following scenario in relation to the “First Fit Algorithm” in memory management. Each user process (job) requests a particular size of memory that must be made available contiguously (one block). If such a memory partition exists, it is allocated to the requested process. If that memory partition is too large to accommodate the process, the memory block is divided into two parts. One to accommodate the process and other one is kept as a free space block. When a job terminates, its allocated block of memory becomes a free space. If one assumes the memory size is 2560k and 400k is allocated for operating system files, the remaining memory is reserved for user processes.
Use C programming language to implement a Memory Management scenario using pointers and appropriate data structure. You should design a suitable interface to input the ProcessID along with the memory size it requires. Your code should include the relevant class definitions and method definitions (for allocating and releasing memory). A method to print a current snapshot of the memory is also required.
Identify appropriate data structure (you have to mentioned explanation for choosing that data structure in your report)
Test your code for the following scenario.

     • Allocate P1 600k
     • Allocate P2 1000k
     • Allocate P3 300k
     • Terminate P2
     • Allocate P4 700k
     • Terminate P1
     • Allocate  P5 400k
