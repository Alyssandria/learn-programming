// FUNCTION POINTERS

#include <stdio.h>

// CONSTANT DEFINITIONS
#define INT_ERR "Error. Please enter a valid number!"
#define NUM_PROMPT "Enter two numbers: "
#define OP_ERR "Error. Please Enter a valid Operation!"
#define OP_PROMPT "Enter operation(+, -, *, /) "
#define DIV_ERR "Error. Divisor with a value of 0 is undefined"

// FUNCTION DEFINITIONS
int add(int num1, int num2){
  return num1 + num2;
}

int subtract(int num1, int num2){
  return num1 - num2;
}

int multiply(int num1, int num2){
  return num1 * num2;
}

int divide(int num1, int num2){
  return num1 / num2;
}

typedef struct {
  char operator;
  int (*operation)(int, int);
} Operation;

int main(){
  // INITIALIZE
  int num1;
  int num2;
  char op;
  Operation operations[] = {
    {'+', add},
    {'-', subtract},
    {'*', multiply},
    {'/', divide},
  };
  int max = sizeof(operations) / sizeof(Operation);

  printf("%d", max);

  // USER PROMPT
  printf(NUM_PROMPT);
  if(scanf("%d %d", &num1, &num2) != 2){ 
    printf(INT_ERR);
    return 1;
  }

  printf(OP_PROMPT);
  scanf(" %c", &op);

  for(int i = 0; i < max; ++i ){
    if(operations[i].operator == op){
      if(num2 == 0 && op == '/'){
        printf(DIV_ERR);
        return 1;
      }
      printf("Result: %d", operations[i].operation(num1, num2));
    }
  }
  return 0;
}