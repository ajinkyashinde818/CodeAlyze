#include<stdio.h>
 
int main(){
  int max,min,i,j,n,R[200000];
   
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
