#include<stdio.h>
#define A 200000 

int main(){
 int n, i, maxv, minv;
 int R[A];
 scanf("%d" , &n);
 
 for(i=0; i<n; i++){
  scanf("%d" , &R[i]);
  }
  
  for(i=0; i<n-1; i++){
   if(i==0 || minv>R[i]){
     minv=R[i];
     }
  if(i==0 || maxv<R[i+1]-minv){
     maxv=R[i+1]-minv;
     }
 }
  
 printf("%d\n" , maxv);
 
 return 0;
 }
