#include<iostream>
using namespace std;
void hanoi(int n,char s,char h,char e){
  if(n==0)return;
  hanoi(n-1,s,e,h);
  printf("%c->%c\n",s,e);
  hanoi(n-1,h,s,e);
}
int main(){
  hanoi(3,'A','B','C');
  return 0;
}