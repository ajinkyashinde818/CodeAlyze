#include<stdio.h>
int main(){
 int A[10000];
 int i,j,k;

  for(i=0;i<10000;i++){

   scanf("%d\n",&A[i]);

   if(A[i]==0)
     break;
  }
    k=i-1;

    for(j=0;j<=k;j++){
     printf("Case %d: %d\n",j+1,A[j]);
   }







 

  return 0;
}
