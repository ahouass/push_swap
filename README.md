# push_swap - 1337 Project  

[![1337 Badge](https://img.shields.io/badge/1337-Project-blue)](https://www.42network.org/)  

## 📜 Project Overview

**push_swap** is a core project in the **1337 curriculum** (part of the 42 Network) that challenges students to sort data on a stack using a limited set of operations. This project focuses on algorithm optimization, problem-solving, and managing constraints.  

The goal is to create an efficient sorting algorithm that sorts a stack in as few instructions as possible, with additional features for handling larger stacks and achieving full bonuses.  

---

## 🚀 Features  

- Implements an optimized **sorting algorithm** tailored for stacks.  
- Handles varying stack sizes with dynamic complexity:  
  - Small stacks: brute force or simple algorithms.  
  - Large stacks: advanced range-based sorting techniques.  
- Includes a custom instruction set:  
  - Push, swap, rotate, and reverse-rotate operations.  
- Bonus: Efficiently handles larger stacks (e.g., 500 elements).  

---

## 📂 Repository Structure  

```plaintext  
|-- Makefile                     // Compilation rules for building the project  
|-- push_swap.c                  // Main implementation of the sorting algorithm  
|-- push_swap.h                  // Header file containing structs and function prototypes  

|-- check_input.c                // Input validation and error handling  
|-- check_input_utils.c          // Helper functions for input validation  

|-- checker_bonus.c              // Bonus: Checker program to validate sorting  
|-- checker_utils_bonus.c        // Bonus: Utilities for the checker program  
|-- get_next_line_bonus.c        // Bonus: Get Next Line implementation for reading input  
|-- get_next_line_utils_bonus.c  // Bonus: Utilities for Get Next Line  

|-- push.c                       // Implementation of 'push' operations (pa, pb)  
|-- swap.c                       // Implementation of 'swap' operations (sa, sb, ss)  
|-- rotate.c                     // Implementation of 'rotate' operations (ra, rb, rr)  
|-- reverse_rotate.c             // Implementation of 'reverse rotate' operations (rra, rrb, rrr)  

|-- sort_range.c                 // Range-based sorting algorithm for large stacks  
|-- sort_small.c                 // Sorting logic for small stacks  

|-- list_utils.c                 // Helper functions for linked list manipulation  
|-- utils.c                      // General utility functions  
|-- split.c                      // Custom implementation of string splitting  
```  

---

## 🛠️ How to Use  

### 1. Clone the Repository  
```bash  
git clone https://github.com/ahouass/push_swap.git 42-push_swap_1337
cd 42-push_swap_1337  
```

### 2. Compile the Program  

Use the provided `Makefile` to compile:  
- **Without Bonus**  
  ```bash  
  make  
  ```  

- **With Bonus**  
  ```bash  
  make bonus  
  ```  

### 3. Run the Program  


#### Mandatory Part  

The program expects a series of integers as arguments to represent the initial stack.  
```bash  
./push_swap <list_of_numbers>  
./push_swap 4 67 3 87 23
```
The output will be the list of instructions to sort the stack.

#### Bonus Part

To test if a list of instructions successfully sorts the stack, use the checker program. It takes the same input format as push_swap but also reads instructions from standard input to validate the sorting process.
```bash  
./checker <list_of_numbers>
./checker 4 67 3 87 23  
```
After entering the list of numbers, type the instructions one by one (e.g., pb, ra, etc.) and press Ctrl+D to end the input. The program will output either OK (if the instructions sort the stack) or KO (if the instructions fail to sort the stack).
```bash
./checker 4 67 3 87 23  
pb  
pb  
ra  
pb  
sa  
pa  
pa
```

Output:
```bash
OK  
```

For automated testing with the bonus, you can provide instructions using a file or command substitution.

```bash
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

---

### 📖 Instructions Set  

- **sa (swap a)**: Swap the first two elements of stack A.  
- **sb (swap b)**: Swap the first two elements of stack B.  
- **ss**: Perform `sa` and `sb` simultaneously.  
- **pa (push a)**: Move the top element of stack B to stack A.  
- **pb (push b)**: Move the top element of stack A to stack B.  
- **ra (rotate a)**: Shift all elements of stack A up by one.  
- **rb (rotate b)**: Shift all elements of stack B up by one.  
- **rr**: Perform `ra` and `rb` simultaneously.  
- **rra (reverse rotate a)**: Shift all elements of stack A down by one.  
- **rrb (reverse rotate b)**: Shift all elements of stack B down by one.  
- **rrr**: Perform `rra` and `rrb` simultaneously.  

---

### 📖 Sorting Algorithm  

#### Range-Based Algorithm  

The Range-Based Algorithm optimizes the sorting process by using a dynamic range to progressively organize elements across two stacks (stack A and stack B). This method is designed to efficiently sort large datasets with minimal operations, using the available set of instructions. The key idea is to determine a "range" of indices that helps you decide which elements from `stack A` should be moved to `stack B`. The algorithm adapts as you process the elements, reducing unnecessary moves.

### Detailed Steps:

1. **Parse input into stack A and validate it.**  
    - The input is first parsed and converted into stack A. Each element is stored in the stack as an integer. The program checks whether each element is a valid integer, ensuring no non-numeric characters are present. If any invalid characters are detected, an error is triggered.
    - Once the input is validated, each element is given its correct index based on the sorted order of the elements. This means that each element will have an index that reflects where it would be if the stack were sorted in ascending order.
    - The algorithm ensures there are no duplicate values, as duplicates would lead to an undefined or erroneous behavior during the sorting process. If any duplicate values are found, the program triggers an error and stops further processing.

2. **Use a dynamic range to determine which elements are pushed to stack B:**
    - Initially, define a range with a starting and ending index, based on the total number of elements in `stack A`.
    - Elements from `stack A` are then pushed to `stack B` based on their position in the sorted stack and whether their index lies within the current range:
        - **If the index of the element is within the range**, push it to stack B (via the `pb` instruction). The range is then dynamically adjusted (both the start and end of the range are incremented) to reflect the change in `stack A`.
        - **If the index of the element is greater than the current range**, leave it in `stack A` and rotate it to the top using the `ra` instruction. This helps ensure that elements outside the current range are processed later, keeping the algorithm efficient.

3. **Adjust the range dynamically for each push:**  
    - As elements are pushed from `stack A` to `stack B`, the range is adjusted by incrementing the start and end indices. This ensures that only the relevant elements are moved, and the range "shrinks" as elements are pushed into `stack B`.
    - By pushing elements based on their index in the sorted stack, the algorithm efficiently distributes elements between the two stacks.

4. **Once stack A is empty, retrieve elements from stack B in descending order:**
    - At this point, `stack A` is empty, and all elements have been pushed to `stack B` in a particular order.
    - The next step is to retrieve elements from `stack B` in descending order:
        - **Locate the maximum element** in `stack B` by checking the index of each element and identifying the largest value.
        - **Rotate or reverse-rotate stack B** to bring the maximum element to the top. The `ra` or `rra` instructions are used depending on the element's position.
        - **Push the element back to stack A** (via the `pa` instruction).

5. **Repeat until stack B is empty.**
    - This process continues until all elements are moved back from `stack B` to `stack A`, and `stack A` is completely sorted in ascending order.

### Why This Algorithm is Efficient:
- **Reduced operations:** By dynamically adjusting the range and only pushing elements within it to `stack B`, the algorithm minimizes the number of unnecessary moves.
- **Efficient handling of large datasets:** The approach is particularly effective when handling large stacks (e.g., 500 elements), as it reduces the total number of operations compared to simpler algorithms like bubble sort or insertion sort.
- **Optimization of `stack B`:** By sorting elements into `stack B` in a reverse pyramid-like structure, it ensures that when retrieving elements from `stack B`, the process is efficient and minimal in terms of rotations and reverse rotations.

This method allows for sorting large stacks in a relatively small number of operations compared to traditional sorting algorithms, making it an efficient solution for the **push_swap** project.

---

## 🌟 Achievements  

- Implemented a robust and scalable sorting algorithm.
- Mastered stack manipulation and algorithmic thinking.
- Achieved full bonus by optimizing for large datasets (e.g., 500 elements).
- Improved problem-solving skills and efficient use of memory.
- Analyzed and optimized the algorithm's time complexity, achieving efficient performance even for large stacks.

---

## 🛡️ Makefile Targets  

- `make` – Compiles the program.
- `make clean` – Removes object files.
- `make fclean` – Removes object files and the executable.
- `make re` – Cleans and recompiles everything.

---

## 📋 Objectives  

- Sort a stack using a limited instruction set.
- Optimize sorting for both small and large stacks.
- Manage stack data structures and implement custom algorithms.
- Gain expertise in sorting algorithms and their practical applications.
- Analyze and optimize the algorithm's time and space complexity for efficient performance.

---

## 🛡️ License 

This project is part of the 1337 curriculum. It is shared here for educational purposes and should not be used for plagiarism.
