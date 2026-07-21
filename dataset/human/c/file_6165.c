#include<stdio.h>

#define N 200000

main(){
  int i,j,n,R[N],x,max,min;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }
  max=R[1]-R[0];
  min=R[0];
  for(j=1;j<=n-1;j++){  
    x=R[j]-min;
    if(max<x)
      max=x;
    if(min>R[j])
      min=R[j];
  }
  
  printf("%d\n",max);
  return 0;
  
}
