# Multi-Core Programming Notes

## 1. Core Concepts
### 1.1 Key Terms
- Parallelism
  - Running multiple tasks across multiple cores/threads
  - Single task single core
- Concurrency
  - Running multiple tasks simultaneously on one core
- Asynchronous & Synchronous Processing
  - Asynchronous: Independent events, unordered, suspendable
  - Synchronous: Linear events, ordered, barrier operations

### 1.2 Memory Architecture
- Shared Memory
  - Thread-based, shared access, needs synchronization
- Distributed Memory
  - Process-based, explicit communication
- Hybrid Approaches

## 2. Hardware Architecture
### 2.1 CPU Components
- Cores & Multi-core Systems
- ALU (Arithmetic Logical Unit)
- FPU (Floating Point Unit)

### 2.2 Pipelining
- Stages: Fetch, Decode, Execute, Write
- Superpipelined Systems
- Challenges
  - Data dependencies
  - Branch prediction
  - Stage timing optimization

### 2.3 Clock & Timing
- Clock Frequency
- Clock Cycle Time (T = 1/F)
- Parallel Execution Considerations

## 3. Parallel Processing Models
### 3.1 Flynn's Taxonomy
- SIMD (Single Instruction Multiple Data)
- MIMD (Multiple Instruction Multiple Data)

### 3.2 Processor Types
- Superscalar Processors
- VLIW Processors

### 3.3 Processing Models
- Machine Model
- Architectural Model
- Computational Model
- Programming Model

## 4. Implementation Concepts
### 4.1 Task Management
- Scheduling
- Mapping
- Load Balancing
- Granularity
- Decomposition

### 4.2 Performance Considerations
- ILP (Instruction Level Parallelism)
- Throughput
- Idle Times
- Barrier Operations

## 5. Research & References
### 5.1 Quotes
"The technological development toward multicore processors..."

### 5.2 Resources
- DBLP for computer science articles
- Parallel Programming for Multicore Clusters
- Computer Architecture texts
- Structured Computer ORganization

## 6. Project Status
- Current progress
- Next steps
- Questions for supervisor

## 7. CPU Architecture

### 7.1 ISA

- Instruction Set Architecture
- ARM
- X86

### 7.2 Caching

- Local cpu memory
- requests memory from the memory subsystem when needed
- memory is fetched in batches
  - used to avoid idle times

### 7.3 Micro Architecture

- Contains a set of stages
  - Fetch
  - Decode
  - Execute
    - such as addition, subtraction or comparisons
  - Write Back
    - Stores the execution either locally in a register or in global memory

### 7.4 Speculative Design

- CPU Fetch and Decode uses a prediction algorithm to optimize code execution to make it optimal

### 7.5 uOPS

- Micro Operations
- Strongest connection between the micro operations and the ISA

### 7.6 Instructions

- Instructions consist of a variety of elements
  - Prefix
  - OpCode
    - Operations code simplified to let the cpu operate on them
  - ModR/M
    - Specifies 0,1 or 2 operands for an instructions
  - SIB
    - Identifies an address in the registry if present, followed by the MODR/M
  - Displacement
    - Identifies a target
  - Immediate
    - Identifies a target memory location

### 7.7 Superscalar Execution

- Called Superscalar Execution when they can operate in parallel
- The number of executions a Microprocessor can execute is one way to measure the width of it
- All modern Microprocessors are superscalar
- The front-end of a microprocessor is important because it is needed to feed the back-end quickly enough for it to be efficient

#### 7.7.1 ALU

- Arithmetic Logic Unit
- Simplest form of operation
- Can perform adds or subtractions

#### 7.7.2 FPU

- Floating Point Unit

### 7.8 Order Execution

#### 7.8.1 Ordered Execution

- Synchronous execution, waiting on one task to finish before executing the next

#### 7.8.2 Unordered Execution

- Asynchronous execution, competing tasks in parallel disregarding order

### 7.9 CPU Backend

#### 7.9.1 Unordered Backend

- Takes the instructions as they get decoded into uOPS and determines their dependencies on other executions
  - uOPS are dependant when they need another uOPS' output to continue
  - Is tracked by a process called "Register Renaming"

## 8. GPU Architecture

### 8.1 Embarassingly Parallel Operations

- Parallel operations are operations that are so easily split into multiple tasks it is almost embarassing