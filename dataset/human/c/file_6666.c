#include<stdio.h>
#define N 200000

int main(){
  int max,min,j,n,R[N];
  
  scanf("%d",&n);
  for(j=0;j<n;j++){
    scanf("%d",&R[j]);
  }
  min=R[0];
  max=R[1]-R[0];
  
  for(j=1;j<n;j++){
    if(max<R[j]-min)
      max=R[j]-min;
    if(min>R[j])
      min=R[j];
  }
  printf("%d\n",max);
  return 0;
  
}
