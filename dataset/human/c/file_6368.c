#include <stdio.h>
#include <limits.h>
#define Max INT_MAX
#define Min INT_MIN

int main(void)
{
  int n;
  int i;
  int R[200000];
  int max=Min;
  int min=Max;
  int dif;

  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&R[i]);
    dif = R[i] - min;
    if(dif>max)max=dif;
    if(R[i]<min)
    {
      min = R[i];
    }

  }
  printf("%d\n",max);

  return 0;
}
