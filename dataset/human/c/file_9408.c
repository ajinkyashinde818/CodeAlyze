#include<stdio.h>

int main(void)
{
  int n,d,x;
  scanf("%d%d%d",&n,&d,&x);

  int i,j,a[110],ans = x;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    for(j=0;j<d;j+=a[i])
      ans++;
  }

  printf("%d\n",ans);
  return 0;
}
