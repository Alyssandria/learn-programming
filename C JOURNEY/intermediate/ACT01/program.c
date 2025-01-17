// MATRIX TRANSPOSE AND SYMMETRY CHECK
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PROMPT "Enter the size of the matrix: "
#define EL_PROMPT "Enter the elements of the matrix: \n"
#define INV_ERR "Error. Must be a valid integer"
#define SIZE_ERR "Error. Invalid size, must be inside 1 - 10 range"
#define MEM_ERR "Memory Allocation Failed"
#define TRANSPOSE_PROMPT "Transpose of the matrix: \n" 

typedef struct {
  int **matrix;
  int** (*transpose)(int **matr, int size);
  bool (*isSymmetric)(int **matr, int size);
} Matrix;

bool isSymm(int **matr, int len){
  for(int i = 0; i < len; i++){
    for(int j = 0; j < len; j++){
      if(matr[i][j] != matr[j][i]){
        return false;
      }
    }
  }

  return true;
}
int **allocate_matr(int size){
  int **matr = (int **)malloc(sizeof(int *) * size);
  if(matr == NULL){
    printf(MEM_ERR);
    exit(1);
  }
  for(int i = 0; i < size; i++){
    matr[i] = (int *)malloc(sizeof(int) * size);
    if(matr[i] == NULL){
      printf(MEM_ERR);
      exit(1);
    }
  }
  return matr;
}

int **transpose(int **matr, int len){
  int **trans = allocate_matr(len); // CREATES ANOTHER FOR TRANSPOSE VERSION

  for(int i = 0; i < len; i++){
    for(int j = 0; j < len; j++){
      trans[i][j] = matr[j][i];
    }
  }

  return trans;
}

void free_matr(int **matr, int size){
  for(int i = 0; i < size; i++){
    free(matr[i]);
  }

  free(matr);
}

// CONSTRUCTOR
Matrix *new_matrix(int size){
  Matrix *matr = malloc(sizeof(Matrix));
  matr->matrix = allocate_matr(size);
  matr->transpose = transpose;
  matr->isSymmetric = isSymm;


  return matr;
}

int main(){
  // INITIALIZE
  int size;

  printf(PROMPT);

  if(scanf("%d", &size) != 1){
    printf(INV_ERR);
    return 1;
  }

  if(size < 1 || size > 10){
    printf(SIZE_ERR);
    return 1;
  }

  // ALLOCATE MATRIX
  Matrix *matr = new_matrix(size);

  // GET USER INPUT
  printf(EL_PROMPT);
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      if(scanf("%d", &matr->matrix[i][j]) != 1){
        printf(INV_ERR);
        return 1;
      }
    }
  }

  // TRANSPOSES THE USER MATRIX WITHOUT ALTERING USER INPUT
  printf(TRANSPOSE_PROMPT);
  int **transMatr = matr->transpose(matr->matrix, size);
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      printf("%d ", transMatr[i][j]);
    }
    printf("\n");
  }

  printf("The matrix is %s symetrical", matr->isSymmetric(matr->matrix, size) ? "" : "not");

  free_matr(matr->matrix, size);
  free_matr(transMatr, size);
  free(matr);
  return 0;
}
