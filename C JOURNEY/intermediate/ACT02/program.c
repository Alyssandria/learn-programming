// IMPLEMENT A QUEUE USING LINKED LIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT "Enter operation (enqueue, dequeue, display, exit): "
#define STRING_ERR "Error. Please enter a valid input\n"
#define UNDER_ERR "Underflow Error. Queue is currently empty"
#define INT_ERR "Please enter a valid integer value\n"
#define EMPTY_PROMPT "Queue is currently empty. Add one now\n"
#define OP_ERR "Error. Please Enter a valid operation! \n"
#define INV_OP_ERR "Please enter a valid operation! \n"

typedef struct linkedlist{
  int data;
  struct linkedlist *next; 
} LinkedList;

typedef struct queue{
  LinkedList *list;
  LinkedList *tail;
  LinkedList *head;
  LinkedList *(*enq)(struct queue *queue, int val);
  int (*deq)(struct queue *queue);
  int length;
} Queue;

// QUEUE METHODS/OPERATIONS
LinkedList *enq(Queue *queue, int val){
  LinkedList *new_list = (LinkedList *)malloc(sizeof(LinkedList));
  new_list->data = val;
  new_list->next = NULL;

  // CHECK IF EMPTY
  if(queue->head == NULL){
    queue->head = new_list;
    queue->list = queue->head;
  } 

  if(queue->tail == NULL){
    queue->tail = new_list;
  }else{
    queue->tail->next = new_list;
    queue->tail = new_list;
  }

  queue->length++;
  return queue->list;
}

int deq(Queue *queue){
  if(!queue->length){
    printf(UNDER_ERR);
    exit(1);
  }

  LinkedList *next = queue->head->next;
  int deqVal = queue->head->data;
  queue->head = next;
  queue->list = queue->head;
  queue->length--;

  return deqVal;
}

// CONSTRUCTOR
Queue *new_queue(){
  // INITIALIZATION
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  
  queue->head = NULL;
  queue->tail = NULL;
  queue->list = queue->head;
  queue->length = 0;

  queue->enq = enq;
  queue->deq = deq;


  return queue;
}

int main(){  
  // INIZIALIZE
  char choice[10];
  char operations[4][10] = {"enqueue", "dequeue", "display", "exit"};
  Queue *q = new_queue();

  do{
    printf(PROMPT);
    if(scanf("%s", choice) != 1){
      printf(STRING_ERR);
      break;
    };

    if(strcmp(choice, operations[0]) == 0){
      int val;
      if(scanf("%d", &val) != 1){
        printf(INT_ERR);
      }
      q->enq(q, val);
    }
    else if(strcmp(choice, operations[1]) == 0) {
      printf("Dequeued value: %d", q->deq(q));
    } else if (strcmp(choice, operations[2]) == 0){
      LinkedList *current = q->list;
      if(!current){
        printf(EMPTY_PROMPT);
      }
      while(current != NULL){
        printf("%d %s ", current->data, current->next == NULL ? "" : "->");
        current = current->next;
      }
    } else if (strcmp(choice, operations[3]) == 0){
      free(q);
      break;
    } else {
      printf(INV_OP_ERR);
    }
  } while(1);
}