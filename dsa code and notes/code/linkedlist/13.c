// the code below demonstrates the implementation of a circular linked list 
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
  display(first_circular_ll);
  return 0;
}