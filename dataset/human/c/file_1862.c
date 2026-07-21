#include <stdio.h>

int main()
{
  int n;
  scanf("%d",&n);
  int a[n],b[n],c[n-1];
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  for(int j=0;j<n;j++)scanf("%d",&b[j]);
  for(int k=0;k<n-1;k++)scanf("%d",&c[k]);

  int s=0;
  for(int l=0;l<n;l++){
    s=s+b[l];
    if(a[l+1]==a[l]+1) s=s+c[a[l]-1];
  }
  printf("%d\n",s);
  return 0;
}
