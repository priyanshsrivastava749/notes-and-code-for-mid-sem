//the following code contain the solution to the problem where we are suppossed to insert a node after or before certain node
//the code is the solution to the problem to insert a newly created node to the very end of the linked list
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
struct node* insert_at_begin(struct node* head){
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  if(temp == NULL){
    printf("Failed to allocate memory!");
    exit(1);
  }
  else{
    int x;
    printf("\nEnter the number you want to insert at the very beginning of your given ll: ");
    scanf("%d",&x);
    temp->val = x;
  }
  temp -> next = head;
  head = temp;
  return head;
}
/// this portion is the heighlighted version of our complete code
void insert_at_end(struct node* head){
  struct node* ptr = head;
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  if(temp == NULL){
    printf("\nmemory allocation failed!");
    exit(1);
  }
  else{
    int x;
    printf("\nEnter the number you want to create and insert a node at the end of the linked-list: ");
    scanf("%d",&x);
    temp->val = x;
  }
  while(ptr->next){
    ptr = ptr->next;
  }
  ptr->next = temp;
  return;
}
void insert_after_node(struct node* head,int target){
  struct node* temp = (struct node*) malloc(sizeof(struct node*));
  if(temp == NULL){
    printf("Memory allocation failed!");
    exit(1);
  }
  else{
    int x;
    printf("\nEnter the value of the node you want to insert after the node with value %d : ",target);
    scanf("%d",&x);
    temp->val = x;
  }
  struct node* ptr = head;
  while(ptr->next->val == target){
    ptr = ptr->next;
  }
  temp = ptr->next;
  ptr->next = temp;
  return;
}
void insert_before_node(struct node* head,int target){
 struct node* ptr = head;
 struct node* temp = (struct node*) malloc (sizeof(struct node));
 if(temp == NULL){
  printf("\nMemory Allocation Failed!");
  exit(1);
 }
 else{
  int x;
  printf("\nEnter the number you want to create and insert a node before node %d of the linked-list: ",target);
  scanf("%d",&x);
  temp->val = x;
 }
 while(!(ptr->next->val == target)){
  ptr = ptr->next;
 }
 temp->next = ptr->next;
 ptr->next = temp;
 return;
}
int main(){
  struct node* first_ll = create();
  display(first_ll);
  int target;
  printf("\nEnter the target before which node to be inserted: ");
  scanf("%d",&target);
  insert_before_node(first_ll,target);
  display(first_ll);
  return 0;
}