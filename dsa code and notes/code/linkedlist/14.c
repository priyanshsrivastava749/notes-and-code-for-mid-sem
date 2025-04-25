// the code below demonstrates the implementation of a circular linked list  and insertion of element at the very beginning of the circular linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int val;
  struct node* next;
};

struct node* create(){
  char ch;
  struct node* head = NULL;
  do{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if(temp == NULL){
      printf("Memory Allocation Failed!");
      exit(1);
    }
    else{
      int x;
      printf("\nENTER THE VALUE OF NODE: ");
      scanf("%d",&x);
      temp->val = x;
    }
    if(head == NULL){
      head = temp;
      head -> next = head;
    }
    else{
      struct node* ptr = head;
      while(ptr->next != head){
        ptr = ptr -> next;
      }
      ptr -> next = temp;
      temp -> next = head;
    }
    printf("\nFor More Nodes Press 'y' or 'Y': ");
    scanf(" %c",&ch);
  }while(ch == 'Y' || ch == 'y');
  return head;
};
struct node* insert_at_beginning(struct node* head){
  struct node* temp = (struct node*) malloc (sizeof(struct node));
  if(temp == NULL){
    printf("Memory allocation Failed!");
    exit(1);
  }
  else{
    int x;
    printf("\nEnter the value of the node to be inserted at the beginning: ");
    scanf("%d",&x);
    temp->val = x;
  }
  if(head == NULL){
    head = temp;
    head->next = head;
    return head;
  }
  struct node* ptr = head;
  while(ptr->next != head){
    ptr = ptr->next;
  }
  temp -> next = head;
  ptr -> next = temp;
  head = temp;
  return head;
}
void display(struct node* head){
  struct node* ptr = head;
  while(ptr->next != head){
    printf(" %d ->",ptr->val);
    ptr = ptr->next;
  }
  printf(" %d",ptr->val);
  return;
}
int main(){
  struct node* first_circular_ll = create();
  first_circular_ll = insert_at_beginning(first_circular_ll);
  display(first_circular_ll);
  return 0;
}