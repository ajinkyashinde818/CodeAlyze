#include <stdio.h>

int main()
{
  int K,N;
  scanf("%d %d",&K,&N);
  int min=K;
  int MinPla=0;
  int a[1000000],tmp,ans;
  
  for(int i=0;i<N;i++)
  {
    scanf("%d",&a[i]);
    if (i!=0)
    {
      tmp=K-a[i]+a[i-1];
      if(min > tmp)
      {
        min=tmp;
        MinPla=i;
      }
    }
  }
  tmp=a[N-1]-a[0];
  if(min > tmp)
    ans=tmp;
  else
    ans=min;
  printf("%d",ans);
}
