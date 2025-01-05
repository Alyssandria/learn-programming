// BINARY SEARCH

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define FOUND "Found" 
#define NOT_FOUND "Not Found"
#define INT_ERR "Error. Invalid Integer!"

#define LEN_PROMPT "Enter the size of the array: "
#define EL_PROMPT "Enter elements: "
#define SEARCH_PROMPT "Enter the number to search for: "

int* sortArr(int* arr, int length){
  // BUBBLE SORT IMPLEMENTATION 
  for(int i = 0; i < length - 1; i++){
    int swapped = FALSE;
    for(int j = 0; j < length - i - 1; j++){
      if(arr[j] > arr[j + 1]){
        int curr = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = curr;
        swapped = TRUE;
      }
    }

    if(!swapped){
      break;
    }
  }
  return arr;
}

int binarySearch(int* arr, int searchVal, int length){
  int low = 0;
  int high = length - 1;

  arr = sortArr(arr, length);

  while(low <= high){
    int median = low + (high - low) / 2;

    if(arr[median] == searchVal){
      return median;
    }

    if(searchVal > arr[median]){
      low = median + 1;
    } else{
      high = median - 1;
    }
  }

  return -1;
}
int main(){
  int length = 0;

  printf(LEN_PROMPT);
  if(!scanf("%d", &length)){
    printf(INT_ERR);
    return 1;
  }


  printf(EL_PROMPT);

  int* arr = malloc(length * sizeof(int));
  for(int i = 0; i < length; i++){
    scanf("%d", &arr[i]);
  }

  printf(SEARCH_PROMPT);
  int searchVal;
  if(!scanf("%d", &searchVal)){
    printf(INT_ERR);
    return 1;
  }
  int result = binarySearch(arr, searchVal, length);
  if(result != -1){
    printf(FOUND);
  } else{
    printf(NOT_FOUND);
  }
  return 0;
}