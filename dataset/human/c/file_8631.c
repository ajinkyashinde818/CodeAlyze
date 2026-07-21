#include<stdio.h>
int main(){
  int a[100001],n,t=1,i;
  scanf("%d",&n);
  for(i=1;i<=n;i++)scanf("%d",&a[i]);
  for(i=1;i<=n;i++){t=a[t];if(t==2){printf("%d",i);return 0;}}
  printf("-1");
}
