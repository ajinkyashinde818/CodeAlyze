#include<stdio.h>
#include<stdlib.h>
int main(void){
  int n,i,min,max,A;
  int *R;
  while(1){
  scanf("%d",&n);
  if(n>=2 && n<=200000)break;
  }
  R = (int*)malloc(sizeof(int)*n);
  for(i=0 ; i<n ; i++){
    while(1){
      scanf("%d",&R[i]);
      if(R[i]>=1 && R[i]<=1000000000)break;
    }
  }
  min=R[0];
  max=R[1]-min;
  for(i=1 ; i<n ; i++){
    if(max<R[i]-min)max=R[i]-min;
    if(min>R[i])min=R[i];
  }
  printf("%d\n",max);
  free(R);
  return 0;
}
