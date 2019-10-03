---
title: Workshop on Parallel Programming with Python (3-pop)
author: Johan Hidding (Netherlands eScience Center)
---

# Intro

## Schedule

| Time    | Item                                  |
| ------: | --------                              |
| 9:15    | Introduction, Primitives and the GIL  |
| 10:30   | Coffee                                |
| 10:45   | Concurrent IO with `asyncio`          |
| 12:00   | Lunch                                 |
| 13:00   | Functional programming with `noodles` |
| 14:30   | Coffee                                |
| 14:45   | Boost your NumPy with `dask`          |
| 15:30   | Applications                          |

# Primitives and the GIL

## Parallel programming models

* Shared memory
    * threads

* Distributed memory
    * message passing

## SIMD / MIMD

* Partitioning
    * Domain decomposition
    * Functional decomposition

## Managing

* Load balancing
* Granularity: communication vs. computation

## Primitives

* `multithreading`
* `timeit`
* the global interpreter lock
* `cython`
* `multiprocessing`

# Async IO

## Co-routines in Python

* `yield`
* co-routines
* futures
* `async` / `await`

# Functional Programming with Noodles

* Higher order functions: `map`, `reduce`
* Decorators
* Dynamic programming
* Error handling
* Promises

# Boost NumPy with Dask

