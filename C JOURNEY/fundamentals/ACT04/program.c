// PRIME NUMBER CHECKER
#include <stdio.h>

#define INPPROMPT "Enter an integer: "
#define INPERR "Error: Must be a valid integer"
#define PRIME "Prime"
#define NOTPRIME "Not Prime"
#define INVERR "Integer must be greater than 1!"
int main(){
  int num; 

  printf(INPPROMPT);
  if(!scanf("%d", &num)){
    printf(INPERR);
    return 1;
  }

  if(num <= 1){
    printf(INVERR);
    return 1;
  }

  for(int i = 2; i < num; i++){
    if(num % i == 0){
      printf(NOTPRIME);
      break;
    }else{
      printf(PRIME);
      break;
    }
  }
  return 0;
}