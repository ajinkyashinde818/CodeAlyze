#include<stdio.h>
int main(void)
{
  	int i,K,N,M;
  	if((scanf("%d %d",&K,&N)) == 1);
  ;
  int A[N];
  	for(i=0;i < N ; i++){
  	  if((scanf("%d",&A[i])) == 1);
      ;
    }
  	M = K - A[N-1] + A[0];
  	for(i=0;i < N-1;i++){
      if((A[i+1] - A[i]) > M)
        M = A[i+1] - A[i];
    }
  	printf("%d",K - M);
}
