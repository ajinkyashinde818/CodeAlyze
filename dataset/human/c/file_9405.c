#include<stdio.h>
int main()
{
  int n,d,x,nb=0,eaten=0;
  scanf("%d %d %d",&n,&d,&x);
  int a[n];
  while(nb<n)
  {
    scanf("%d",&a[nb]);
    nb++;
  }
  nb=0;
  while(nb<n)
  {
    eaten+=((((d-1)-((d-1)%a[nb]))/a[nb])+1);
    nb++;
  }
  printf("%d",x+eaten);
  return 0;
}
