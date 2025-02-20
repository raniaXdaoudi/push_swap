# push_swap

A sorting algorithm project that sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions. This project is part of the 42 school curriculum.

## Description

This project involves sorting a set of integers using two stacks and a limited set of operations. The goal is to sort the numbers in ascending order with the minimum number of operations possible. The project teaches about algorithm complexity and optimization.

## Features

The program supports the following operations:
- `sa` - Swap the first two elements of stack A
- `sb` - Swap the first two elements of stack B
- `ss` - sa and sb at the same time
- `pa` - Push the first element of stack B onto stack A
- `pb` - Push the first element of stack A onto stack B
- `ra` - Rotate stack A (first element becomes last)
- `rb` - Rotate stack B (first element becomes last)
- `rr` - ra and rb at the same time
- `rra` - Reverse rotate stack A (last element becomes first)
- `rrb` - Reverse rotate stack B (last element becomes first)
- `rrr` - rra and rrb at the same time

## Getting Started

### Prerequisites
- GCC compiler
- Make

### Installation
```bash
git clone https://github.com/yourusername/push_swap.git
cd push_swap
make
```

### Usage
```bash
./push_swap 2 1 3 6 5 8
```
The program will output a list of operations that will sort the numbers.

For testing with the checker (if available):
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## Algorithm

The program implements different sorting algorithms based on the size of the input:
- For 2 numbers: Simple swap if needed
- For 3 numbers: Optimized algorithm with maximum 2 operations
- For 5 numbers: Insertion sort approach
- For larger sets: Radix sort algorithm

## Return Value
- The program outputs the list of operations to sort the stack
- In case of error (non-numeric input, duplicates, etc.), it displays "Error"

## Building
The project includes a Makefile with the following rules:
- `make` - Compiles the program
- `make clean` - Removes object files
- `make fclean` - Removes object files and the executable
- `make re` - Rebuilds the program

## Author
- Rania (radaoudi)

## License
This project is part of the 42 school curriculum. Please refer to 42's policies regarding code usage and distribution.

## Acknowledgments
- 42 school for providing the project requirements and framework
- The sorting algorithms documentation and resources
