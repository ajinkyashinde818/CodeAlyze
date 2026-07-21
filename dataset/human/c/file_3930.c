#include <stdio.h>
int main(){
  int A,B,K;
  scanf("%d %d %d",&A,&B,&K);
  int count=0;
  int i;
  for(i=100;i>1;i--){
    if(A%i==0 && B%i==0)
      count++;
    if(count==K)
      break;
  }
  
  printf("%d\n",i);
  
  return 0;
}
