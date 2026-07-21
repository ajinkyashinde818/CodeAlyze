#include<stdio.h>
#define N 2000000
int main(void){
  int i,max=-1000000000;
  int min;
  int n,R[N];
   
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }
 
  min = R[0];
  for(i=1;i<n;i++){
    if(R[i] - min > max) max = R[i] - min;
    if(R[i] < min) min = R[i];
  }
 
  printf("%d\n",max);
}
