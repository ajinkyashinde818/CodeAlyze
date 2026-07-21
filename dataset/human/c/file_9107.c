#include<stdio.h>
int main()
{
int a,b,d;
  d=0;
  scanf("%d %d",&a,&b);
int c[a];
for(int j=0;j<a;++j)
  {scanf("%d ",&c[j]);
   if(c[j]>=b) d=d+1;
  }
printf("%d",d);
return 0;
}
