#include<stdio.h>
 
int main(void)
{
  int n,i,ans=0;
  scanf("%d",&n);
  int a[n],b[n],c[n-1];
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n;i++)
    scanf("%d",&b[i]);
  for(i=0;i<n-1;i++)
    scanf("%d",&c[i]);
  for(i=0;i<n;i++){
    ans += b[a[i]-1];
    if((a[i]==a[i-1]+1)&&(i>0))
      ans += c[a[i-1]-1];
  }
  printf("%d\n",ans);
  return 0;
}
