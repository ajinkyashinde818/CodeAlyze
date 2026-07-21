#include<stdio.h>
int main(void)
{
  int i,ans,b,n;
  int a[20];
  int c[20];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    scanf("%d",&b);
    ans+=b;
  }
  for(i=0;i<n-1;i++){
    scanf("%d",&c[i]);
  }
  for(i=0;i<n-1;i++){
    if (a[i+1]-a[i]==1){
      ans+=c[a[i]-1];
    }
  }
  printf("%d",ans);
  return 0;
}
