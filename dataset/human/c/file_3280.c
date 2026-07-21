#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(){

  int N,K;

  scanf("%d %d",&K,&N);

  
  int A[N];
  int i;
  for(i=0;i<N;i++){
   scanf("%d",&A[i]);
   }
  
   int len[N];
  for(i=0;i<N-1;i++){
     len[i] = -A[i] + A[i+1];
  }
   len[N-1] = K - A[N-1] + A[0];
   qsort(len,N,sizeof(int),compare_int);
  printf("%d",K-len[N-1]);







 return(0);
 }
