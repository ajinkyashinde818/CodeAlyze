#include<stdio.h>

int main(void)
{
   int N,D,i,j,X,s=0,A[100];
   scanf("%d%d%d",&N,&D,&X);
   for(i=0;i<N;i++){
      scanf("%d",&A[i]);
      
      }
   for(i=0;i<N;i++){
      for(j=1;j<=D;j+=A[i]){
     	s++;
   }}
   printf("%d\n",s+X);
   return 0;
}
