// REVERSING A SINGLY LINKED LIST
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
} Node;

Node* reverse(Node* head){
  Node* ptr_current = head;
  Node* ptr_next = NULL;
  Node* ptr_prev = NULL;

  while(ptr_current != NULL){
    ptr_next = ptr_current->next;
    ptr_current->next = ptr_prev;
    ptr_prev = ptr_current;
    ptr_current = ptr_next;
    head = ptr_prev;
  }
  return head;
}

int main(){
  // INITIALIZE 5 NODE INSTANCES
  Node* ptr_head = malloc(sizeof(Node));
  Node* ptr_node1 = malloc(sizeof(Node));
  Node* ptr_node2 = malloc(sizeof(Node));
  Node* ptr_node3 = malloc(sizeof(Node));
  Node* tail = malloc(sizeof(Node));

  // ASSIGNMENTS

  // HEAD
  ptr_head->data = 1;
  ptr_head->next = ptr_node1;

  // NODE 1
  ptr_node1->data = 2;
  ptr_node1->next = ptr_node2;

  // NODE2
  ptr_node2->data = 3;
  ptr_node2->next = ptr_node3;

  // NODE 3
  ptr_node3->data = 4;
  ptr_node3->next = tail;

  // TAIL
  tail->data = 5;
  tail->next = NULL;

  printf("\nLinked List\n");

  Node* ptr_current = ptr_head;
  printf("Original list: ");
  while(ptr_current != NULL){
    if(ptr_current->next != NULL){
      printf("%d -> ", ptr_current->data);
    } else{
      printf("%d", ptr_current->data);
    }
    ptr_current = ptr_current->next;
  }

  printf("\n\n");
  printf("Reversed list: ");
  Node* ptr_reversed = reverse(ptr_head);
  while(ptr_reversed != NULL){
    if(ptr_reversed->next != NULL){
      printf("%d -> ", ptr_reversed->data);
    } else{
      printf("%d", ptr_reversed->data);
    }

    ptr_reversed = ptr_reversed->next;
  }
  
  return 0;
}