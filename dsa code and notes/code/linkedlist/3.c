//to find the presence of an element in the linked list
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
  do{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if(temp == NULL){
      printf("memory allocation failed!");
    }
    else{
      int x;
      printf("Enter the number you want to create node with: ");
      scanf("%d",&x);
      temp -> val = x;
    }
    if(head == NULL){
      head = temp;
    }
    //to uppend the newly made temp node to our linked list//
    else{
      struct node* ptr = head;
      while(ptr->next){
        ptr = ptr->next;
      }
      ptr->next = temp;
    }
    printf("For more nodes press 'y' or 'Y': ");
    scanf(" %c",&ch);
  }while(ch == 'y' || ch == 'Y');
  return head;
}
void display(struct node* head){
  struct node* ptr = head;
  printf("Heres your linked list sir: ");
  while(ptr != NULL){
    printf("%d ",ptr->val);
    ptr = ptr->next;
  }
  return;
}
//finding the presence of an element in the linked list
void find(struct node* head,int target,bool* flag){
  struct node* ptr = head;
  while(ptr){
    if(ptr->val == target){
     *flag = true;
     return;
    }
   ptr = ptr->next;
  }
  return;
}
int main(){
  struct node* first_ll = create();
  display(first_ll);
  int target;
  bool flag = false;
  printf("\nEnter the target element: ");
  scanf("%d",&target);
  find(first_ll,target,&flag);
  if(flag == false){
    printf("The element is not in the linked list!");
  }
  else{
    printf("The element is present in the linked list");
  }
  return 0;
}