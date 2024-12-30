// COUNT WORDS IN A FILE
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#define getCurrDir() GetCurrentDirectoryA(MAX_PATH, filePath)
#else
#include <unistd.h>
#define getCurrDir() getcwd(filePath, sizeof(filePath))
#endif

#define PROMPT "Enter the file name: "
#define FILE_ERR "Error: File not found"
#define DIR_ERR "Error. There's a problem getting your current directory"
#define FALSE 0
#define TRUE 1

int isSpace(char ch){
  if(ch == ' ' || ch == '\t' || ch == '\n'){
    return TRUE;
  }
  return FALSE;
}

int main(){
  // INITIALIZE
  char filePath[MAX_PATH]; // STORAGE OF CURRENT DIRECTORY
  
  if(getCurrDir() == NULL){
    printf(DIR_ERR);
    return 1;
  }

  strcat(filePath, "\\");
  char userFile[100];

  printf(PROMPT);
  scanf("%99s", &userFile);
  strcat(filePath, userFile);

  FILE *file = fopen(filePath, "r");
  if(file == NULL){
    printf(FILE_ERR);
    return 1;
  }

  char ch;
  int wordCount = 0;
  int inWord = FALSE;

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