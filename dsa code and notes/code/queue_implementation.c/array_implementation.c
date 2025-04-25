#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct queue{
  int arr[5];
  int front;
  int rear;
};

struct queue* create(){
  struct queue* q = (struct queue*)malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

void push(struct queue* q,int val){
  if(q->rear<=4){
    if(q->front == -1 && q->rear == -1){
      q->front = 0;
      q->rear = 0;
    }
   q->arr[q->rear] = val;
   q->rear++;
  }
  else {
    printf("<---\nQueue Overflow!--->");
    return;
  }
};

void pop(struct queue* q){
  if(q->front == -1){
    printf("\n!Queue is already empty!");
    return;
  }
  else{
    q->front++;
    return;
  }
}

void display(struct queue* q){
  if(q->front == -1 && q->rear == -1){
    return;
  }
  for(int i=q->front;i<=q->rear-1;i++){
    printf("%d\n",q->arr[i]);
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
      int x;
      printf("\n<---Enter value to be pushed in queue!--->");
      scanf("%d",&x);
      push(q,x);
    }
    else{
      display(q);
    }
    printf("for more operation press 'y': ");
    scanf(" %c",&ch);
  }while(ch == 'y' || ch == 'Y');
   return 0;
}