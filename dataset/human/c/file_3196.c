#include <stdio.h>

int main(void)
{

  int K,N,i,ans;
  int dis_max = 0;
  scanf("%d %d",&K,&N);
  int a[N];
  int d[N];
  for(i=0;i<N;i++)
  {
    scanf("%d",&a[i]);
  }
  for(i=0;i<N-1;i++)
    d[i] = a[i+1] - a[i];
  
  d[N-1] = a[0] - a[N-1] + K;
  
  for(i=0;i<N;i++)
    if(dis_max < d[i])
      dis_max = d[i];

  ans = K - dis_max;
  

  printf("%d\n",ans);
  return 0;
}
