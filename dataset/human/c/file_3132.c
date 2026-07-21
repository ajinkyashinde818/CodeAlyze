#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(void){
  int K,N;
  scanf("%d %d\n",&K,&N);
  if((K>=2 && K<=1000000) && (N>=2 && N<=200000))
  {
    int A[N];
    int i;
    scanf("%d ",&A[0]);
    if(A[0]<0 || A[0]>=K)
      return 0;
    for(i=1;i<N;i++)
    {
      scanf("%d ",&A[i]);
      if((A[i]<0 || A[i]>=K) || A[i]<=A[i-1])
        return 0;
    }
    int B[N],max=0;
    for(i=0;i<N-1;i++)
    {
      B[i]=A[i+1]-A[i];
      if(B[i]>max)
        max=B[i];
    }
    B[N-1]=K-A[N-1]+A[0];
    if(B[N-1]>max)
      max=B[N-1];
    int r=K-max;
    printf("%d",r);
  }
  return 0;
}
