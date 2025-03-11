# General

DBLP - god resource for datalogi artikler

Parallel programming: for multicore clusters
Computer Architecture
Structured COmputer ORganization

# Keywords

- Parallelism
    - Running multiple tasks across multiple cores/threads
    - Single task single core
- Concurrency
    - Running multiple tasks simultaneously on one core
- Asynchronous 
    - Events that occur independently of the main program
    - How to deal with said events
    - Unordered
    - A thread that can be suspended to save processing
- Synchronous
    - Events that occur linearly and order in tune with the flow of the main program
    - Ordered
- Subroutine
    - Broadly speaking, functions
    - Defined by having a set of instructions that are callable from memory
    - Either internal or external
        - Declared inside the code or fetched from another piece
- Coroutine
    - A function that is allowed to be suspended and continued at will
    - Premise for running tasks across multiple cores or threads
- Threads
    - A list of tasks or instructions for a computer to execute
    - There can be many so the computer knows to switch when awaiting changes
- Load Balancing
    - The art of distributing network traffic equally across a pool of resources (i.e. cores)
- Context Switching

# Supervisor Questions

- How much should i expect the reader to know?
- How should i structure the report

# Status

- Began reading, noting lots of keywords and looking them up
- Starting to setup C programming environment and looking into pthreads
- Python doesn't use multiple cores by default, can use them with the multiprocessing library

# Quotes

"The technological development toward multicore processors was forced by physical reasons, since the clock speed of chips with more and more transistors cannot be increased at the previous rate without overheating." - Parallel Programming for Multicore and Cluster Systems (P.3)

# Parallel Programming for Multicore and Cluster Systems

- Read chapter 2 & 3
- Chapter 2 is theory
- Chapter 3 is for coding

### Instruction Pipeline

- The execution of each instruction is partitioned into several steps that are performed by dedicated hardware units one after another
  - These hardware units are also called pipeline stages
- Overlaps multiple instructions
- Is similar to an assembly line
- Typical numbers of pipeline stages lie inbetween 2 and 26 stages

### Clock Frequency

- The number of clock cycles per second
- Also called clock speed
- Meazured in hertz which is 1/second
  - abbreviated as Hz

### Clock Cycle Time

- The clock frequency F determines the clock cycle time T of the processor
- Formula: T = 1/F
- Usually the time needed for the execution of one instruction

### Parallel execution time

- Consists of the time it takes for all cores or processors to finish a given program
- Also the time for data exchange or synchronization
- Should be smaller than the time for a synchronized single core process to be worth it
- Influenced by idle times
- Smallest execution time occurs generally when workload is distributed equally amongst cores/processors
- Speedup and Efficiency is used to quantitatively measure the parallel execution time

### Load Balancing

- When the workload of a program is distributed equally amongst the machine's cores or processors

### Idle Times

- The time a processor cannot do anything useful but wait for more work

### Barrier Operations

- Barrier points where both distributed and shared memory machines have to wait for all cores to synchronize

### Memory

- Memory distribution methods per multi-core systems
- Can use bits of both

#### Shared Memory

- Memory organization where the machine shares memory for all threads
- Synchronization plays a heavy role, for example by keeping threads from reading files before another has written to them
- Often connected to the term "Thread"

#### Distributed Memory

- Memory organization where the machine distributes memory per processor
- Communication happens explicitly via communication operations
- Often connected to the term "Process"

### Core

- Refers to single computing units

### Multicore

- Refers to entire processor having several cores

### Tasks

- Bits of instructions broken down into something more that can be managed on multiple cores
- Are assigned to processes or threads which are then assigned to physical computation units for execution

### Synchronization

- Synchronization and coordination of threads and processes in order to execute them correctly
- Strongly connected with the way in which information is exchanged between processes or threads
  - Hardware dependant as well

### Scheduling

- The process of assigning tasks to processes or threads
- Fixes the order in which the tasks are executed
- Can be done by hand in the source code or by the programming environment, at compile time or dynamically at runtime

### Mapping

- The assignment of processes or threads onto the physical units, processors or cores
- Usually done by the runtime system but can sometimes be influenced by the programmer

### Decomposition

- Decomposing computations down into several tasks for multiple cores to process in parallel
- There are many different types of decomposition

### Granularity

- The size of tasks in terms of the number of instructions

### Potential Parallelism

- An inherited property of an application algorithm
- Influences how an application can be split into tasks

### ILP

- Instruction Level Parallelism (ILP)
- Processors which use pipelining to execute instructions are ILP processors

### Throughput

- The number of instructions finished per unit time of a pipeline
- In the absence of dependencies, the throughput is one instruction per clock cycle and the pipelines all work in parallel
- The absence of dependencies of pipelines determine the degree of parallelism attainable

### Superpipelined

- Processors with a relatively large number of pipeline stages

### ALU

- Arithmetic Logical Unit

### FPU

- Floating Point Unit 

## Flynn's Taxonomy of Parallel Architectures

### SIMD

- Single Instruction Multiple Data

### MIMD

- Multiple Instruction Multiple Data

### Superscalar Processors

- Superscalar processors have their parallel dependencies determined dynamically at runtime by hardware
- Decoded instructions are dispatched to the instruction units by hardware using dynamic Scheduling
- Makes the circut complexity increase significantly
- Simulations show that superscalar processors with up to four functional units yield substantial benefits over the single

### VLIW Processors

- Very Long Instruction Word (VLIW)

### 

### Computing Systems

- Comprises all the hardware and software components which are provided to the programmer
  - Forms the programmer's view of the machine

#### Software Aspects

- Operating System
- Programming Language
- Compiler or Runtime Libraries

#### Hardware Aspects

- Processor Architecture

### Four Parallel Processing Models

#### Machine Model

- Lowest level of abstraction
- Describes the hardware and operating system

#### Architectural Model

- Interconnection network of parallel platforms
- Memory organization
- Synchronous or Asynchronous processing
- Execution mode of single instructions by SIMD or MIMD

#### Computational Model

- 

#### Programming Model