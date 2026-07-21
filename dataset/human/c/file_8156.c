#include <stdio.h>
#include <stdlib.h>

int main()
{int q,p,a,b,c,d;
 while(~scanf("%d%d%d%d",&a,&b,&c,&d))
 {p=a*b;
  q=c*d;
  if(q>=p)
  printf("%d\n",q);
  if(p>q)
  printf("%d\n",p);
 }
    return 0;
}
