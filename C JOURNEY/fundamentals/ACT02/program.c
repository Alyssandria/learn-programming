// BASIC MATH

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ERRMSG "Error: Must be a valid integer"
#define INVOP "Error: Invalid Operation" 
#define ERR "There's something wrong. Please Try again later" 
#define INVDIV "Error: Division by zero is not allowed"
#define PROMPT1 "Enter the first number: " 
#define PROMPT2 "Enter the second number: " 
#define PROMPTOP "Enter Operation (+,-,*,/): " 
#define RETRYPROMPT "Do you want to retry? [y/n]: "

int main(){
  int num1;
  int num2;
  char op; 
  int result;
  char choice;
  bool isRetry = false; 

  do{
  
  // PROMPT USER 
  printf(PROMPT1);
  if(!scanf("%d", &num1)){
    printf(ERRMSG);
    return 1;
  }

  // PROMPT USER 
  printf(PROMPT2);
  if(!scanf("%d", &num2)){
    printf(ERRMSG);
    return 1;
  }
  
  // PROMPT USER 
  printf(PROMPTOP);
  scanf(" %c", &op);

  // HANDLE INVALID OPERATION
  if(op != '+' && op != '/' && op != '*' && op != '-'){
    printf(INVOP);
    return 1;
  }

  // HANDLE UNDEFINED DIVISION
  if(op == '/' && num2 == 0){
    printf(INVDIV);
    return 1;
  }

  // HANDLE COMPUTATION
  switch(op){
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '/':
      result = num1 / num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    default:
      printf(ERR);
      return 1;
  }

  // DISPLAY RESULT
  printf("Result: %d\n", result);

  // ASK FOR REDO
  printf(RETRYPROMPT);
  scanf(" %c", &choice);

  if(choice == 'y'){
    isRetry = true;
  }else{
    isRetry = false;
  }
  } while(isRetry);
  
  return 0;
}
