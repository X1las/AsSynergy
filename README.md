# AsSynergy
Repository for benchmarking C, C#, Java and Python with and without Multi-Core Threading capabilities.

# Requirements

Tests were run on Ubuntu 24.04.2 LTS with an intel Core i5-4460 CPU @ 3.2GHz, with 4 cores and 4 threads.

## Python 
Release: 3.12.3

### Modules

Benchmarking:
- Multiprocessing (version 0.70.18)

Models:
- matplotlib (version 3.10.1)
- numpy (version 1.26.0)

## Java
OpenJDK 21.0.6
OpenJDK RE 21.0.6
OpenDJK 64-Bit Server VM

With VM args: "-Xint" to disable JIT

## C-Sharp
.NET 8.0.115

## C Compiler
GCC 13.3.0
Thread Model: Posix
