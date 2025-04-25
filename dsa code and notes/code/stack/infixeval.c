#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
  int val;
  struct node* next;
};

typedef struct stack{
  struct node* top;
}; 

typedef struct char_node{
  char val;
  struct char_node* next;
}

struct stack* create(){
  struct stack* st = (struct stack*) malloc (sizeof(struct stack));
  st->top = NULL;
  return st;
}
void push(struct stack* st,int data){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  if(temp == NULL){
    printf("\n<---Memory Allocation Failed!--->");
    exit(1);
  } 
  else{
    temp->next = NULL;
    temp->val = data;
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
  int eval(int a,int b,char ch){
    if(ch == '+'){
      return b+a;
    }
    else if(ch == '*'){
      return b*a;
    }
    else if(ch == '/'){
      return b/a;
    }
    else{
      return b-a;
    }
  }

int main(){
 struct stack* st = create();
 struct stack* op = create();
 char str[]="3+5*2-4/7+1";
 int n = strlen(str);
 for(int i=0;i<n;i++){
  if(48<=(str[i])&& (str[i])<=57){
    push(st,(int)(str[i])-48);
  }
  else{
   if(op->top != NULL){
    op->top
   }
  }
 }
 printf("%d is the ans of the given postfix expression",st->top->val);
 return 0;
}
///stack implementation with the help of linked list is now completed!