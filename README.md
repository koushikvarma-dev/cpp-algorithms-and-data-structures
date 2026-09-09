# C++ Algorithms and Data Structures

A portfolio project containing clean, modern C++ implementations of common algorithms and data structures, with emphasis on problem solving, complexity analysis, STL usage, and testable design.

> **Portfolio project:** This repository is designed to demonstrate C++ problem-solving and software engineering skills.

## Highlights

- Binary search
- Merge sort and quicksort
- Two-pointer and sliding-window techniques
- BFS and DFS graph traversal
- Heap / priority-queue based processing
- Stack and queue implementations
- Singly linked list
- Binary search tree
- Hash-based lookups using the STL
- Unit-style executable tests
- Complexity notes for implemented algorithms

## Tech Stack

- C++17
- STL
- CMake
- Make
- Git

## Project Structure

```text
cpp-algorithms-and-data-structures/
├── include/
│   └── algorithms.hpp
├── src/
│   └── algorithms.cpp
├── examples/
│   └── main.cpp
├── tests/
│   └── test_algorithms.cpp
├── CMakeLists.txt
├── Makefile
└── .gitignore
```

## Build with CMake

```bash
cmake -S . -B build
cmake --build build
./build/algorithms_demo
./build/algorithms_tests
```

## Build with Make

```bash
make
./build/algorithms_demo
make test
```

## Skills Demonstrated

- Algorithm design and implementation
- Time and space complexity analysis
- Modern C++17 programming
- STL and generic programming concepts
- Data structures
- Defensive programming and edge-case handling
- Modular source/header organization
- Automated testing
- CMake and Make build systems

## Future Improvements

- Add benchmarking with large datasets
- Add more graph algorithms
- Add dynamic programming examples
- Add additional automated test coverage
