#include<stdio.h>

int count(int n){
  if(n!=0){
    int sc;
    scanf("%d",&sc);
    return sc+count(n-1);
  }
  else{
    return 0;
  }
}

void doit(){
  int score=count(10);
  printf("%d\n",score);
}

int main(){
  doit();
  return 0;
}
