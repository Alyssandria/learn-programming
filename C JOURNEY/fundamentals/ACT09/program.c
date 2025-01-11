// RECURSIVE TOWER OF HANOI
#include <stdio.h>

#define PROMPT "Enter the number of disks: " 
#define INT_ERR "Error. Please enter a valid integer"
#define CONSTRAINT_ERR "Integer must not be less than 1 or greater than 10."

// RODS
#define A 'A'
#define B 'B'
#define C 'C'

void hanoi(int n, char src, char aux, char des){
  if(n == 1){
    printf("Move disk %d from %c to %c\n", n , src, des);
    return;
  }

  hanoi(n - 1, src, des, aux);
  printf("Move disk %d from %c to %c\n", n , src, des);
  hanoi(n-1, aux, src, des);

}

int main(){
  int disk;

  printf(PROMPT);

  if(scanf("%d", &disk) != 1){
    printf(INT_ERR);
    return 1;
  }

  if(disk <= 0 || disk > 10){
    printf(CONSTRAINT_ERR);
    return 1;
  }

  hanoi(disk, A, B, C);
  return 0;
}