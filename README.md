*This project was created as part of the 42 curriculum by vvan-ach and ncaravac*

# Push Swap - Stack sorting and algorithm implementations exercise

<p align="center">
	<img src="https://i.ibb.co/1YF8R8Z9/Chat-GPT-Image-Dec-27-2025-09-08-13-PM-1.png" width="800">
</p>

## Description

	Push swap is a project requiring to learn, understand and implement different types of sorting algorithms, the main objective is to create a program that takes as argument a stack of numbers that are not in order, and then, based on the amount of disorder in that stack, choose an algorithm varying betwen O(n^2) (simple), O(n√n) (medium), and O(n log n) (complex) to sort that stack with the less movements possible. Most of the projet is about optimisation and fine tuning our implementations of theses three algorithm that we choose : Selection sorting (simple), chunk based sorting (medium), quicksort with stack-based partitioning (complex)

## Instructions
#### This program can be compiled as follow:

`**make**`
> Compiles the sources in a program called push_swap

#### Here are examples of how to use the program:

`./push_swap --medium 4 3 2 1`

`./push_swap --bench --adaptive 78 45 77 32 1`

## Reason of the choosen algorithms

#### 1. Simple (O(n^2)) : Selection Sort

> This algorithm is a simple selection sort method. After repeatedly identifying the smallest element in stack A, it rotates the stack in the optimal direction to move this element to the top. The element is then pushed to stack B, and the remaining three elements in stack A are sorted immediately. In the end, every element from stack B is returned to stack A in the correct order. This approach was selected because it is simple to use and performs well with small input sizes. Additionally, it is a good fit for simple cases because it requires fewer and more predictable operations than more complicated algorithms.

#### 2. Medium (O(n√n)) : Chunk based sort

> This algorithm is based on a chunk-based sorting strategy.
The values in stack A are divided into several ranges (chunks). Elements belonging to the current chunk are progressively pushed to stack B, using rotations to minimize the number of moves. Once all chunks have been processed, elements in stack B are pushed back to stack A in descending order, restoring a fully sorted stack.
This approach was chosen because it scales better than simple selection sort for medium-sized inputs, significantly reducing the total number of operations while remaining simpler and more predictable than advanced algorithms.

#### 3. Complex (O(n log n)) : Quicksort with stack-based partitioning

> This algorithm is a quicksort-inspired approach using stack-based partitioning.
A pivot is selected from the current stack segment, and elements are partitioned between stack A and stack B according to this pivot using rotations and push operations. The process is applied recursively on both stacks until the remaining segments are small enough to be sorted directly.
This method was chosen because it scales efficiently for large input sizes, significantly reducing the total number of operations compared to selection or chunk-based approaches, while fully respecting the constraints of stack operations in push_swap.

## Ressources
1. [w3schools](https://www.w3schools.com/c/):
    Good website to understand C functions completely, full of snippets and explainations.
2. [ChatGPT](https://chatgpt.com):
    The ai that everyone knows, to confirm and give me optimisation ints when I have a working code.
3. [Stackexchange](https://stackexchange.com):
    The website when I want to read extensive responses to simple questions
4. [Quicksort](https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/):
	Quicksort algorithm on the geeksforgeeks website
