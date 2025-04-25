#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int val;
  struct node* next;
};

typedef struct stack{
  struct node* top;
};

struct stack* create(){
  struct stack* st = (struct stack*) malloc (sizeof(struct stack));
  st->top = NULL;
  return st;
}
void push(struct stack* st){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  if(temp == NULL){
    printf("\n<---Memory Allocation Failed!--->");
    exit(1);
  } 
  else{
    int x;
    temp->next = NULL;
    printf("Enter the value to be pushed: ");
    scanf("%d",&x);
    temp->val = x;
  }
  if(st -> top == NULL){
    st -> top = temp;
  }
  else{
    temp->next = st->top;
    st->top = temp;
  }
  return;
}
void pop(struct stack* st){
  if(st->top == NULL){
    printf("\n<---Stack Underflow Error!--->");
    return;
  }
  struct node* temp = st->top;
  st->top = st->top->next;
  free(temp);
  return;
}
  void display(struct stack* st){
    struct node* ptr = st->top;
    while(ptr){
      printf("%d\n",ptr->val);
      ptr = ptr->next;
    }
    return;
  }

int main(){
  struct stack* st = create();
  char ch;
  char ml;
  do{
    printf("\n<---for popping press 'P'--->");
    printf("\n<---for pushing press 'p'--->");
    printf("\n<---for display press 'd'--->\n\n");
    scanf(" %c",&ml);
    if(ml == 'P') pop(st);
    else if(ml == 'p')push(st);
    else{
      display(st);
    }
    printf("for more operation press 'y': ");
    scanf(" %c",&ch);
  }while(ch == 'y' || ch == 'Y');
  display(st);
  return 0;
}
///stack implementation with the help of linked list is now completed!