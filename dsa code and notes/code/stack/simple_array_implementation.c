#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack{
    int arr[5];
    int top;
};

struct stack* create(){
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    if(temp == NULL){
        printf("\nMEMORY ALLOCATION FAILED!\n");
        exit(1);
    }
    else{
        temp -> top = -1;
    }
    return temp;
}
bool isEmpty(struct stack* st){
    if(st->top == -1) return true;
    else return false;
}
void push(struct stack* st,int val){
    if(st->top >= 5){
        printf("<---!Stack Over-Flow Error!--->");
        return;
    }
    st->top += 1;
    st->arr[st->top] = val;
}
void pop(struct stack* st){
    if(isEmpty(st)){
        printf("!Stack overflow Error!");
        return;
    }
    st->top -= 1;
}
void display(struct stack* st){
    struct stack* gt = create();
    while(!isEmpty(st)){
        push(gt,st->arr[st->top]);
        printf("%d\n",st->arr[st->top]);
        pop(st);
    }
    while(!isEmpty(gt)){
        push(st,gt->arr[gt->top]);
        pop(gt);
    }
    return;
}

int main(){
    struct stack* st = create();
    char ch;
    do{
        int x;
        printf("ENTER THE VALUE TO BE PUSHED: ");
        scanf("%d",&x);
        push(st,x);
        printf("For More Press Y: ");
        scanf(" %c",&ch);
    }while(ch == 'y' || ch == 'Y');
    display(st);
    return 0;
}