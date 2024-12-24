// ODD OR EVEN
#include <stdio.h>
#include <stdbool.h>

#define PROMPT "Enter an integer: "
#define ERRMSG "Error: Enter a valid integer"
#define ODD "ODD\n"
#define EVEN "EVEN\n"
#define RETRYPROMPT "Do you want to try again? [y/n]: "

int main(){
  int num;
  char choice;

  bool retry;
  do{
  printf(NUM_PROMPT);
  if(!scanf("%d", &num)){
    printf(ERRMSG);
    return 1;
  }

  if(num % 2 == 1){
    printf(ODD);
  } else {
    printf(EVEN);
  }

  // ASK RETRY
  printf(RETRYPROMPT);
  scanf(" %c", &choice);

  if(choice == 'y'){
    retry = true;
  }else{
    retry = false;
  }
  } while(retry);
  
  return 0;
}