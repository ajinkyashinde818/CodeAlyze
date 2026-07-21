#include<stdio.h>
int main(){
  int n,d,x,ans = 0;
  scanf("%d %d %d",&n,&d,&x);
  int a[n];
  d--;
  for(int i = 0;i < n;i++){
    scanf("%d",&a[i]);
    ans += d / a[i];
  }
  printf("%d\n",ans + n + x);
  return 0;
}
