//the below code snippet has a function to insert a newly created node at the very end of the circular linked list created with the create  function//
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int val;
  struct node* next;
};
struct node* create(){
  struct node* head = NULL;
  char ch;
  do{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if(temp == NULL){
      printf("\nMemory Allocation Failed!");
      exit(1);
    }
    else{
      int x;
      printf("\nEnter the value with which you want to create a node with: ");
      scanf("%d",&x);
      temp->val = x;
    }
    if(head == NULL){
      head = temp;
      head->next = head;
    }
    else{
      struct node* ptr = head;
      while(ptr->next != head){
        ptr = ptr->next;
      }
      ptr -> next = temp;
      temp -> next = head;
    }
    printf("\nTO Add More Nodes press 'Y' or 'y': ");
    scanf(" %c",&ch);
  }while(ch == 'Y' || ch == 'y');
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

void insert_at_end(struct node* head){
  struct node* ptr = head;
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  if(temp == NULL){
    printf("\n<---Memory allocation failed!--->");
    exit(1);
  }
  else{
    int x;
    printf("\nEnter the value of the node to be inserted at the end!: ");
    scanf("%d",&x);
    temp->val = x;
    temp -> next = NULL;
  }
  while(ptr->next != head){
    ptr = ptr->next;
  }
  ptr -> next = temp;
  temp -> next = head;
  return;
}

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

int main(){
  struct node* new_circular_ll = create();
  display(new_circular_ll);
  insert_at_end(new_circular_ll);
  display(new_circular_ll);
  new_circular_ll = insert_at_beginning(new_circular_ll);
  display(new_circular_ll);
  return 0;
}