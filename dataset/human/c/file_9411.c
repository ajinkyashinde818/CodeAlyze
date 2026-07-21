#include<stdio.h>
int main()
{
int a,b,c,j,e;
  scanf("%d %d %d",&a,&b,&c);
int d[a];
  
  for(j=0;j<a;++j)
  {
  scanf("%d",&d[j]);
    e=1;
  while(e<=b){e=e+d[j];
             c++;
             }
  }
  
  printf("%d",c);
  
return 0;
}
