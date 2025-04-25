#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int val;
  struct node* next;
};
typedef struct queue{
  struct node* front;
  struct node* rear;
};
struct queue* create(){
  struct queue* q = (struct queue*)malloc(sizeof(struct queue));
  q->front = NULL;
  q->rear = NULL;
  return q;
}
void push(struct queue* q){
 struct node* temp = (struct node*)malloc(sizeof(struct node));
 if(temp == NULL){
  printf("\n<---!Memory Allocation failed!--->\n");
  return;
 }
 else{
  int x;
  printf("\n<---Enter the value to be pushed!--->\n\n");
  scanf("%d",&x);
  temp->val = x;
  temp->next = NULL;
 }
 if(q->rear == NULL){
  q->rear = temp;
  q->front = temp;
 }
 else{
  q->rear->next = temp;
  q->rear = temp;
 }
}
void pop(struct queue* q){
  if(q->front == NULL){
    printf("\n<---Queue Underflow! error!--->\n");
    return;
  }
  else{
    struct node* temp = q->front;
    q->front = q->front->next;
    free(temp);
  }
}
void display(struct queue* q){
  struct node* ptr = q->front;
  while(ptr!=NULL){
    printf("%d\n",ptr->val);
    ptr = ptr->next;
  }
  return;
}
int main(){
  struct queue* q = create();
  char ch;
  char ml;
  do{
    printf("\n<---for popping press 'P'--->");
    printf("\n<---for pushing press 'p'--->");
    printf("\n<---for display press 'd'--->\n\n");
    scanf(" %c",&ml);
    if(ml == 'P') pop(q);
    else if(ml == 'p'){
      push(q);
    }
    else{
      display(q);
    }
    printf("for more operation press 'y': ");
    scanf(" %c",&ch);
  }while(ch == 'y' || ch == 'Y');
  return 0;
}