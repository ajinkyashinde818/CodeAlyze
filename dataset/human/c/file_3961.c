#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX(p,q) ((p>q)?(p):(q))
#define MIN(p,q) ((p<q)?(p):(q))

#define REP(i,n) for(i=n;i>0;i--)

int gcd(int a,int b);

int main(void)
{
  int a,b,k;
  scanf("%d%d%d",&a,&b,&k);
  int g;
  g = gcd(a,b);
  int i,flag=0;
  REP(i,g)
  {
    if(g%i==0) flag++;
    if(flag==k)
    {
      printf("%d\n",i);
      break;
    }
  }
  return 0;
}

int gcd(int a,int b)
{
  int max,min,tmp;
  max = MAX(a,b);
  min = MIN(a,b);
  if(max%min==0) return min;
  else
  {
    tmp = min;
    min = max%min;
    max = tmp;
    return gcd(max,min);
  }
}
