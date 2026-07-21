#include <stdio.h>

int main()
{
  int n,k;
  int s=0;
  scanf("%d %d",&n,&k);

  int h[n];
  for(int i=0;i<n;i++){
    scanf("%d",&h[i]);
  }

  for(int j=0;j<n;j++){
    if(h[j]>=k)s=s+1;
  }
  printf("%d",s);

  return 0;
  
}
