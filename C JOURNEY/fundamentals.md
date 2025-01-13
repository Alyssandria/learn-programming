# FUNDAMENTAL ACTIVITIES

## ACTIVITY 1: Hello, World!

Problem

- Write a program that prints "Hello, World!" to the console. Extend the program to take a user's name as
  input and greet them.

Description

1. First, create a program that outputs the text "Hello, World!" using printf.
2. Extend the program to accept the user's name as input and display a personalized greeting:
   "Hello, [Name]!"

Constraints

- Use only stdio.h for input and output.
- Ensure the program handles up to 50 characters for the name.

Output

- A greeting message printed to the console.

```
  Expected Output
  Hello, World!
  What is your name? John
  Hello, John!
```

## ACTIVITY 2: Basic Math Operations

Problem

- Create a simple calculator that performs addition, subtraction, multiplication, and division of two
  integers.

Description

1. Prompt the user to input two integers and a choice of operation (+, -, \*, /).
2. Perform the operation and display the result.
3. Handle invalid operations gracefully.

Constraints

- Only integer inputs are allowed.
- Division by zero should display an error message.

Output

- The result of the operation or an error message.

```
Expected Output

Example 1:
Enter first number: 10
Enter second number: 5
Enter operation (+, -, *, /): *
Result: 50

Example 2:
Enter first number: 10
Enter second number: 0
Enter operation (+, -, *, /): /
Error: Division by zero is not allowed.
```

## ACTIVITY 3: EVEN OR ODD

Problem

- Write a program to determine whether a given integer is even or odd.

Description

1. Prompt the user for an integer.
2. Check if the number is divisible by 2.
3. Output "Even" if true, otherwise "Odd."

Constraints

- Only integer input is allowed.

Output

- A single word: "Even" or "Odd."

```
  Expected Output
  Example 1:
  Enter an integer: 8
  Even

  Example 2:
  Enter an integer: 13
  Odd
```

## ACTIVITY 4: PRIME NUMBER CHECKER

Problem

- Determine if a given integer is a prime number.

Description

1. Prompt the user for an integer greater than 1.
2. Check if it is divisible only by 1 and itself.
3. Output "Prime" or "Not Prime."

Constraints

- Input must be greater than 1.
- Use a loop to check divisibility.

Output

- A single word: "Prime" or "Not Prime."

```
  Expected Output
  Example 1:
  Enter an integer: 7
  Prime
  Example 2:
  Enter an integer: 10
  Not Prime
```

## Activity 5: Reverse a Linked List

Problem

- Write a program to reverse a singly linked list.

Description

1. Create a linked list with a node structure.
2. Implement a function to reverse the list.
3. Display the list before and after reversal.

Constraints

- Use a linked list structure to implement the reversal.
- Display the list after reversal.

Output

- The linked list before and after reversal.

```
  Expected Output
  Example 1:
  Original list: 1 -> 2 -> 3 -> 4
  Reversed list: 4 -> 3 -> 2 -> 1
```

# Activity 6: Function Pointer

Problem

- Write a program that uses function pointers to perform basic arithmetic operations.

Description

1. Implement functions for addition, subtraction, multiplication, and division.
2. Use function pointers to call these functions based on user input.
3. Display the result of the chosen operation.

Constraints

- Use function pointers to dynamically call the appropriate operation.
- Ensure that division by zero is handled gracefully.

Output

- The result of the selected operation.

```
  Expected Output
  Example 1:
  Enter two numbers: 10 5
  Enter operation (+, -, _, /): +
  Result: 15

  Example 2:
  Enter two numbers: 10 0
  Enter operation (+, -, _, /): /
  Error: Division by zero is not allowed.
```

# Activity 7: File I/O - Count Words in a File

Problem

- Write a program that reads a file and counts the number of words in it.

Description

1. Prompt the user for the file name.
2. Open the file and read its contents.
3. Count the number of words (separated by spaces) and display the count.

Constraints

- Handle cases where the file might not exist.
- The file can contain multiple lines.

Output

- The number of words in the file.

```
Expected Output
Example 1:
Enter the file name: test.txt
Number of words: 120

Example 2:
Enter the file name: test.txt
Error: File not found.
```

# Activity 8: Binary Search

Problem

- Implement the binary search algorithm to search for a value in a sorted array.

Description

- Prompt the user for the size of the array and the value to search for.
- Sort the array if necessary.
- Implement the binary search algorithm and display whether the value is found or not.

Constraints

1. Only integer arrays.
2. The array should be sorted before performing the search.

Output

- "Found" or "Not Found" message.

```
Expected Output

Example 1:
Enter the size of the array: 5
Enter elements: 1 3 5 7 9
Enter the number to search for: 5
Found

Example 2:
Enter the size of the array: 5
Enter elements: 1 3 5 7 9
Enter the number to search for: 6
Not Found
```

# Activity 9: Recursion - Tower of Hanoi

Problem

- Write a recursive function to solve the Tower of Hanoi puzzle.

Description

- Implement a recursive function that moves disks from one peg to another while following the rules of the Tower of Hanoi.
  Prompt the user for the number of disks and display the series of moves.

- Constraints

- The number of disks should be between 1 and 10.

Output

- The steps required to solve the puzzle.

```
Expected Output

Example 1:
Enter the number of disks: 3
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
```

# Activity 10: Implementing Stack Using Arrays

Problem

- Write a program to implement a stack using arrays.

- Description
- Create a stack data structure using an array.
- Implement basic operations: push, pop, peek, and is_empty.
- Prompt the user for operations to perform on the stack.

Constraints

1. The stack should have a maximum size of 100 elements.
2. Handle underflow and overflow conditions.

Output

- The result of the stack operations.

```
Expected Output

Example 1:
Enter operation (push, pop, peek, exit): push 10
Enter operation (push, pop, peek, exit): push 20
Enter operation (push, pop, peek, exit): pop
Popped value: 20
```
