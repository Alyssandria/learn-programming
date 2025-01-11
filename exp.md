Suppose that we have a recursive function like this to show the steps for solving tower of hanoi

```C
void hanoi(int n, char src, char aux, char des){
  if(n == 1){
    printf("Move disk %d from %c to %c\n", n , src, des);
    return;
  }

  hanoi(n - 1, src, des, aux); // SRC TO AUX
  printf("Move disk %d from %c to %c\n", n, src, des); // PRINT
  hanoi(n - 1, aux, src, des); // SRC TO DES
};
```

And we invoked it like this:

`hanoi(3, 'A', 'B', 'C')`

This would be the step by step process inside the function

```
hanoi(3, A, B, C)
|  -  check 3 == 1 // FALSE
|  -  hanoi(2, A, C, B)
|  -  |  - check 2 == 1 // FALSE
|  -  |  - hanoi(1, A, B, C)
|  -       |  - check 1 == 1 // TRUE
|  -       |    - print = "Move disk 1 from A to C"   // LINE 1
|  -       |  END FUNC
|  -  |  - print = "Move disk 2 from A to B" // LINE 2
|  -  |  - hanoi(1, C, A, B)
|  -       | - check 1 == 1 // TRUE
|  -       |   - print = "Move disk 1 from C to B" // LINE 3
|  -       | END FUNC
|  -  | END FUNC
|
|  -  print = "Move disk 3 from A to C // LINE 4
|
|  -  hanoi(2, B, A, C)
|  -  | - check 2 == 1 // FALSE
|  -  | - hanoi(1, B, C, A)
|  -      |  - check 1 == 1 // TRUE
|  -      |  - print = "Move disk 1 from B to A" // LINE 5
|  -      |  END FUNC
|  -  | - print = "Move disk 2 from B to C" // LINE 6
|  -  | - hanoi(1, A, B, C)
|  -      |  - check 1 == 1 // TRUE
|  -      |  - print = "Move disk 1 from A to C" // LINE 7
|  -      | END FUNC
|  -  | END FUNC
|  - END FUNC
```
