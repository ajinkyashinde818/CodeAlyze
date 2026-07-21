#include <stdio.h>
#define N 10000
int main()
{
  int mat[N];
  int i,x,count;

  count=0;

  for(i=0;i<N;i++)
  {
    scanf("%d",&x);
    if(x==0) {
      break;
    }
    mat[i]=x;
    count++;
  }

  for(i=0;i<count;i++)
  {
    printf("Case %d: %d\n",i+1,mat[i]);
  }

  return 0;
}
