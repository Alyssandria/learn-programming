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
