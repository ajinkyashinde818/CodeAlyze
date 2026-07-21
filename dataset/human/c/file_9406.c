#include<stdio.h>

int main(void)
{

 int n,d,x,a[100],i,j,c=0;

 scanf("%d%d%d",&n,&d,&x);

 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);

  for(j=1;j<=d;j=j+a[i])
    c++;
 }

  printf("%d\n",c+x);
  return 0;
}
