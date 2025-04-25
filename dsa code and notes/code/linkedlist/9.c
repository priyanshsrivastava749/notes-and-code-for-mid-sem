//the code is particularly targetting towards deletion of the node of a linked list from beginning
//the following function targets to reverse a linked list by using three pointer algorithm
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
  int val;
  struct node* next;
};
struct node* create(){
  char ch;
  struct node* head = NULL;
  do
  {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if(temp == NULL){
      printf("\nMemory allocation failed!: ");
      exit(1);
    }
    else{
      int x;
      temp->next = NULL;
      printf("\nENTER THE NUMBER YOU WANT TO ADD TO LINKED LIST: ");
      scanf("%d",&x);
      temp -> val = x;
    }
    if(head == NULL){
      head = temp;
    }
    else{
      struct node* ptr = head;
      while(ptr->next){
        ptr = ptr->next;
      }
      ptr->next = temp;
    }
    printf("\npress 'y' or 'Y' for more nodes to be added: ");
    scanf(" %c",&ch);
  }while(ch == 'y' || ch == 'Y');
  return head;
}
void display(struct node* head){
  printf("\n\n");
  struct node* ptr = head;
  while(ptr){
    printf("%d->",ptr->val);
    ptr = ptr->next;
  }
  printf("NULL");
  return;
}
//three pointer algorithm
struct node* reverse_ll(struct node* head){
  struct node* prev= NULL;
  struct node* curr = head;
  struct node* NEXT = curr->next;
  while(curr){
    curr->next = prev;
    prev = curr;
    curr = NEXT;
    if(curr)NEXT = curr->next;
  }
  head = prev;
  return head;
}
void display_reverse(struct node* head){
  struct node* ptr = head;
  if(ptr->next != NULL){
   display_reverse(ptr->next);
  }
  printf("%d->",ptr->val);
  return;
}
struct node* delete_at_beginning(struct node* head){
  head  = head->next;
  return head;
}
int main(){
  struct node* firstll = create();
  display(firstll);
  firstll = delete_at_beginning(firstll);
   display(firstll);
  return 0;
}