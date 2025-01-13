// STACKS USING ARRAYS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define OVERFLOW_ERR "Overflow Error. Exceeding the maximum capacity"
#define UNDERFLOW_ERR "Underflow Error. There is no element in the stack currently"
#define PROMPT "Enter operation (push, pop, peek, exit): "
#define INV_ERR "Error. Invalid Input"
#define MEM_ERR "Error. Memory Allocation Failed\n"

typedef struct stack{
  // PRIVATE
  int _top;  

  int length;
  int nodes[MAX_SIZE];  
  void (*push)(struct stack*, int);
  int (*pop)(struct stack*);
  int (*destroy)(struct stack*);
  int (*peek)(struct stack*);
  int (*is_empty)(struct stack*);
} Stack;

void push(Stack *self, int n){
  if(self->length == MAX_SIZE){
    printf(OVERFLOW_ERR);
    return; 
  }
  self->_top++;
  self->nodes[self->_top] = n;
  self->length++;
}

int destroy(Stack** self){
  if(*self){
    free(*self);
    *self = NULL;
    printf("The stack has been destroyed. All memories have been freed");
  }
  return 0;
}

int pop(Stack *self){
  if(self->_top == -1){
    printf(UNDERFLOW_ERR);
    exit(0);
  }
  int popped = self->nodes[self->_top]; // SAVE THE POPPED NODE
  self->nodes[self->_top] = -1; // "DELETE" THE TOP OF THE STACK
  self->_top--;
  self->length--;
  return popped; 
}

int peek(Stack *self){
  if(self->length == 0){
    printf(UNDERFLOW_ERR);
    return - 1;
  }
  return self->nodes[self->_top];
}

int is_empty(Stack *self){
  return self->length == 0;
}

// CONSTRUCTOR
Stack* new_stack(){ 
  // INITIALIZATION
  Stack* stack = malloc(sizeof(Stack));

  if(!stack){
    printf(MEM_ERR);
    exit(0);
  }
  stack->_top = -1;
  stack->length = 0;
  stack->peek = peek;
  stack->push = push;
  stack->pop = pop;
  stack->destroy = destroy;
  stack->is_empty = is_empty;

  return stack;
}

void testOverflow(Stack* stack){
  int size = sizeof(stack->nodes) / sizeof(int);

  // SHOULD ERROR AFTER 99 IF EMPTY
  for(int i = 0; i <= size; i++){
    stack->push(stack, i);
    printf("%d \n", stack->nodes[i]);
  }
}

int main(){
  // INITIALIZATIONS
  Stack *stack = new_stack();
  int val;
  char options[4][10] = {"pop", "peek","exit", "push"};
  int optLen = 4;
  int (*operations[])(Stack*) = {stack->pop, stack->peek, stack->destroy};
  char inp[10];

  do
  {
    printf(PROMPT);
    if(scanf("%s", &inp) == 0){
      printf(INV_ERR);
      return 1;
    }

    for(int i = 0; i < optLen; i++) {
      if(strcmp(inp, options[i]) == 0){
        if(i == 3){
          if(scanf("%d", &val) == 0){
            printf(INV_ERR);
            return 1;
          }

          stack->push(stack, val);
          break;
        }
        if(i == 0){
          printf("Popped value: %d\n", operations[i](stack));
          break;
        }
        if(i == 1){
          printf("Top value: %d\n", operations[i](stack));
          break;
        }

        operations[i](stack);
      }
    }
  } while (strcmp(inp, options[2]) != 0);

  

  // testOverflow(stack); // TEST THE OVERFLOW ERROR
}