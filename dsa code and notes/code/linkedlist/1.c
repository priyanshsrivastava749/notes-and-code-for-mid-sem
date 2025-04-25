#include<stdio.h>
#include<stdlib.h>
void create();
typedef struct node{
  int val;
  struct node* next;
};
int main(){
  create();
  return 0;
}
void create(){
  struct node* head = NULL;
  char ch;
  do
  { 
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if(temp == NULL){
      printf("Memory Allocation Failed!");
    }
    else{
      int x;
      printf("Enter the number you want to be added to the end of ll: ");
      scanf("%d",&x);
      temp->val = x;
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
    printf("IF YOU WANT MORE NODES TO BE ADDED: ");
    scanf(" %c",&ch);
  } while(ch=='y'||ch =='Y');
  struct node* ptr = head;
  while(ptr != NULL){
    printf("%d ",ptr->val);
    ptr = ptr->next;
  }
  return;
}