#include<stdio.h>
#include<stdlib.h>
 
int main(){
  int i,n,R[200000],min,max;
 
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
    if(R[i]<1 || R[i]>1000000000){
      exit(8);
    }
  }
 
  max=R[1]-R[0];
  min=R[0];
 
  for(i=1;i<n;i++){
    if(max<R[i]-min){
      max=R[i]-min;
    }
    if(min>R[i]){
      min=R[i];
    }
  } 
 
  printf("%d\n",max);
 
  return 0;
}
