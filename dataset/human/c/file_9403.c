#include<stdio.h>
int main()
{
  int i,n,d,x,a;
  scanf("%d%d%d",&n,&d,&x);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    x+=d/a+1;
    if(d%a==0)x--;
  }
  printf("%d\n",x);
  return 0;
}
