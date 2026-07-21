#include<stdio.h>
#include<stdlib.h>
int main(void){
 int N,K;
 scanf("%d",&N);
 scanf("%d",&K);
 int i;
 int a[N];
 int count=0;
 for(i=0;i<N;i++){
   scanf("%d",&a[i]);
  if(a[i]>=K){
   count++;
  }
  else{
  }
 }printf("%d",count);

}
