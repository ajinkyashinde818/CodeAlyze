#include<stdio.h>
int main(void)
{
  int n,i,d,x,ans=0,t=1,a[101];
  scanf("%d%d%d",&n,&d,&x);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    while(t<d+1){
      ans++;
      t+=a[i];
    }
    t=1;
  }
  printf("%d",x+ans);
  return 0;
}
