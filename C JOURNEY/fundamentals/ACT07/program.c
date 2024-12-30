// COUNT WORDS IN A FILE
#include <stdio.h>
#include <string.h>

#define PROMPT "Enter the file name: "
#define FILE_ERR "Error: File not found"
#define FALSE 0
#define TRUE 1

int isSpace(char ch){
  if(ch == ' ' || ch == '\t' || ch == '\n'){
    return TRUE;
  }

  return FALSE;
}

int main(){
  char filePath[500]= "D:/personal/coding/learning/pl/learn-programming/C JOURNEY/fundamentals/ACT07/";
  char new[100];

  printf(PROMPT);
  scanf("%s", new);
  strcat(filePath, new);

  FILE *file = fopen(filePath, "r");
  if(file == NULL){
    printf(FILE_ERR);
    return 1;
  }

  char ch;
  int wordCount = 0;
  int inWord = FALSE;
  char b;

  while((ch = fgetc(file)) != EOF){
    if(isSpace(ch)){
      if(inWord){
        wordCount++;
        inWord = FALSE;
      }
    } else {
      inWord = TRUE;
    } 
  }

  if(inWord){
    wordCount++;
  }
  
  fclose(file);
  printf("Number of words: %d", wordCount);
  return 0;
}