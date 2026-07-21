#include <stdio.h>
#include <math.h>

#define N 999999

int main()
{
  int i,j,n;
  char prime[N];

  for (i=0;i<N;i++){
    prime[i]=1;
  }
  prime[0]=0;
  for (i=1;i<(int)sqrt(N);i++){
    if (prime[i]==1){
      for (j=i+1;(i+1)*j<=N;j++){
        prime[(i+1)*j-1]=0;
      }
    }
  }
  while (scanf("%d",&n)){
    if (n==0)
      break;
    int cnt=0,sum=0;
    for (i=0;i<N;i++){
      if (prime[i]==1){
        sum+=i+1;
        cnt++;
      }
      if (cnt>=n)
        break;
    }
    printf("%d\n",sum);
  }

  return 0;
}
