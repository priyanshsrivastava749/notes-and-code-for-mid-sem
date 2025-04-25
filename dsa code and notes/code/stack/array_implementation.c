#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct stack{
  int *arr;
  int top;
  int capacity;
};

struct stack* create(int size){
  struct stack* temp = (struct stack*) malloc(sizeof(struct stack));
  temp -> capacity = size;
  temp -> top = -1;
  temp -> arr = (int*) malloc(size * sizeof(int));
  return temp;
};

void push(struct stack* st,int val){
  if(st->top >= (st->capacity - 1)){
    printf("\nSTACK-OVERFLOW ERROR!");
    return;
  }
    st->top = st->top + 1;
    st -> arr[st->top] = val; 
}

void pop(struct stack* st){
  if(st->top == -1){
    printf("<--\nSTACK-UNDERFLOW!-->");
    return;
  }
    st->top -= 1;
    return;
}
bool isEmpty(struct stack* st){
  if(st->top == -1){
    return true;
  }
  return false;
}

void display(struct stack* st){
  struct stack* gt = create(st->capacity);
  if(isEmpty(st)){
    return;
  }
  while(!(isEmpty(st))){
    printf("%d\n",st->arr[st->top]);
    push(gt,st->arr[st->top]);
    pop(st);
  }
  while(!isEmpty(gt)){
      push(st,gt->arr[gt->top]);
      pop(gt);
  }
return;
}
int main(){
  int size;
  printf("Enter the size of stack!: ");
  scanf("%d",&size);
  struct stack* st = create(size);
  char ch;
  do{
    int pushval;
    printf("Enter value to be pushed in stack!: ");
    scanf("%d",&pushval);
    push(st,pushval);
    scanf(" %c",&ch);
  }while(ch == 'y' || ch == 'Y');
  display(st);
  printf("\n");
  pop(st);
  display(st);
  return 0;
}